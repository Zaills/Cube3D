/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:16:42 by marvin            #+#    #+#             */
/*   Updated: 2023/09/04 18:16:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "stdio.h"

void	put_big_pixel(mlx_image_t* img, int x, int y, int color)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 10)
	{
		while (j < 10)
		{
			mlx_put_pixel(img, x + i, y + j, color);
			j++;
		}
		j = 0;
		i++;
	}
}

void	minimap(t_parse* data, t_render *render)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (data->map[y])
	{
		while (data->map[y][x])
		{
			if (data->map[y][x] == '1')
				put_big_pixel(render->minimap, x * 10, y * 10, 0x000000FF);
			else if (data->map[y][x] == 'N' || data->map[y][x] == 'S'
				|| data->map[y][x] == 'E' || data->map[y][x] == 'W')
				put_big_pixel(render->minimap, x * 10, y * 10, 0xFFFFFFFF);
			else if (data->map[y][x] == '0')
				put_big_pixel(render->minimap, x * 10, y * 10, 0xFFFFFFFF);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_image_to_window(render->mlx, render->minimap, 0, 0);
}

void	render_player(t_render *render, mlx_t* mlx)
{
	put_big_pixel(render->player, 0, 0, 0x00FF00FF);
	mlx_image_to_window(mlx, render->player, (int) (render->spawn_y * 10), (int) (render->spawn_x * 10));
}
