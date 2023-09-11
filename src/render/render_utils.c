/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:55:31 by gouz              #+#    #+#             */
/*   Updated: 2023/09/11 11:52:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "render.h"
#include "parse_struct.h"
#include "stdio.h"

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
	if (dir == 'N')
	{
		render->dirX = -1;
		render->dirY = 0;
		render->planeX = 0;
		render->planeY = 0.66;
	}
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
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E' || map[i][j] == 'W')
			{
				render->spawn_y = j + 0.5;
				render->spawn_x = i + 0.5;
				get_player_dir(map[i][j], render);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	init_render(t_render *render, t_parse *data)
{
	render->mlx = mlx_init(WIDTH, HEIGHT, "Cub3d", true);
	render->view = mlx_new_image(render->mlx, WIDTH, HEIGHT);
	render->minimap = mlx_new_image(render->mlx, 500, 500);
	render->player = mlx_new_image(render->mlx, 10, 10);
	get_player_pos(data->map, render);
//	render->dirX = 1; // changer selon N S E W (direction de la vue fps)
//	render->dirY = 0;
//	render->planeX = 0;
//	render->planeY = -0.66;
	printf("spawn is at coord:x=%f,y=%f\n",render->spawn_x, render->spawn_y);
}
