/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_closed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorandi <nmorandi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:43:56 by nmorandi          #+#    #+#             */
/*   Updated: 2023/08/31 14:21:57 by nmorandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static char** copy_map(char **map)
{
	char	**copy;
	int		i;

	i = 0;
	while (map[i])
		i++;
	copy = malloc(sizeof(char *) * i);
	if (!copy)
		return (NULL);
	i = -1;
	while (map[++i])
		copy[i] = ft_strdup(map[i]);
	return (copy);
}

static int	is_surrounded(char **map, int i, int j)// take 0 and check if surrounded
{
	int top=0;
	int	tempi;
	tempi = i;
	while (i >= 0)
	{
		printf("checking if %c is 1, i is %d\n", map[i][j], i); // need check avec la len des lignes pour pas target du vide
		if (map[i][j] == '1' || map[i][j] == '2')
			top = 1;
		i--;
	}
	if (top == 0)
		return (-1);
	map[tempi][j] = '1';
	return (1);
}

int	check_closed(t_parse *data)
{
	int		i;
	int		j;
	char	**map_edit;

	return (1);
	map_edit = copy_map(data->map);
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
					return (-1); // need free copy_map
			j++;
		}
		printf("copy[i] =%s\n", map_edit[i]); // checker si entourer de wall, si oui --> devenir 2 (donc est un 0 et est entourer de wall) TODO
		i++;
		j = 0;
	}
	return (1);
}
