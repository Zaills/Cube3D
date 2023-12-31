/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gouz <gouz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:33:57 by gouz              #+#    #+#             */
/*   Updated: 2023/09/25 20:53:06 by gouz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include "parse_struct.h"
# include "../libft/libft.h"
# include <stdio.h>
# define FLOOR_ERR 1
# define CEIL_ERR 2
# define ORDER_SYMB 3
# define MAP_ERR 4

int		get_height(char **map);
char	**open_map(int ac, char **av);
void	close_map(t_parse *data);
char	**cub_to_cubed(char *cub);
void	free_cubed(char **cubed);
int		init_identifier(t_parse *data);
int		get_map(t_parse *data, int i);
int		check_map(t_parse *data);
int		check_closed(t_parse *data);
int		output_error(int code);
int		count_c(char *str, char c);
int		precheck_parse(t_parse *data);
char	*skip_space(char *str);

#endif
