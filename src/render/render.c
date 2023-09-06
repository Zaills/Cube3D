/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 17:21:26 by gouz              #+#    #+#             */
/*   Updated: 2023/09/06 17:50:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "stdio.h"

int	init_texture(t_parse *data, mlx_t* mlx) //need check how to use this (with render struct)
{
	mlx_texture_t* png;
	mlx_image_t* img;

	png = mlx_load_png(data->no_text);
	if (!png)
	{
		printf ("png failed\n");
		return (-1);
	}
	img = mlx_texture_to_image(mlx, png);
	if (!img)
	{
		printf("img failed\n");
		return (-1);
	}
	mlx_image_to_window(mlx, img, 0, 0); //uncomment to display the current image
	return 1;
}

void	render(t_parse *data)
{
	mlx_t*	mlx;
	t_render render;
	t_movement	movement;

	mlx = mlx_init(WIDTH, HEIGHT, "Cub3d", true);
	render_sky_floor(mlx,data);
	init_texture(data, mlx); // check error
	init_render(&render, data);
	init_movement(&movement, &render, mlx, data);
	printf("dir x: %f\ndir y: %f\n", render.dirX, render.dirY);
	minimap(data, mlx);
	render_player(&render, mlx);
	mlx_key_hook(mlx, &key_hook, &movement);
	raycast(&render);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	printf("dir x: %f\ndir y: %f\n", render.dirX, render.dirY);
}
