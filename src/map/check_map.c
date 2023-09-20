/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorandi <nmorandi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 03:36:06 by gouz              #+#    #+#             */
/*   Updated: 2023/09/20 17:36:46 by nmorandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	get_map(t_parse *data, int i)
{
	if (data->file[i] == NULL)
	{
		printf("Parse error : Invalid map\n");
		return (1);
	}
	while (count_c(data->file[i], ' ') + count_c(data->file[i], '\t')
		== (int)ft_strlen(data->file[i]))
		i++;
	data->map = &data->file[i];
	return (-1);
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
			printf("Parse error : Invalid symbol : %c\n", line[i]);
			return (-2);
		}
		if (line[i] == 'N' || line[i] == 'W'
			|| line[i] == 'S' || line[i] == 'E')
			spawn++;
		if (spawn > 1)
			return (-1);
		i++;
	}
	return (1);
}

static int	check_emptyline(t_parse *data)
{
	int		i;
	char	*temp;
	int		stop;

	stop = 0;
	i = -1;
	while (data->map[++i])
	{
		temp = skip_space(data->map[i]);
		if (ft_strlen(temp) == 0)
			stop = 1;
		else if (stop == 1)
			return (-1);
	}
	return (1);
}

int	check_map(t_parse *data)
{
	int			i;
	int			ret;

	i = 0;
	while (data->map[i])
	{
		ret = check_line(data->map[i], 0);
		if (ret == -1 || ret == -2)
		{
			if (ret == -1)
				printf("Parse error : Multiple spawn\n");
			return (-1);
		}
		i++;
	}
	if (check_line(data->map[i - 1], 1) == -1)
	{
		printf("Parse error : No spawn\n");
		return (-1);
	}
	if (check_closed(data) == -1 || check_emptyline(data) == -1)
		return (-1);
	return (1);
}
