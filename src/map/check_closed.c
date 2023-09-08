/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_closed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:43:56 by nmorandi          #+#    #+#             */
/*   Updated: 2023/09/08 13:07:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int get_len_line(char *line)
{
	int i;

	i = 0;
	while (line[i])
		i++;
	return (i);
}

static int get_len_map(char **map)
{
	int i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

static int	is_surrounded(char **map, int i, int j)
{
	int verif;

	verif = 0;
	if(i == 0 || j == 0 || j == get_len_line(map[i]) || i == get_len_map(map)
		|| j >= get_len_line(map[i + 1]) || j >= get_len_line(map[i - 1]))
		return (-1);
	if (map[i][j + 1] == '1' || map[i][j + 1] == '0' || map[i][j + 1] == 'N'
		|| map[i][j + 1] == 'S' || map[i][j + 1] == 'E' || map[i][j + 1] == 'W')
		verif++;
	if (map[i][j - 1] == '1' || map[i][j - 1] == '0' || map[i][j - 1] == 'N'
		|| map[i][j - 1] == 'S' || map[i][j - 1] == 'E' || map[i][j - 1] == 'W')
		verif++;
	if (map[i + 1][j] == '1' || map[i + 1][j] == '0' || map[i + 1][j] == 'N'
		|| map[i + 1][j] == 'S' || map[i + 1][j] == 'E' || map[i + 1][j] == 'W')
		verif++;
	if (map[i - 1][j] == '1' || map[i - 1][j] == '0' || map[i - 1][j] == 'N'
		|| map[i - 1][j] == 'S' || map[i - 1][j] == 'E' || map[i - 1][j] == 'W')
		verif++;
	if (verif != 4)
		return (-1);
	return (1);
}

int	check_closed(t_parse *data)
{
	int		i;
	int		j;
	char	**map_edit;

	map_edit = data->map;
	if (!map_edit)
		return (-1);
	j = 0;
	i = 0;
	while (map_edit[i])
	{
		while (map_edit[i][j])
		{
			if (map_edit[i][j] == '0' || map_edit[i][j] == 'N'
				 || map_edit[i][j] == 'S' || map_edit[i][j] == 'E'
				 || map_edit[i][j] == 'W')
				if (is_surrounded(map_edit, i , j) == -1)
					return (-1);
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}
