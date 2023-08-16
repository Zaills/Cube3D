/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gouz <gouz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:33:57 by gouz              #+#    #+#             */
/*   Updated: 2023/08/16 18:35:40 by gouz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include "../libft/libft.h"
# include "stdio.h"
# define FLOOR_ERR 1
# define CEIL_ERR 2
# define ORDER_SYMB 3

typedef struct parsing
{
	char	*no_text;
	char	*so_text;
	char	*we_text;
	char	*ea_text;
	char	*floor;
	char	*ceil;
	char	**file;
}		t_parse;

char	**open_map(int ac, char **av);
char	**cub_to_cubed(char *cub);
void	free_cubed(char **cubed);
int		init_identifier(t_parse *data);
void	free_parsedata(t_parse *data);

//utils

int		output_error(int code);
int		count_char(char *str, char c);
//TEMPORARY SECTION FOR DEBUGGING

void	d_print_parsedata(t_parse *data);

#endif
