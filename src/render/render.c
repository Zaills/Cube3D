/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gouz <gouz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 17:21:26 by gouz              #+#    #+#             */
/*   Updated: 2023/09/01 18:20:07 by gouz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "parsing.h"

int	init_texture(t_parse *data, mlx_t* mlx)
{
	xpm_t* xpm = mlx_load_xpm42(data->no_text);
	mlx_image_t* img = mlx_texture_to_image(mlx, &xpm->texture);
	mlx_image_to_window(mlx, img, 0, 0);
	return 1;
}

int get_rgba(char *type)
{
	char **temp;
	int	r;
	int	g;
	int	b;
	temp = ft_split(type, ',');
	r = ft_atoi(temp[0]);
	g = ft_atoi(temp[1]);
	b = ft_atoi(temp[2]);
	return (r << 24 | g << 16 | b << 8 | 255);
}

void	render_sky_floor(mlx_t* mlx, t_parse *data)
{
	mlx_image_t* img = mlx_new_image(mlx, WIDTH, HEIGHT);
	ft_memset(img->pixels, 255, img->width * img->height * sizeof(int32_t));
	for (int i =0; i < WIDTH; i++)
	{
		for (int j =0; j < HEIGHT/2; j++)
			mlx_put_pixel(img, i,j,get_rgba(data->ceil));
	}
	for (int i =0; i < WIDTH; i++)
	{
		for (int j =HEIGHT/2; j < HEIGHT; j++)
			mlx_put_pixel(img, i,j,get_rgba(data->floor));
	}
	mlx_image_to_window(mlx, img, 0, 0);
}

void	render(t_parse *data)
{
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "Cub3d", true);
	//init_texture(data, mlx); segfault
	render_sky_floor(mlx,data);
	mlx_loop(mlx);
	mlx_terminate(mlx);
}
