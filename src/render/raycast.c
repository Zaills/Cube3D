/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:26:40 by gouz              #+#    #+#             */
/*   Updated: 2023/09/06 17:57:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "math.h"

void	raycast(t_render *render, char **map) //NEED DDA and norm
{
	int		i;
	double	cameraX;
	double	rayDirX;
	double	rayDirY;

	int mapX;
	int mapY;

	double sideDistX;
	double sideDistY;

	double perpWallDist;

	int stepX;
	int stepY;

	int hit;
	int side;
	hit = 0;
	double deltaDistX;
	double deltaDistY;
	i = 0;
	while (i < WIDTH) // envoie un rayon par chaque ligne vertical de l ecran
	{
		hit = 0;
		cameraX = 2 * i / (double)WIDTH - 1;
		rayDirX = render->dirX + render->planeX * cameraX;
		rayDirY = render->dirY + render->planeY * cameraX;

		mapX = (int)render->spawn_x;
		mapY = (int)render->spawn_y;

		deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX); // need to be normed
		deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);// idk how to do

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
		while(hit == 0) // trace le chemin du rayon et check si un mur
		{
		//jump to next map square, either in x-direction, or in y-direction
			if(sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			//Check if ray has hit a wall
			if(map[mapX][mapY] == '1')
				hit = 1;
		}
		if(side == 0)
			perpWallDist = (sideDistX - deltaDistX);
		else
			perpWallDist = (sideDistY - deltaDistY);

		//Calculate height of line to draw on screen
		int lineHeight;
		lineHeight = (int)(HEIGHT / perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + HEIGHT / 2;
		if(drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + HEIGHT / 2;
		if(drawEnd >= HEIGHT)
			drawEnd = HEIGHT - 1;
		draw_ver_line(drawStart, drawEnd, render, i);
		i++;
	}
}
