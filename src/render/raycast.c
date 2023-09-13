/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gouz <gouz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:26:40 by gouz              #+#    #+#             */
/*   Updated: 2023/09/13 18:22:14 by gouz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "math.h"
#include "stdio.h"

int	get_texture(t_render *render)
{
	if (render->side == 0 && render->rayDirX < 0) // NORTH
		return (0);
	if (render->side == 0 && render->rayDirX > 0) // SOUTH
		return (2);
	if (render->side == 1 && render->rayDirY < 0) //WEST
		return (3);
	return (1); //EAST
}

int	encode_color(int x, int y, t_render *render)
{
	int	r;
	int	g;
	int	b;
	int	pixelPos;
	int	text_index;

	text_index = get_texture(render);
	pixelPos = (4 * x) + (256 * y);
	r = render->text[text_index]->pixels[pixelPos];
	g = render->text[text_index]->pixels[pixelPos + 1];
	b = render->text[text_index]->pixels[pixelPos + 2];
	return (r << 24 | g << 16 | b << 8 | 255);
}

static void	draw_wall(double wall_dist, int i, t_render *render)
{
	int	line_height;
	int	draw_start;
	int	draw_end;

	line_height = (int)(HEIGHT / wall_dist);
	draw_start = -line_height / 2 + HEIGHT / 2;
	draw_end = line_height / 2 + HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	if (draw_end >= HEIGHT)
		draw_end = HEIGHT - 1;
	//
 	double wallX;
	if(render->side == 0)
		wallX = render->spawn_y + wall_dist * render->rayDirY;
	else
		wallX = render->spawn_x + wall_dist * render->rayDirX;
	wallX -= floor((wallX));
	int texX = (int)(wallX * (double)64);
	if(render->side == 0 && render->rayDirX > 0)
		texX = 64 - texX - 1;//here
	if(render->side == 1 && render->rayDirY < 0)
		texX = 64 - texX - 1;//here
	double step = 1.0 * 64 / line_height;
	double texPos = (draw_start - HEIGHT / 2 + line_height / 2) * step; //X
	for(int y = draw_start; y < draw_end; y++)
	{
		int texY = (int)texPos & (64 - 1);
		texPos += step;
		int color = encode_color(texX, texY, render);
		//if(render->side == 1)
		//	color = color / 2;
		// (color >> 1) & 8355711; maybe plus rapide
		mlx_put_pixel(render->view, i, y, color);
	}
}

static void	update_var(t_render *render, int i)
{
	double	camera_x;

	camera_x = 2 * i / (double)WIDTH - 1;
	render->rayDirX = render->dirX + render->planeX * camera_x;
	render->rayDirY = render->dirY + render->planeY * camera_x;
	render->mapX = (int)render->spawn_x;
	render->mapY = (int)render->spawn_y;
	if (render->rayDirX == 0)
		render->deltaDistX = 1e30;
	else
		render->deltaDistX = fabs(1 / render->rayDirX);
	if (render->rayDirY == 0)
		render->deltaDistY = 1e30;
	else
		render->deltaDistY = fabs(1 / render->rayDirY);
}

static void	digital_differential_analyzer(t_render *render, char **map)
{
	while (1)
	{
		if (render->sideDistX < render->sideDistY)
		{
			render->sideDistX += render->deltaDistX;
			render->mapX += render->stepX;
			render->side = 0;
		}
		else
		{
			render->sideDistY += render->deltaDistY;
			render->mapY += render->stepY;
			render->side = 1;
		}
		if (map[render->mapX][render->mapY] == '1')
			return ;
	}
}

static void	step_and_dist(t_render *r)
{
	if (r->rayDirX < 0)
	{
		r->stepX = -1;
		r->sideDistX = (r->spawn_x - r->mapX) * r->deltaDistX;
	}
	else
	{
		r->stepX = 1;
		r->sideDistX = (r->mapX + 1.0 - r->spawn_x) * r->deltaDistX;
	}
	if (r->rayDirY < 0)
	{
		r->stepY = -1;
		r->sideDistY = (r->spawn_y - r->mapY) * r->deltaDistY;
	}
	else
	{
		r->stepY = 1;
		r->sideDistY = (r->mapY + 1.0 - r->spawn_y) * r->deltaDistY;
	}
}

void	raycast(t_render *render, char **map)
{
	int		i;
	double	wall_dist;

	i = -1;
	while (++i < WIDTH)
	{
		update_var(render, i);
		step_and_dist(render);
		digital_differential_analyzer(render, map);
		if (render->side == 0)
			wall_dist = (render->sideDistX - render->deltaDistX);
		else
			wall_dist = (render->sideDistY - render->deltaDistY);
		draw_wall(wall_dist, i, render);
	}
}
