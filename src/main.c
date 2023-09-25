/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gouz <gouz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:34:01 by gouz              #+#    #+#             */
/*   Updated: 2023/09/25 20:54:20 by gouz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "render.h"

static void	init_parse(t_parse *data)
{
	data->ceil = NULL;
	data->floor = NULL;
	data->ea_text = NULL;
	data->no_text = NULL;
	data->so_text = NULL;
	data->we_text = NULL;
	data->file = NULL;
	data->map = NULL;
}

static int	check_color_value(char *str_rgb)
{
	int	value[3];
	int	i;

	i = 0;
	if (str_rgb[0] == ',' || ft_isdigit(ft_strrchr(str_rgb, ',')[1]) == 0
		|| count_c(str_rgb, ',') != 2)
		return (-1);
	value[0] = ft_atoi(str_rgb);
	value[1] = ft_atoi(&ft_strchr(str_rgb, ',')[1]);
	value[2] = ft_atoi(&ft_strrchr(str_rgb, ',')[1]);
	while (i < 3)
	{
		if (value[i] > 255 || value[i] < 0)
			return (-1);
		i++;
	}
	return (1);
}

int	verif_beg_struct(t_parse *data)
{
	if (data->ceil == NULL || check_color_value(data->ceil) == -1)
		return (output_error(CEIL_ERR));
	if (data->floor == NULL || check_color_value(data->floor) == -1)
		return (output_error(FLOOR_ERR));
	if (data->ea_text == NULL)
		return (1);
	if (data->no_text == NULL)
		return (1);
	if (data->so_text == NULL)
		return (1);
	if (data->we_text == NULL)
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_parse	data;

	init_parse(&data);
	data.file = open_map(ac, av);
	if (!data.file)
		return (0);
	if (precheck_parse(&data) == -1)
	{
		free_parsedata(&data);
		printf("Parse error : incorrect identifier\n");
		return (1);
	}
	if (init_identifier(&data) == 1 || verif_beg_struct(&data))
	{
		free_parsedata(&data);
		return (1);
	}
	if (check_map(&data) == -1)
	{
		free_parsedata(&data);
		return (output_error(MAP_ERR));
	}
	render(&data);
	free_parsedata(&data);
}
