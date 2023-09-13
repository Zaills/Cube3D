/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gouz <gouz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:55:31 by gouz              #+#    #+#             */
/*   Updated: 2023/09/13 18:26:04 by gouz             ###   ########.fr       */
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
				return ;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

static int	init_texture(t_render *render, t_parse *data)
{
	xpm_t	*temp;

	temp = mlx_load_xpm42(data->no_text);
	if (!temp)
		return (-1);
	render->text[0] = mlx_texture_to_image(render->mlx, &temp->texture);
	mlx_delete_xpm42(temp);
	temp = mlx_load_xpm42(data->ea_text);
	if (!temp)
		return (-1);
	render->text[1] = mlx_texture_to_image(render->mlx, &temp->texture);
	mlx_delete_xpm42(temp);
	temp = mlx_load_xpm42(data->so_text);
	if (!temp)
		return (-1);
	render->text[2] = mlx_texture_to_image(render->mlx, &temp->texture);
	mlx_delete_xpm42(temp);
	temp = mlx_load_xpm42(data->we_text);
	if (!temp)
		return (-1);
	render->text[3] = mlx_texture_to_image(render->mlx, &temp->texture);
	mlx_delete_xpm42(temp);
	if (render->text[0] == NULL || render->text[1] == NULL
		|| render->text[2] == NULL || render->text[3] == NULL)
		return (-1);
	return (1);
}

void	free_render(t_render *render)
{
	int	i;

	i = 0;
	if (render->view != NULL)
		mlx_delete_image(render->mlx, render->view);
	if (render->minimap != NULL)
		mlx_delete_image(render->mlx, render->minimap);
	if (render->player != NULL)
		mlx_delete_image(render->mlx, render->player);
	while (i < 3)
	{
		if (render->text[i] != NULL)
			mlx_delete_image(render->mlx, render->text[i]);
		i++;
	}
}


int	init_render(t_render *render, t_parse *data)
{
	render->mlx = mlx_init(WIDTH, HEIGHT, "Cub3d", true);
	render->view = mlx_new_image(render->mlx, WIDTH, HEIGHT);
	render->minimap = mlx_new_image(render->mlx, 500, 500);
	render->player = mlx_new_image(render->mlx, 10, 10);
	get_player_pos(data->map, render);
	render->text[0] = NULL;
	render->text[1] = NULL;
	render->text[2] = NULL;
	render->text[3] = NULL;
	if (init_texture(render,data) == -1)
	{
		printf("Error : a texture path is wrong / a texture can't be loaded\n");
		free_render(render);
		return (-1);
	}
	return (1);
}
