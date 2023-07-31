/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gouz <gouz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:33:57 by gouz              #+#    #+#             */
/*   Updated: 2023/07/31 17:12:26 by gouz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include "../libft/libft.h"

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

#endif
