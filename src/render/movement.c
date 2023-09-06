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

void	movement(mlx_key_data_t key, t_movement* mv)
{
	t_render* render;

	render = mv->render;
	if (key.key == MLX_KEY_W)
	{
		render->spawn_x += render->dirX * 0.1;
		render->spawn_y += render->dirY * 0.1;
	}
	if (key.key == MLX_KEY_S)
	{
		render->spawn_x -= render->dirX * 0.1;
		render->spawn_y -= render->dirY * 0.1;
	}
}

void	rotation(mlx_key_data_t key, t_movement* mv)
{
	t_render* render;
	double oldDirX;
	double oldPlaneX;

	render = mv->render;
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
	t_movement* mv;
	t_render* render;

	mv = param;
	render = mv->render;
	if (key.action == MLX_PRESS)
	{
		printf("key pressed\n");
		if (key.key == MLX_KEY_W || key.key == MLX_KEY_S
			|| key.key == MLX_KEY_A || key.key == MLX_KEY_D)
			movement(key, mv);
		if (key.key == MLX_KEY_LEFT || key.key == MLX_KEY_RIGHT)
			rotation(key, mv);
	}
	if (key.key == MLX_KEY_Q && key.action == MLX_PRESS)
		{
			printf("Info\n");
			printf("spaw_x: %f\nspawn_y: %f\n", render->spawn_x, render->spawn_y);
			printf("dir x: %f\ndir y: %f\n", render->dirX, render->dirY);
			printf("plane x: %f\nplane y: %f\n", render->planeX, render->planeY);
		}
	if(key.key == MLX_KEY_ESCAPE && key.action == MLX_PRESS)
		mlx_close_window(mv->mlx);
}

void	init_movement(t_movement* movement, t_render* render, mlx_t* mlx, t_parse* data)
{
	movement->mlx = mlx;
	movement->render = render;
	movement->map = data->map;
}
