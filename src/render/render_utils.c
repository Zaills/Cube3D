/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gouz <gouz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:55:31 by gouz              #+#    #+#             */
/*   Updated: 2023/09/15 14:08:19 by gouz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int	get_rgba(char *type)
{
	char	**temp;
	int		r;
	int		g;
	int		b;

	temp = ft_split(type, ',');
	r = ft_atoi(temp[0]);
	g = ft_atoi(temp[1]);
	b = ft_atoi(temp[2]);
	free(temp[0]);
	free(temp[1]);
	free(temp[2]);
	free(temp);
	return (r << 24 | g << 16 | b << 8 | 255);
}

void	get_player_dir(char dir, t_render *render)
{
	render->dirX = -1;
	render->dirY = 0;
	render->planeX = 0;
	render->planeY = 0.66;
	if (dir == 'S')
	{
		render->dirX = 1;
		render->dirY = 0;
		render->planeX = 0;
		render->planeY = -0.66;
	}
	if (dir == 'E')
	{
		render->dirX = 0;
		render->dirY = 1;
		render->planeX = 0.66;
		render->planeY = 0;
	}
	if (dir == 'W')
	{
		render->dirX = 0;
		render->dirY = -1;
		render->planeX = -0.66;
		render->planeY = 0;
	}
}

void	get_player_pos(char **map, t_render *render)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
			{
				render->spawn_y = j + 0.5;
				render->spawn_x = i + 0.5;
				get_player_dir(map[i][j], render);
				return ;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

int	get_texture(t_render *render)
{
	if (render->side == 0 && render->rayDirX < 0)
		return (0);
	if (render->side == 0 && render->rayDirX > 0)
		return (2);
	if (render->side == 1 && render->rayDirY < 0)
		return (3);
	return (1);
}

int	encode_color(int x, int y, t_render *render)
{
	int	r;
	int	g;
	int	b;
	int	pixel_pos;
	int	text_index;

	text_index = get_texture(render);
	pixel_pos = (4 * x) + (256 * y);
	r = render->text[text_index]->pixels[pixel_pos];
	g = render->text[text_index]->pixels[pixel_pos + 1];
	b = render->text[text_index]->pixels[pixel_pos + 2];
	return (r << 24 | g << 16 | b << 8 | 255);
}
