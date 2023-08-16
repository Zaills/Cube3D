/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gouz <gouz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:33:57 by gouz              #+#    #+#             */
/*   Updated: 2023/08/16 15:50:01 by gouz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include "../libft/libft.h"
# include "stdio.h"
# define FLOOR_ERR 1
# define CEIL_ERR 2

typedef struct parsing
{
	char	*no_text;	// "./path_to_texture"
	char	*so_text;
	char	*we_text;
	char	*ea_text;
	char	*floor;	// "255,200,100"
	char	*ceil;
	char	**map;
}		t_parse;

char	**open_map(int ac, char **av);
char	**cub_to_cubed(char *cub);
int		output_error(int code);
void	free_cubed(char **cubed);
void	init_identifier(t_parse *data);
void	free_parsedata(t_parse *data);

//TEMPORARY SECTION FOR DEBUGGING

void d_print_parsedata(t_parse *data);

#endif
