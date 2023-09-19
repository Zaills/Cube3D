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

	mlx_get_mouse_pos(move->render->mlx, &x, &y);
	printf("x: %d, y: %d\n", x, y);
}
