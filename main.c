/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gouz <gouz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:34:01 by gouz              #+#    #+#             */
/*   Updated: 2023/08/08 19:26:39 by gouz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/parsing.h"

char	*skip_space(char *str)
{
	int	i;

	i = 0;
	while ((str[i] == ' ' || str[i] == '\t') && str[i])
		i++;
	return (&str[i]);
}

int	check_identifier(char *str, t_parse *data, char *c)
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

void init_identifier(t_parse *data, char **map)
{
	int		j;
	char	*temp;

	temp = NULL;
	j = 0;
	while (j < 6) // to replace
	{
		temp = skip_space(map[j]);
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

void	init_parse(t_parse *data)
{
	data->ceil = NULL;
	data->floor = NULL;
	data->ea_text = NULL;
	data->no_text = NULL;
	data->so_text = NULL;
	data->we_text = NULL;
	data->map = NULL;
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
/* 	if (data->map != NULL)
		free_split(map); */
}

int	verif_beg_struct(t_parse *data)
{
	if (data->ceil == NULL)
		return (output_error(CEIL_ERR));
	if (data->floor == NULL)
		return output_error(FLOOR_ERR);
	if (data->ea_text == NULL)
		return 1;
	if (data->no_text == NULL)
		return 1;
	if (data->so_text == NULL)
		return 1;
	if (data->we_text == NULL)
		return 1;
	return 0;
}

int	main(void)
{
	t_parse	data;
	char *test[] = {"    NO ./coins.xpm		  ",
		"					SO ./coins.xpm             ",
		"                                               WE ./coins.xpm",
		"   EA ./coins.xpm",
		"F 		220,100,0   ",
		"C 					225,30,0    "
	};
	init_parse(&data);
	init_identifier(&data, test);
	if (verif_beg_struct(&data))
	{
		free_parsedata(&data);
		return (1);
	}
	printf("Good\n");
	free_parsedata(&data);
}
