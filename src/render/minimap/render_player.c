/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:12:00 by marvin            #+#    #+#             */
/*   Updated: 2023/09/05 15:12:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "stdio.h"

void	player_no(mlx_image_t* img)
{
	int i;

	i = 0;
	while (i < 10)
	{
		mlx_put_pixel(img, 5, i, 0xFF0000FF);
		i++;
	}
}

void	wich_player(t_render* render, mlx_image_t* img)
{
	if (render->dirX < 90 && render->dirX > -90)
	{
		if (render->dirY < 90 && render->dirY > -90)
			player_no(img);
		else
			printf("S\n") ;
	}
	else
	{
		if (render->dirY < 90 && render->dirY > -90)
			printf("N\n") ;
		else
			printf("E\n") ;
	}
}
