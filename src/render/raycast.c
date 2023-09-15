/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gouz <gouz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:26:40 by gouz              #+#    #+#             */
/*   Updated: 2023/09/15 16:11:29 by gouz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "math.h"

static void	update_var(t_render *render, int i)
{
	double	camera_x;

	camera_x = 2 * i / (double)WIDTH - 1;
	render->raydirx = render->dirx + render->planex * camera_x;
	render->raydiry = render->diry + render->planey * camera_x;
	render->mapx = (int)render->spawn_x;
	render->mapy = (int)render->spawn_y;
	if (render->raydirx == 0)
		render->deltadistx = 1e30;
	else
		render->deltadistx = fabs(1 / render->raydirx);
	if (render->raydiry == 0)
		render->deltadisty = 1e30;
	else
		render->deltadisty = fabs(1 / render->raydiry);
}

static void	dda(t_render *render, char **map)
{
	while (1)
	{
		if (render->side_distx < render->side_disty)
		{
			render->side_distx += render->deltadistx;
			render->mapx += render->stepx;
			render->side = 0;
		}
		else
		{
			render->side_disty += render->deltadisty;
			render->mapy += render->stepy;
			render->side = 1;
		}
		if (map[render->mapx][render->mapy] == '1')
			return ;
	}
}

static void	step_and_dist(t_render *r)
{
	if (r->raydirx < 0)
	{
		r->stepx = -1;
		r->side_distx = (r->spawn_x - r->mapx) * r->deltadistx;
	}
	else
	{
		r->stepx = 1;
		r->side_distx = (r->mapx + 1.0 - r->spawn_x) * r->deltadistx;
	}
	if (r->raydiry < 0)
	{
		r->stepy = -1;
		r->side_disty = (r->spawn_y - r->mapy) * r->deltadisty;
	}
	else
	{
		r->stepy = 1;
		r->side_disty = (r->mapy + 1.0 - r->spawn_y) * r->deltadisty;
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
			wall_dist = (render->side_distx - render->deltadistx);
		else
			wall_dist = (render->side_disty - render->deltadisty);
		draw_wall(wall_dist, i, render);
	}
}
