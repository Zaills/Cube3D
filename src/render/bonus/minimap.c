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

void	put_big_pixel(mlx_image_t *img, int x, int y, int color)
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
#include <stdio.h>

static void	draw_outline(t_render *render)
{
	int	i;

	i = 0;
	while (i < 11)
	{
		put_big_pixel(render->minimap, i*10, 0, 0xFF0000FF);
		put_big_pixel(render->minimap, i*10, 100, 0xFF0000FF);
		put_big_pixel(render->minimap, 0, i*10, 0xFF0000FF);
		put_big_pixel(render->minimap, 100, i*10, 0xFF0000FF);
		i++;
	}
}

static void	draw_upright(char c, t_render *render, int i, int j)
{
	if (c == '0')
		put_big_pixel(render->minimap, (5+i) * 10, (5-j) * 10, 0xFFFFFFFF);
	else if (c == '1')
		put_big_pixel(render->minimap, (5+i) * 10, (5-j) * 10, 0x000000FF);
 	else
		put_big_pixel(render->minimap, (5+i) * 10, (5-j) * 10, 0x0000FFFF);
}

static void	draw_botright(char c, t_render *render, int i, int j)
{
	if (c == '0')
		put_big_pixel(render->minimap, (5+i) * 10, (5+j) * 10, 0xFFFFFFFF);
	else if (c == '1')
		put_big_pixel(render->minimap, (5+i) * 10, (5+j) * 10, 0x000000FF);
 	else
		put_big_pixel(render->minimap, (5+i) * 10, (5+j) * 10, 0x0000FFFF);
}

static void	draw_upleft(char c, t_render *render, int i, int j)
{
	if (c == '0')
		put_big_pixel(render->minimap, (5-i) * 10, (5-j) * 10, 0xFFFFFFFF);
	else if (c == '1')
		put_big_pixel(render->minimap, (5-i) * 10, (5-j) * 10, 0x000000FF);
 	else
		put_big_pixel(render->minimap, (5-i) * 10, (5-j) * 10, 0x0000FFFF);
}

static void	draw_botleft(char c, t_render *render, int i, int j)
{
	if (c == '0')
		put_big_pixel(render->minimap, (5-i) * 10, (5+j) * 10, 0xFFFFFFFF);
	else if (c == '1')
		put_big_pixel(render->minimap, (5-i) * 10, (5+j) * 10, 0x000000FF);
	else
		put_big_pixel(render->minimap, (5-i) * 10, (5+j) * 10, 0x0000FFFF);
}

int	get_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	minimap(t_parse *data, t_render *render)
{
 	int	x;
	int y;
	int i;
	int j;
	int	h;
	h = get_height(data->map);
	x = render->spawn_x;
	y = render->spawn_y;
	i = 0;
	j = 0;
	draw_outline(render);
	while (j < 5)
	{
		while (i < 5)
		{
			if (x + j < h && y+i < (int)ft_strlen(data->map[x+j]))
				draw_botright(data->map[x+j][y+i], render, i,j);
			else
				put_big_pixel(render->minimap, (5+i) * 10, (5+j) * 10, 0x0000FFFF);
			if (x - j >= 0 && y + i < (int)ft_strlen(data->map[x-j]))
				draw_upright(data->map[x-j][y+i], render, i, j);
			else
				put_big_pixel(render->minimap, (5+i) * 10, (5-j) * 10, 0x0000FFFF);
			if (x - j >= 0 && y - i >= 0)
				draw_upleft(data->map[x-j][y-i], render, i ,j);
			else
				put_big_pixel(render->minimap, (5-i) * 10, (5-j) * 10, 0x0000FFFF);
			if (y - i >= 0 && x + j <h)
				draw_botleft(data->map[x+j][y-i], render ,i ,j);
			else
				put_big_pixel(render->minimap, (5-i) * 10, (5+j) * 10, 0x0000FFFF);
			i++;
		}
		j++;
		i = 0;
	}
	put_big_pixel(render->minimap, 5 * 10, 5 * 10, 0x00FF00FF);
	mlx_image_to_window(render->mlx, render->minimap, 0, 0);
}
