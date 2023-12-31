/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorandi <nmorandi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 17:21:26 by gouz              #+#    #+#             */
/*   Updated: 2023/09/26 17:02:33 by nmorandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include <stdio.h>

static int	check_loaded(t_render *render)
{
	if (render->text[0] == NULL || render->text[1] == NULL
		|| render->text[2] == NULL || render->text[3] == NULL)
		return (-1);
	else
		return (1);
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
	if (check_loaded(render) == -1)
		return (-1);
	return (1);
}

void	free_render(t_render *render)
{
	int	i;

	i = 0;
	if (render->view != NULL)
		mlx_delete_image(render->mlx, render->view);
	while (i < 3)
	{
		if (render->text[i] != NULL)
			mlx_delete_image(render->mlx, render->text[i]);
		i++;
	}
}

static int	init_render(t_render *render, t_parse *data)
{
	render->mlx = mlx_init(WIDTH, HEIGHT, "Cub3d", true);
	render->view = mlx_new_image(render->mlx, WIDTH, HEIGHT);
	get_player_pos(data->map, render);
	render->text[0] = NULL;
	render->text[1] = NULL;
	render->text[2] = NULL;
	render->text[3] = NULL;
	if (init_texture(render, data) == -1)
	{
		printf("Error : a texture path is wrong / a texture can't be loaded\n");
		free_render(render);
		return (-1);
	}
	return (1);
}

void	render(t_parse *data)
{
	t_render	render;
	t_move		move;

	if (init_render(&render, data) == -1)
		return ;
	init_move(&move, &render, data);
	mlx_set_cursor_mode(render.mlx, 0x00034002);
	render_sky_floor(&render, data);
	minimap(data, &render, render.spawn_x, render.spawn_y);
	raycast(&render, data->map);
	mlx_image_to_window(render.mlx, render.view, 0, 0);
	mlx_key_hook(render.mlx, &key_hook, &move);
	mlx_loop_hook(render.mlx, &l_hook, &move);
	mlx_loop_hook(render.mlx, &loop_hook, &move);
	mlx_loop(render.mlx);
	mlx_terminate(render.mlx);
}
