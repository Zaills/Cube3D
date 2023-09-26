/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gouz <gouz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:19:00 by gouz              #+#    #+#             */
/*   Updated: 2023/09/25 20:52:58 by gouz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	get_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (!ft_strlen(map[i]))
			return (i);
		i++;
	}
	return (i);
}

int	output_error(int code)
{
	if (code == FLOOR_ERR)
		printf("Parse error : invalid floor value\n");
	if (code == CEIL_ERR)
		printf("Parse error : invalid ceil value\n");
	if (code == ORDER_SYMB)
		printf("Parse error : identfier order and / or incorrect identfier\n");
	if (code == MAP_ERR)
		printf("Parse error : Incorrect map\n");
	return (1);
}

int	count_c(char *str, char c)
{
	int	i;
	int	value;

	i = 0;
	value = 0;
	while (str[i])
	{
		if (str[i] == c)
			value++;
		i++;
	}
	return (value);
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
	close_map(data);
}

char	*skip_space(char *str)
{
	int	i;

	i = 0;
	while ((str[i] == ' ' || str[i] == '\t') && str[i])
		i++;
	return (&str[i]);
}
