/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:26:40 by gouz              #+#    #+#             */
/*   Updated: 2023/09/05 15:26:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "math.h"

void	raycast(t_render *render) //NEED DDA and norm
{
	(void) render;
	return;
/* 	int		i;
	double	cameraX;
	double	rayDirX;
	double	rayDirY;

	int mapX;
	int mapY;

	double sideDistX;
	double sideDistY;

	//double perpWallDist;

	int stepX;
	int stepY;

	//int hit;
	//int side;
	//hit = 0;
	double deltaDistX;
	double deltaDistY;
	i = 0;

	while (i < WIDTH)
	{
		cameraX = 2 * i / (double)WIDTH - 1;
		rayDirX = render->dirX + render->planeX * cameraX;
		rayDirY = render->dirY + render->planeY * cameraX;

		mapX = (int)render->spawn_x;
		mapY = (int)render->spawn_y;

		deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
		deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);

		if(rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (render->spawn_x - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - render->spawn_x) * deltaDistX;
		}
		if(rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (render->spawn_y - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - render->spawn_y) * deltaDistY;
		}
	}*/
}
