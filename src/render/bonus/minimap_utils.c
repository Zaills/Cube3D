/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gouz <gouz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:28:27 by gouz              #+#    #+#             */
/*   Updated: 2023/09/25 20:49:13 by gouz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	big_pix(mlx_image_t *img, int x, int y, int color)
{
	int	i;
	int	j;

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

void	draw_outline_place(t_render *render)
{
	int	i;

	i = 0;
	while (i < 11)
	{
		big_pix(render->minimap, i * 10, 0, 0xFF0000FF);
		big_pix(render->minimap, i * 10, 100, 0xFF0000FF);
		big_pix(render->minimap, 0, i * 10, 0xFF0000FF);
		big_pix(render->minimap, 100, i * 10, 0xFF0000FF);
		i++;
	}
	big_pix(render->minimap, 5 * 10, 5 * 10, 0x00FF00FF);
	mlx_image_to_window(render->mlx, render->minimap, 0, 0);
}

void	draw_bg(t_render *render)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (i < 10)
	{
		while (j < 10)
		{
			big_pix(render->minimap, i * 10, j * 10, 0x0000FFFF);
			j++;
		}
		j = 0;
		i++;
	}
}
