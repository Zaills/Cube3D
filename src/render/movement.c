/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:24:28 by marvin            #+#    #+#             */
/*   Updated: 2023/09/06 17:24:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "stdio.h"
#include <math.h>

void	movement(mlx_key_data_t key, t_move* move)
{
	t_render* render;

	render = move->render;
	if (key.key == MLX_KEY_W)
	{
		render->spawn_x += render->dirX * 0.1;
		render->spawn_y += render->dirY * 0.1;
		printf("W");
	}
	if (key.key == MLX_KEY_S)
	{
		render->spawn_x -= render->dirX * 0.1;
		render->spawn_y -= render->dirY * 0.1;
		printf("S");
	}
}

void	rotation(mlx_key_data_t key, t_move* move)
{
	t_render* render;
	double oldDirX;
	double oldPlaneX;

	render = move->render;
	oldDirX = render->dirX;
	oldPlaneX = render->planeX;
	if (key.key == MLX_KEY_RIGHT)
	{
		render->dirX = render->dirX * cos(-0.1) - render->dirY * sin(-0.1);
		render->dirY = oldDirX * sin(-0.1) + render->dirY * cos(-0.1);
		render->planeX = render->planeX * cos(-0.1) - render->planeY * sin(-0.1);
		render->planeY = oldPlaneX * sin(-0.1) + render->planeY * cos(-0.1);
	}
	if (key.key == MLX_KEY_LEFT)
	{
		render->dirX = render->dirX * cos(0.1) - render->dirY * sin(0.1);
		render->dirY = oldDirX * sin(0.1) + render->dirY * cos(0.1);
		render->planeX = render->planeX * cos(0.1) - render->planeY * sin(0.1);
		render->planeY = oldPlaneX * sin(0.1) + render->planeY * cos(0.1);
	}
}

void	key_hook(mlx_key_data_t key, void* param)
{
	t_move* move;
	t_render* render;

	move = param;
	render = move->render;
	if (key.action == MLX_PRESS)
	{
		printf("key pressed\n");
		if (key.key == MLX_KEY_W || key.key == MLX_KEY_S
			|| key.key == MLX_KEY_A || key.key == MLX_KEY_D)
				movement(key, move);
		if (key.key == MLX_KEY_LEFT || key.key == MLX_KEY_RIGHT)
			rotation(key, move);
		render_sky_floor(render, move->data);
		raycast(render, move->data->map);
	}
	if (key.key == MLX_KEY_Q && key.action == MLX_PRESS)
		{
			printf("Info\n");
			printf("spaw_x: %f\nspawn_y: %f\n", render->spawn_x, render->spawn_y);
			printf("dir x: %f\ndir y: %f\n", render->dirX, render->dirY);
			printf("plane x: %f\nplane y: %f\n", render->planeX, render->planeY);
		}
	if(key.key == MLX_KEY_ESCAPE && key.action == MLX_PRESS)
		mlx_close_window(move->render->mlx);
}

void	init_move(t_move *move, t_render *render, t_parse *data)
{
	move->render = render;
	move->data = data;
}
