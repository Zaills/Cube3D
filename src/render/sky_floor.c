/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sky_floor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gouz <gouz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:55:28 by gouz              #+#    #+#             */
/*   Updated: 2023/09/04 14:58:58 by gouz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static void	draw_sky(mlx_image_t *img, char *ceil)
{
	int	i;
	int	j;
	int	rgba;

	rgba = get_rgba(ceil);
	j = -1;
	i = -1;
	while (++i < WIDTH)
	{
		while (++j < HEIGHT/2)
			mlx_put_pixel(img, i,j,rgba);
		j = -1;
	}
}

static void	draw_floor(mlx_image_t *img, char *floor)
{
	int	i;
	int	j;
	int	rgba;

	rgba = get_rgba(floor);
	j = HEIGHT/2;
	i = -1;
	while (++i < WIDTH)
	{
		while (j < HEIGHT)
		{
			mlx_put_pixel(img, i,j,rgba);
			j++;
		}
		j = HEIGHT/2;
	}
}

void	render_sky_floor(mlx_t* mlx, t_parse *data)
{
	mlx_image_t*	img;

	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	ft_memset(img->pixels, 255, img->width * img->height * sizeof(int32_t));
	draw_sky(img, data->ceil);
	draw_floor(img, data->floor);
	mlx_image_to_window(mlx, img, 0, 0);
}
