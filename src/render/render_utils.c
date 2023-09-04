/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gouz <gouz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:55:31 by gouz              #+#    #+#             */
/*   Updated: 2023/09/04 15:21:56 by gouz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int	get_rgba(char *type)
{
	char	**temp;
	int		r;
	int		g;
	int		b;

	temp = ft_split(type, ',');
	r = ft_atoi(temp[0]);
	g = ft_atoi(temp[1]);
	b = ft_atoi(temp[2]);
	return (r << 24 | g << 16 | b << 8 | 255);
}
