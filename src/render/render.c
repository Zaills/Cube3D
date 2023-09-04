/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 17:21:26 by gouz              #+#    #+#             */
/*   Updated: 2023/09/04 19:02:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "stdio.h"

int	init_texture(t_parse *data, mlx_t* mlx) //need check how to use this (with render struct)
{
	mlx_texture_t* png;
	mlx_image_t* img;

	printf("texture = %s\n", data->no_text);
	png = mlx_load_png(data->no_text);
	if (!png)
	{
		printf ("png failed\n");
		return 1;
	}
	img = mlx_texture_to_image(mlx, png);
	if (!img)
	{
		printf("img failed\n");
		return (1);
	}
	//mlx_image_to_window(mlx, img, 0, 0); //uncomment to display the current image
	return 1;
}

void	render(t_parse *data)
{
	mlx_t* mlx;

	//t_render render; //used to store data for rendering (like spawn , texture etc...)
	mlx = mlx_init(WIDTH, HEIGHT, "Cub3d", true);
	render_sky_floor(mlx,data);
	init_texture(data, mlx);
	minimap(data, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
}
