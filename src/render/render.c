/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 17:21:26 by gouz              #+#    #+#             */
/*   Updated: 2023/09/05 20:02:21 by marvin           ###   ########.fr       */
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

void	dkey(mlx_key_data_t key, void* param)
{
	mlx_t* mlx;

	mlx = param;
	if(key.key == MLX_KEY_UP && key.action == MLX_PRESS)
		printf("/\\\n");
	if(key.key == MLX_KEY_DOWN && key.action == MLX_PRESS)
		printf("\\/\n");
	if(key.key == MLX_KEY_LEFT && key.action == MLX_PRESS)
		printf("<-\n");
	if(key.key == MLX_KEY_RIGHT && key.action == MLX_PRESS)
		printf("->\n");
	if (key.key == MLX_KEY_W && key.action == MLX_PRESS)
		printf("W\n");
	if (key.key == MLX_KEY_A && key.action == MLX_PRESS)
		printf("A\n");
	if (key.key == MLX_KEY_S && key.action == MLX_PRESS)
		printf("S\n");
	if (key.key == MLX_KEY_D && key.action == MLX_PRESS)
		printf("D\n");
	if(key.key == MLX_KEY_ESCAPE && key.action == MLX_PRESS)
		mlx_close_window(mlx);

}

void	render(t_parse *data)
{
	mlx_t*	mlx;
	t_render render;

	mlx = mlx_init(WIDTH, HEIGHT, "Cub3d", true);
	render_sky_floor(mlx,data);
	init_texture(data, mlx); // check error
	init_render(&render, data);
	printf("dir x: %f\ndir y: %f\n", render.dirX, render.dirY);
	minimap(data, mlx);
	render_player(&render, mlx);
	mlx_key_hook(mlx, &dkey, mlx);
	raycast(&render);
	mlx_loop(mlx);
	mlx_terminate(mlx);
}
