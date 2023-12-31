/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorandi <nmorandi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:28:27 by gouz              #+#    #+#             */
/*   Updated: 2023/09/26 17:00:54 by nmorandi         ###   ########.fr       */
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
		big_pix(render->view, i * 10, 0, 0xFF0000FF);
		big_pix(render->view, i * 10, 100, 0xFF0000FF);
		big_pix(render->view, 0, i * 10, 0xFF0000FF);
		big_pix(render->view, 100, i * 10, 0xFF0000FF);
		i++;
	}
	big_pix(render->view, 5 * 10, 5 * 10, 0x00FF00FF);
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
			big_pix(render->view, i * 10, j * 10, 0x0000FFFF);
			j++;
		}
		j = 0;
		i++;
	}
}
