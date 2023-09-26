/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:28:27 by marvin            #+#    #+#             */
/*   Updated: 2023/09/15 15:28:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	init_move(t_move *move, t_render *render, t_parse *data)
{
	move->render = render;
	move->data = data;
	move->ml = 1;
}

int	verif_move(char nxt)
{
	if (nxt == '0' || nxt == 'N' || nxt == 'S' || nxt == 'E' || nxt == 'W')
		return (1);
	return (0);
}

void	key_hook(mlx_key_data_t key, void *param)
{
	t_move		*move;

	move = param;
	if (key.key == MLX_KEY_ESCAPE && key.action == MLX_PRESS)
		mlx_close_window(move->render->mlx);
}
