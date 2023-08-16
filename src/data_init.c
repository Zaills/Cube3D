/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gouz <gouz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 15:31:01 by gouz              #+#    #+#             */
/*   Updated: 2023/08/16 16:51:50 by gouz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/parsing.h"

static char	*skip_space(char *str)
{
	int	i;

	i = 0;
	while ((str[i] == ' ' || str[i] == '\t') && str[i])
		i++;
	return (&str[i]);
}

static int	check_identifier(char *str, t_parse *data, char *c)
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

void	init_identifier(t_parse *data)
{
	int		j;
	char	*temp;

	temp = NULL;
	j = 0;
	while (data->map[j])
	{
		temp = skip_space(data->map[j]);
		if (ft_strncmp(temp, "NO", 2) == 0)
			data->no_text = ft_strtrim(&temp[2], " \t");
		if (ft_strncmp(temp, "SO", 2) == 0)
			data->so_text = ft_strtrim(&temp[2], " \t");
		if (ft_strncmp(temp, "WE", 2) == 0)
			data->we_text = ft_strtrim(&temp[2], " \t");
		if (ft_strncmp(temp, "EA", 2) == 0)
			data->ea_text = ft_strtrim(&temp[2], " \t");
		if (check_identifier(temp, data, "F") == 1)
			data->floor = ft_strtrim(&temp[1], " \t");
		if (check_identifier(temp, data, "C") == 1)
			data->ceil = ft_strtrim(&temp[1], " \t");
		j++;
	}
	d_print_parsedata(data);
}

void	free_parsedata(t_parse *data)
{
	if (data->ceil != NULL)
		free(data->ceil);
	if (data->floor != NULL)
		free(data->floor);
	if (data->ea_text != NULL)
		free(data->ea_text);
	if (data->no_text != NULL)
		free(data->no_text);
	if (data->so_text != NULL)
		free(data->so_text);
	if (data->we_text != NULL)
		free(data->we_text);
	if (data->map != NULL)
		free_cubed(data->map);
}
