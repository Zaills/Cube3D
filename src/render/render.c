/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gouz <gouz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 17:21:26 by gouz              #+#    #+#             */
/*   Updated: 2023/09/13 15:19:54 by gouz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "render.h"
#include "stdio.h"

void	render(t_parse *data)
{
	t_render render;
	t_move move;

	if (init_render(&render, data) == -1)
		return ;
	init_move(&move, &render, data);
	render_sky_floor(&render, data);
	minimap(data, &render);
	render_player(&render, render.mlx);
	raycast(&render, data->map);
	mlx_key_hook(render.mlx, &key_hook, &move);
	mlx_loop(render.mlx);
	mlx_terminate(render.mlx);
}
