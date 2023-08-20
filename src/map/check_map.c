/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gouz <gouz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 03:36:06 by gouz              #+#    #+#             */
/*   Updated: 2023/08/20 04:27:04 by gouz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parsing.h"

void	get_map(t_parse *data, int i)
{
	while (count_c(data->file[i], ' ') + count_c(data->file[i], '\t')
		== ft_strlen(data->file[i]))
		i++;
	data->map = &data->file[i];
}

static int	check_line(char *line)
{
	int			i;
	static int	spawn = 0;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '0' && line[i] != '1' && line[i] != 'N'
			&& line[i] != 'W' && line[i] != 'S' && line[i] != 'E')
			return (-1);
		if (line[i] == 'N' || line[i] == 'W'
			|| line[i] == 'S' || line[i] == 'E')
			spawn++;
		if (spawn > 1)
			return (-1);
		i++;
	}
	return (1);
}

int	check_map(t_parse *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		if (check_line(data->map[i]) == -1)
			return (-1);
		i++;
	}
	return (1);
}
