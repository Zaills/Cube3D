/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 17:25:13 by gouz              #+#    #+#             */
/*   Updated: 2023/09/15 15:42:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H
# include "../MLX42/include/MLX42/MLX42.h"
# include "parse_struct.h"
# include "../../libft/libft.h"
#define HEIGHT 1000
#define WIDTH 1800
#define MOVE_SPEED 0.1

typedef struct render
{
	mlx_t*			mlx;
	mlx_image_t*	view;
	mlx_image_t*	minimap;
	mlx_image_t*	player;
	mlx_image_t*	text[4];
	double			rayDirX;
	double			rayDirY;
	double			spawn_x;
	double			spawn_y;
	double			dirX;
	double			dirY;
	double			planeX;
	double			planeY;
	double			deltaDistX;
	double			deltaDistY;
	double			sideDistX;
	double			sideDistY;
	double			wallX;
	double			texPos;
	int				line_height;
	int				stepX;
	int				stepY;
	int				mapX;
	int				mapY;
	int				side;
	int				texX;
	int				texY;
}		t_render;

typedef struct move
{
	t_render*	render;
	t_parse*	data;
}		t_move;

void	render(t_parse *data);
void	render_sky_floor(t_render *render, t_parse *data);
void	minimap(t_parse* data, t_render *render);
void	raycast(t_render *render, char **map);
void	draw_wall(double wall_dist, int i, t_render *render);
//UTILS
void	render_player(t_render *render, mlx_t* mlx);
void	key_hook(mlx_key_data_t key, void* param);
void	init_move(t_move *move, t_render *render, t_parse *data);
int		verif_move(char nxt);
void	get_player_pos(char **map, t_render *render);
int		get_rgba(char *type);
int		get_texture(t_render *render);
int		encode_color(int x, int y, t_render *render);

#endif
