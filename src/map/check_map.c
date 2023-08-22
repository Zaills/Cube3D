/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorandi <nmorandi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 03:36:06 by gouz              #+#    #+#             */
/*   Updated: 2023/08/22 15:24:51 by nmorandi         ###   ########.fr       */
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

static int	check_line(char *line, int check_spawn)
{
	int			i;
	static int	spawn = 0;

	i = 0;
	if (check_spawn == 1 && spawn != 1)
		return (-1);
	else if (check_spawn == 1)
		return (1);
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '0' && line[i] != '1' && line[i] != 'N'
			&& line[i] != 'W' && line[i] != 'S' && line[i] != 'E')
		{
			printf("INVALID LINE cause : %c\n", line[i]);
			return (-1);
		}
		if (line[i] == 'N' || line[i] == 'W' || line[i] == 'S' || line[i] == 'E')
			spawn++;
		if (spawn > 1)
			return (-1);
		i++;
		printf("spawn=%d\n",spawn);
	}
	return (1);
}

static char** copy_map(char **map)
{
	char **copy;

	int i;

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

static int	check_closed(t_parse *data)
{
	int	i;
	char **map_edit;

	map_edit = copy_map(data->map);
	if (!map_edit)
		return (-1);
	i = 0;
	while (map_edit[i])
	{
		printf("copy[i] =%s\n", map_edit[i]); // checker si entourer de wall, si oui --> devenir 2 (donc est un 0 et est entourer de wall) TODO
		i++;
	}
	return (1);
}

int	check_map(t_parse *data) // wrong symbol + multiple spawn fait
{
	int			i;
	i = 0;
	printf("|| PRINTING THE MAP ||\n");
	while (data->map[i])
	{
		printf("%s\n",data->map[i]);
		if (check_line(data->map[i], 0) == -1)
			return (-1);
		i++;
	}
	if (check_line(data->map[i-1], 1) == -1)
		return (-1);
	if (check_closed(data) == -1) //need check spawn valid ( pas hors map) TODO
	{
		printf("map isn't closed\n");
	}

	printf("|| END OF MAP (everything is good) ||\n");
	return (1);
}
