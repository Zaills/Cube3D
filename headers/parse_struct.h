/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gouz <gouz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:56:48 by gouz              #+#    #+#             */
/*   Updated: 2023/09/15 16:03:16 by gouz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_STRUCT_H
# define PARSE_STRUCT_H

typedef struct parsing
{
	char	*no_text;
	char	*so_text;
	char	*we_text;
	char	*ea_text;
	char	*floor;
	char	*ceil;
	char	**file;
	char	**map;
}		t_parse;

void	free_parsedata(t_parse *data);

#endif
