/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 17:25:13 by gouz              #+#    #+#             */
/*   Updated: 2023/09/05 20:04:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H
# include "../MLX42/include/MLX42/MLX42.h"
# include "parse_struct.h"
# include "../../libft/libft.h"
#define HEIGHT 1080
#define WIDTH 1920

typedef struct render
{
	double	spawn_x;
	double	spawn_y;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;

}		t_render;

typedef struct s_image {
	void	*so;
	void	*no;
	void	*we;
	void	*ea;
}	t_image;

void	render();
void	render_sky_floor(mlx_t* mlx, t_parse *data);
void	minimap(t_parse *data, mlx_t* mlx);
void	render_player(t_render *render, mlx_t* mlx);
void	wich_player(t_render* render, mlx_image_t* img);
void	init_render(t_render *render, t_parse *data);
void	get_player_pos(char **map, t_render *render);
void	raycast(t_render *render);
//UTILS
int		get_rgba(char *type);

#endif
