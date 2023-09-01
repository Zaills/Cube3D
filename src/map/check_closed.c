/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_closed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:43:56 by nmorandi          #+#    #+#             */
/*   Updated: 2023/09/01 14:35:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/*static int	is_surrounded(char **map, int i, int j)// take 0 and check if surrounded
{
	int top;
	int	tempi;

	top = 0;
	tempi = i;
	while (i >= 0)
	{
		printf("checking if %c is 1, i is %d\n", map[i][j], i); // need check avec la len des lignes pour pas target du vide
		if (map[i][j] == '1')
			top = 1;
		i--;
	}
	if (top == 0)
		return (-1);
	map[tempi][j] = '1';
	return (1);
}*/

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
		|| j >= get_len_line(map[i + 1]) || j >= get_len_line(map[i - 1]))	//check si on est pas out of range
		return (-1);
	if (map[i][j + 1] == '1' || map[i][j + 1] == '0' || map[i][j + 1] == 'N'
		|| map[i][j + 1] == 'S' || map[i][j + 1] == 'E' || map[i][j + 1] == 'W')		// check si celui d'apres est bon
		verif++;
	if (map[i][j - 1] == '1' || map[i][j - 1] == '0' || map[i][j - 1] == 'N'
		|| map[i][j - 1] == 'S' || map[i][j - 1] == 'E' || map[i][j - 1] == 'W')		// check si celui d'avant est bon
		verif++;
	if (map[i + 1][j] == '1' || map[i + 1][j] == '0' || map[i + 1][j] == 'N'
		|| map[i + 1][j] == 'S' || map[i + 1][j] == 'E' || map[i + 1][j] == 'W')		// check si celui d'en dessous est bon
		verif++;
	if (map[i - 1][j] == '1' || map[i - 1][j] == '0' || map[i - 1][j] == 'N'
		|| map[i - 1][j] == 'S' || map[i - 1][j] == 'E' || map[i - 1][j] == 'W')		// check si celui d'au dessus est bon
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
			if (map_edit[i][j] == '0')
				if (is_surrounded(map_edit, i , j) == -1)
					return (-1);
			j++;
		}
		printf("copy[i] =%s\n", map_edit[i]); // checker si entourer de wall, si oui --> devenir 2 (donc est un 0 et est entourer de wall) TODO
		i++;
		j = 0;
	}
	return (1);
}
