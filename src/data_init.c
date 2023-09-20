/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorandi <nmorandi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 15:31:01 by gouz              #+#    #+#             */
/*   Updated: 2023/09/20 17:37:40 by nmorandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	check_identifier(char *str, char *c)
{
	char	*temp;
	int		i;

	i = 0;
	if (ft_strncmp(str, c, 1) == 0)
	{
		temp = skip_space(&str[1]);
		while (temp[i])
		{
			if (ft_isalpha(temp[i]) && temp[i] != ',')
				return (-1);
			i++;
		}
	}
	else
		return (-1);
	return (1);
}

static int	check_entry(t_parse *data)
{
	int	entry;

	entry = 0;
	if (data->ceil != NULL)
		entry++;
	if (data->floor != NULL)
		entry++;
	if (data->ea_text != NULL)
		entry++;
	if (data->no_text != NULL)
		entry++;
	if (data->so_text != NULL)
		entry++;
	if (data->we_text != NULL)
		entry++;
	return (entry);
}

static int	try_get_texture(char *temp, t_parse *data)
{
	if (ft_strncmp(temp, "NO", 2) == 0)
	{
		data->no_text = ft_strtrim(&temp[2], " \t");
		return (1);
	}
	else if (ft_strncmp(temp, "SO", 2) == 0)
	{
		data->so_text = ft_strtrim(&temp[2], " \t");
		return (1);
	}
	else if (ft_strncmp(temp, "WE", 2) == 0)
	{
		data->we_text = ft_strtrim(&temp[2], " \t");
		return (1);
	}
	else if (ft_strncmp(temp, "EA", 2) == 0)
	{
		data->ea_text = ft_strtrim(&temp[2], " \t");
		return (1);
	}
	return (-1);
}

int	init_identifier(t_parse *data)
{
	int		j;
	char	*temp;

	temp = NULL;
	j = -1;
	while (data->file[++j] && check_entry(data) != 6)
	{
		temp = skip_space(data->file[j]);
		if (try_get_texture(temp, data) == 1)
			continue ;
		if (check_identifier(temp, "F") == 1)
			data->floor = ft_strtrim(&temp[1], " \t");
		else if (check_identifier(temp, "C") == 1)
			data->ceil = ft_strtrim(&temp[1], " \t");
		else if (count_c(temp, ' ') + count_c(temp, '\t')
			!= (int)ft_strlen(temp))
			return (output_error(ORDER_SYMB));
	}
	return (get_map(data, j));
}

int	precheck_parse(t_parse *data)
{
	int		i;
	int		count;
	char	*temp;

	count = 0;
	i = -1;
	while (data->file[++i])
	{
		temp = skip_space(data->file[i]);
		if (ft_strncmp(temp, "NO", 2) == 0)
			count++;
		else if (ft_strncmp(temp, "SO", 2) == 0)
			count++;
		else if (ft_strncmp(temp, "WE", 2) == 0)
			count++;
		else if (ft_strncmp(temp, "EA", 2) == 0)
			count++;
		else if (check_identifier(temp, "C") == 1)
			count++;
		else if (check_identifier(temp, "F") == 1)
			count++;
	}
	if (count != 6)
		return (-1);
	return (1);
}
