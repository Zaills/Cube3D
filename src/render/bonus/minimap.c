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

static void	draw_upright(char c, t_render *render, int i, int j)
{
	if (c == '0')
		big_pix(render->minimap, (5 + i) * 10, (5 - j) * 10, 0xFFFFFFFF);
	if (c == '1')
		big_pix(render->minimap, (5 + i) * 10, (5 - j) * 10, 0x000000FF);
}

static void	draw_botright(char c, t_render *render, int i, int j)
{
	if (c == '0')
		big_pix(render->minimap, (5 + i) * 10, (5 + j) * 10, 0xFFFFFFFF);
	if (c == '1')
		big_pix(render->minimap, (5 + i) * 10, (5 + j) * 10, 0x000000FF);
}

static void	draw_upleft(char c, t_render *render, int i, int j)
{
	if (c == '0')
		big_pix(render->minimap, (5 - i) * 10, (5 - j) * 10, 0xFFFFFFFF);
	if (c == '1')
		big_pix(render->minimap, (5 - i) * 10, (5 - j) * 10, 0x000000FF);
}

static void	draw_botleft(char c, t_render *render, int i, int j)
{
	if (c == '0')
		big_pix(render->minimap, (5 - i) * 10, (5 + j) * 10, 0xFFFFFFFF);
	if (c == '1')
		big_pix(render->minimap, (5 - i) * 10, (5 + j) * 10, 0x000000FF);
}

void	minimap(t_parse *data, t_render *r, int x, int y)
{
	int	i;
	int	j;
	int	h;

	h = get_height(data->map);
	i = 0;
	j = -1;
	draw_bg(r);
	while (++j < 5)
	{
		while (i < 5)
		{
			if (x + j < h && y + i < (int)ft_strlen(data->map[x + j]))
				draw_botright(data->map[x + j][y + i], r, i, j);
			if (x - j >= 0 && y + i < (int)ft_strlen(data->map[x - j]))
				draw_upright(data->map[x - j][y + i], r, i, j);
			if (x - j >= 0 && y - i >= 0)
				draw_upleft(data->map[x - j][y - i], r, i, j);
			if (x + j < h && y - i >= 0)
				draw_botleft(data->map[x + j][y - i], r, i, j);
			i++;
		}
		i = 0;
	}
	draw_outline_place(r);
}
