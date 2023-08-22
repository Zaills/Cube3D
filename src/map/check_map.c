/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorandi <nmorandi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 03:36:06 by gouz              #+#    #+#             */
/*   Updated: 2023/08/22 15:48:11 by nmorandi         ###   ########.fr       */
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
