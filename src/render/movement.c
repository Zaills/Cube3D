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

int	verif_move(char nxt)
{
	if (nxt == '0' || nxt == 'N' || nxt == 'S' || nxt == 'E' || nxt == 'W')
		return (1);
	return (0);
}

void	movement(mlx_key_data_t key, t_move	*move)
{
	t_render	*render;

	render = move->render;
	if (key.key == MLX_KEY_W)
	{
		if (verif_move(move->data->map[(int)(render->spawn_x + render->dirX * MOVE_SPEED)][(int)render->spawn_y]))
			render->spawn_x += render->dirX * MOVE_SPEED;
		if (verif_move(move->data->map[(int)(render->spawn_x)][(int)(render->spawn_y + render->dirY * MOVE_SPEED)]))
			render->spawn_y += render->dirY * MOVE_SPEED;
	}
	if (key.key == MLX_KEY_S)
	{
		if (verif_move(move->data->map[(int)(render->spawn_x - render->dirX * MOVE_SPEED)][(int)render->spawn_y]))
			render->spawn_x -= render->dirX * MOVE_SPEED;
		if (verif_move(move->data->map[(int)(render->spawn_x)][(int)(render->spawn_y - render->dirY * MOVE_SPEED)]))
			render->spawn_y -= render->dirY * MOVE_SPEED;
	}
	if (key.key == MLX_KEY_A)
	{
		if (verif_move(move->data->map[(int)(render->spawn_x - render->planeX * MOVE_SPEED)][(int)render->spawn_y]))
			render->spawn_x -= render->planeX * MOVE_SPEED;
		if (verif_move(move->data->map[(int)(render->spawn_x)][(int)(render->spawn_y - render->planeY * MOVE_SPEED)]))
			render->spawn_y -= render->planeY * MOVE_SPEED;
	}
	if (key.key == MLX_KEY_D)
	{
		if (verif_move(move->data->map[(int)(render->spawn_x + render->planeX * MOVE_SPEED)][(int)render->spawn_y]))
			render->spawn_x += render->planeX * MOVE_SPEED;
		if (verif_move(move->data->map[(int)(render->spawn_x)][(int)(render->spawn_y + render->planeY * MOVE_SPEED)]))
			render->spawn_y += render->planeY * MOVE_SPEED;
	}
	render_sky_floor(render, move->data);
	raycast(render, move->data->map);
}

void	rotation(mlx_key_data_t key, t_move	*move)
{
	t_render	*render;
	double		old_dirx;
	double		old_planex;

	render = move->render;
	old_dirx = render->dirX;
	old_planex = render->planeX;
	if (key.key == MLX_KEY_RIGHT)
	{
		render->dirX = render->dirX * cos(-MOVE_SPEED) - render->dirY * sin(-MOVE_SPEED);
		render->dirY = old_dirx * sin(-MOVE_SPEED) + render->dirY * cos(-MOVE_SPEED);
		render->planeX = render->planeX * cos(-MOVE_SPEED) - render->planeY * sin(-MOVE_SPEED);
		render->planeY = old_planex * sin(-MOVE_SPEED) + render->planeY * cos(-MOVE_SPEED);
	}
	if (key.key == MLX_KEY_LEFT)
	{
		render->dirX = render->dirX * cos(MOVE_SPEED) - render->dirY * sin(MOVE_SPEED);
		render->dirY = old_dirx * sin(MOVE_SPEED) + render->dirY * cos(MOVE_SPEED);
		render->planeX = render->planeX * cos(MOVE_SPEED) - render->planeY * sin(MOVE_SPEED);
		render->planeY = old_planex * sin(MOVE_SPEED) + render->planeY * cos(MOVE_SPEED);
	}
	render_sky_floor(render, move->data);
	raycast(render, move->data->map);
}

void	key_hook(mlx_key_data_t key, void	*param)
{
	t_move		*move;

	move = param;
	if (key.key == MLX_KEY_W || key.key == MLX_KEY_S
		|| key.key == MLX_KEY_A || key.key == MLX_KEY_D)
			movement(key, move);
	if (key.key == MLX_KEY_LEFT || key.key == MLX_KEY_RIGHT)
		rotation(key, move);
	if (key.key == MLX_KEY_ESCAPE && key.action == MLX_PRESS)
		mlx_close_window(move->render->mlx);
}

void	init_move(t_move *move, t_render *render, t_parse *data)
{
	move->render = render;
	move->data = data;
}
