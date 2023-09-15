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

void	movement_ver(mlx_key_data_t key, t_move *move)
{
	t_render	*render;

	render = move->render;
	if (key.key == MLX_KEY_W)
	{
		if (verif_move(move->data->map
				[(int)(render->spawn_x + render->dirx * (MOVE_SPEED + 0.01))]
			[(int)render->spawn_y]))
			render->spawn_x += render->dirx * MOVE_SPEED;
		if (verif_move(move->data->map[(int)(render->spawn_x)]
			[(int)(render->spawn_y + render->diry * (MOVE_SPEED + 0.01))]))
			render->spawn_y += render->diry * MOVE_SPEED;
	}
	if (key.key == MLX_KEY_S)
	{
		if (verif_move(move->data->map
				[(int)(render->spawn_x - render->dirx * (MOVE_SPEED + 0.01))]
			[(int)render->spawn_y]))
			render->spawn_x -= render->dirx * MOVE_SPEED;
		if (verif_move(move->data->map[(int)(render->spawn_x)]
			[(int)(render->spawn_y - render->diry * (MOVE_SPEED + 0.01))]))
			render->spawn_y -= render->diry * MOVE_SPEED;
	}
	render_sky_floor(render, move->data);
	raycast(render, move->data->map);
}

void	movement_hor(mlx_key_data_t key, t_move *move)
{
	t_render	*render;

	render = move->render;
	if (key.key == MLX_KEY_A)
	{
		if (verif_move(move->data->map
				[(int)(render->spawn_x - render->planex * (MOVE_SPEED + 0.01))]
			[(int)render->spawn_y]))
			render->spawn_x -= render->planex * MOVE_SPEED;
		if (verif_move(move->data->map[(int)(render->spawn_x)]
			[(int)(render->spawn_y - render->planey * (MOVE_SPEED + 0.01))]))
			render->spawn_y -= render->planey * MOVE_SPEED;
	}
	if (key.key == MLX_KEY_D)
	{
		if (verif_move(move->data->map
				[(int)(render->spawn_x + render->planex * (MOVE_SPEED + 0.01))]
			[(int)render->spawn_y]))
			render->spawn_x += render->planex * MOVE_SPEED;
		if (verif_move(move->data->map[(int)(render->spawn_x)]
			[(int)(render->spawn_y + render->planey * (MOVE_SPEED + 0.01))]))
			render->spawn_y += render->planey * MOVE_SPEED;
	}
	render_sky_floor(render, move->data);
	raycast(render, move->data->map);
}

void	rotation_right(t_move *move)
{
	t_render	*render;
	double		old_dirx;
	double		old_planex;

	render = move->render;
	old_dirx = render->dirx;
	old_planex = render->planex;
	render->dirx = render->dirx * cos(-MOVE_SPEED)
		- render->diry * sin(-MOVE_SPEED);
	render->diry = old_dirx * sin(-MOVE_SPEED)
		+ render->diry * cos(-MOVE_SPEED);
	render->planex = render->planex * cos(-MOVE_SPEED)
		- render->planey * sin(-MOVE_SPEED);
	render->planey = old_planex * sin(-MOVE_SPEED)
		+ render->planey * cos(-MOVE_SPEED);
	render_sky_floor(render, move->data);
	raycast(render, move->data->map);
}

void	rotation_left(t_move *move)
{
	t_render	*render;
	double		old_dirx;
	double		old_planex;

	render = move->render;
	old_dirx = render->dirx;
	old_planex = render->planex;
	render->dirx = render->dirx * cos(MOVE_SPEED)
		- render->diry * sin(MOVE_SPEED);
	render->diry = old_dirx * sin(MOVE_SPEED)
		+ render->diry * cos(MOVE_SPEED);
	render->planex = render->planex * cos(MOVE_SPEED)
		- render->planey * sin(MOVE_SPEED);
	render->planey = old_planex * sin(MOVE_SPEED)
		+ render->planey * cos(MOVE_SPEED);
	render_sky_floor(render, move->data);
	raycast(render, move->data->map);
}

void	key_hook(mlx_key_data_t key, void *param)
{
	t_move		*move;

	move = param;
	if (key.key == MLX_KEY_W || key.key == MLX_KEY_S)
		movement_ver(key, move);
	if (key.key == MLX_KEY_A || key.key == MLX_KEY_D)
		movement_hor(key, move);
	if (key.key == MLX_KEY_LEFT)
		rotation_left(move);
	if (key.key == MLX_KEY_RIGHT)
		rotation_right(move);
	if (key.key == MLX_KEY_ESCAPE && key.action == MLX_PRESS)
		mlx_close_window(move->render->mlx);
}
