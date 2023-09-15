/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gouz <gouz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:26:40 by gouz              #+#    #+#             */
/*   Updated: 2023/09/15 14:11:26 by gouz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "math.h"

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

static void	dda(t_render *render, char **map)
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
		dda(render, map);
		if (render->side == 0)
			wall_dist = (render->sideDistX - render->deltaDistX);
		else
			wall_dist = (render->sideDistY - render->deltaDistY);
		draw_wall(wall_dist, i, render);
	}
}
