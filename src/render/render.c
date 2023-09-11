/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gouz <gouz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 17:21:26 by gouz              #+#    #+#             */
/*   Updated: 2023/09/11 18:17:05 by gouz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "render.h"
#include "stdio.h"

void	draw_ver_line(int start, int end, t_render *render, int x)
{
	if (render->side == 1)
	{
		while (start < end)
		{
			mlx_put_pixel(render->view, x, start, (0xFF0000FF / 2));
			start++;
		}
	}
	else
	{
		while (start < end)
		{
			mlx_put_pixel(render->view, x, start, 0xFF0000FF);
			start++;
		}
	}
}

void	render(t_parse *data)
{
	t_render render;
	t_move move;

	init_render(&render, data);
	init_move(&move, &render, data);
	render_sky_floor(&render, data);
	minimap(data, &render);
	render_player(&render, render.mlx);
	raycast(&render, data->map);
	mlx_key_hook(render.mlx, &key_hook, &move);
	mlx_loop(render.mlx);
	mlx_terminate(render.mlx);
}
