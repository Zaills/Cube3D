/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gouz <gouz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:34:01 by gouz              #+#    #+#             */
/*   Updated: 2023/07/31 21:22:49 by gouz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/parsing.h"
#include "stdio.h"

char	*skip_space(char *str)
{
	int	i;

	i = 0;
	while ((str[i] == ' ' || str[i] == '\t') && str[i])
		i++;
	return (&str[i]);
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
		if (ft_strncmp(temp, "F", 1) == 0)
			data->floor = ft_strtrim(&temp[1], " \t");
		if (ft_strncmp(temp, "C", 1) == 0)
			data->ceil = ft_strtrim(&temp[1], " \t");
		j++;
	}
/* 	printf("no=%s\n", data->no_text);
	printf("so=%s\n", data->so_text);
	printf("we=%s\n", data->we_text);
	printf("ea=%s\n", data->ea_text);
	printf("floor=%s\n", data->floor);
	printf("ceil=%s\n", data->ceil); */
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
	if (data->ea_text)
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

int	main(void)
{
	t_parse	data;
	char *test[] = {"    NO ./coins.xpm		  ",
		"					SO ./coins.xpm             ",
		"                                               WE ./coins.xpm",
		"   EA ./coins.xpm",
		"F 		220,100,0    ",
		"C 					225,30,0    "
	};
	init_parse(&data);
	init_identifier(&data, test);
	free_parsedata(&data);
}
