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

	move = param;
	int32_t	x;
	int32_t	y;

	//x -> W, y -> H
	mlx_get_mouse_pos(move->render->mlx, &x, &y);
	//mlx_hide_mouse;
	printf("x: %d, y: %d\n", x, y);
	if (x != WIDTH / 2 || y != WIDTH / 2)
	{
		mlx_set_mouse_pos(move->render->mlx, WIDTH / 2, HEIGHT / 2);
	}
}
