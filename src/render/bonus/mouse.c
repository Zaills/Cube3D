/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 11:21:12 by marvin            #+#    #+#             */
/*   Updated: 2023/09/19 11:21:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include <stdio.h>

void	l_hook(void *param)
{
	t_move	*move;
	int32_t	x;
	int32_t	y;

	move = param;
	if (move->ml == 0)
		return ;
	mlx_get_mouse_pos(move->render->mlx, &x, &y);
	if (y != HEIGHT / 2)
		mlx_set_mouse_pos(move->render->mlx, x, HEIGHT / 2);
	if (x > WIDTH / 2)
	{
		rotation_right(move);
		mlx_set_mouse_pos(move->render->mlx, WIDTH / 2, HEIGHT / 2);
	}
	if (x < WIDTH / 2)
	{
		rotation_left(move);
		mlx_set_mouse_pos(move->render->mlx, WIDTH / 2, HEIGHT / 2);
	}
}

void	lock_mouse(t_move *move)
{
	move->ml = !move->ml;
	if (move->ml)
		mlx_set_cursor_mode(move->render->mlx, 0x00034002);
	else
		mlx_set_cursor_mode(move->render->mlx, 0x00034001);
}