/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gouz <gouz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:09:24 by gouz              #+#    #+#             */
/*   Updated: 2023/09/15 14:17:15 by gouz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include <math.h>

static void	draw_wall2(t_render *render, int start, int end, int i)
{
	int		color;
	int		j;
	double	step;

	j = start;
	if (render->side == 0 && render->rayDirX > 0)
		render->texX = 64 - render->texX - 1;
	if (render->side == 1 && render->rayDirY < 0)
		render->texX = 64 - render->texX - 1;
	step = 1.0 * 64 / render->line_height;
	render->texPos = (start - HEIGHT / 2 + render->line_height / 2) * step;
	while (j < end)
	{
		render->texY = (int)render->texPos & (64 - 1);
		render->texPos += step;
		color = encode_color(render->texX, render->texY, render);
		mlx_put_pixel(render->view, i, j, color);
		j++;
	}
}

void	draw_wall(double wall_dist, int i, t_render *render)
{
	int	draw_start;
	int	draw_end;

	render->line_height = (int)(HEIGHT / wall_dist);
	draw_start = -render->line_height / 2 + HEIGHT / 2;
	draw_end = render->line_height / 2 + HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	if (draw_end >= HEIGHT)
		draw_end = HEIGHT - 1;
	if (render->side == 0)
		render->wallX = render->spawn_y + wall_dist * render->rayDirY;
	else
		render->wallX = render->spawn_x + wall_dist * render->rayDirX;
	render->wallX -= floor((render->wallX));
	render->texX = (int)(render->wallX * (double)64);
	draw_wall2(render, draw_start, draw_end, i);
}
