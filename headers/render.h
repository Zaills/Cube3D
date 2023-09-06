/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gouz <gouz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 17:25:13 by gouz              #+#    #+#             */
/*   Updated: 2023/09/06 17:25:26 by gouz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H
# include "../MLX42/include/MLX42/MLX42.h"
# include "parse_struct.h"
# include "../../libft/libft.h"
#define HEIGHT 800
#define WIDTH 800

typedef struct render
{
	mlx_t*			mlx;
	mlx_image_t*	view;
	double			spawn_x;
	double			spawn_y;
	double			dirX;
	double			dirY;
	double			planeX;
	double			planeY;
}		t_render;

typedef struct s_image {
	void	*so;
	void	*no;
	void	*we;
	void	*ea;
}	t_image;

void	render(t_parse *data);
void	render_sky_floor(t_render *render, t_parse *data);
void	minimap(t_parse *data, mlx_t* mlx);
void	draw_ver_line(int start, int end, t_render *render, int x);
void	raycast(t_render *render, char **map);
//UTILS
void	render_player(t_render *render, mlx_t* mlx);
void	wich_player(t_render* render, mlx_image_t* img);
void	init_render(t_render *render, t_parse *data);
void	get_player_pos(char **map, t_render *render);
int		get_rgba(char *type);

#endif
