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
#include <math.h>

void	movement_ver(char key, t_move *move, t_render *render)
{
	if (key == 'W')
	{
		if (verif_move(move->data->map
				[(int)(render->spawn_x + render->dirx * (MOVE_SPEED + 0.01))]
			[(int)render->spawn_y]))
			render->spawn_x += render->dirx * MOVE_SPEED;
		if (verif_move(move->data->map[(int)(render->spawn_x)]
			[(int)(render->spawn_y + render->diry * (MOVE_SPEED + 0.01))]))
			render->spawn_y += render->diry * MOVE_SPEED;
	}
	if (key == 'S')
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
	minimap(move->data, render, render->spawn_x, render->spawn_y);
}

void	movement_hor(char key, t_move *move, t_render *render)
{
	if (key == 'A')
	{
		if (verif_move(move->data->map
				[(int)(render->spawn_x - render->planex * (MOVE_SPEED + 0.01))]
			[(int)render->spawn_y]))
			render->spawn_x -= render->planex * MOVE_SPEED;
		if (verif_move(move->data->map[(int)(render->spawn_x)]
			[(int)(render->spawn_y - render->planey * (MOVE_SPEED + 0.01))]))
			render->spawn_y -= render->planey * MOVE_SPEED;
	}
	if (key == 'D')
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
	minimap(move->data, render, render->spawn_x, render->spawn_y);
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
	minimap(move->data, render, render->spawn_x, render->spawn_y);
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
	minimap(move->data, render, render->spawn_x, render->spawn_y);
}

void	loop_hook(void *param)
{
	t_move		*move;

	move = param;
	if (mlx_is_key_down(move->render->mlx, MLX_KEY_W))
		movement_ver('W', move, move->render);
	if (mlx_is_key_down(move->render->mlx, MLX_KEY_S))
		movement_ver('S', move, move->render);
	if (mlx_is_key_down(move->render->mlx, MLX_KEY_A))
		movement_hor('A', move, move->render);
	if (mlx_is_key_down(move->render->mlx, MLX_KEY_D))
		movement_hor('D', move, move->render);
	if (mlx_is_key_down(move->render->mlx, MLX_KEY_LEFT))
		rotation_left(move);
	if (mlx_is_key_down(move->render->mlx, MLX_KEY_RIGHT))
		rotation_right(move);
}
