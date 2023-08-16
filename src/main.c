/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gouz <gouz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:34:01 by gouz              #+#    #+#             */
/*   Updated: 2023/08/16 16:42:38 by gouz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/parsing.h"

static void	init_parse(t_parse *data)
{
	data->ceil = NULL;
	data->floor = NULL;
	data->ea_text = NULL;
	data->no_text = NULL;
	data->so_text = NULL;
	data->we_text = NULL;
	data->map = NULL;
}

static int	check_value_color(t_parse *data)
{
	int value[3];
	value[0] = ft_atoi(data->ceil);
	printf("missing last value , data=%s\n",&ft_strrchr(data->ceil, ',')[2]);
	value[1] = ft_atoi(&ft_strchr(data->ceil, ',')[1]);
	value[2] = ft_atoi(&ft_strrchr(data->ceil, ',')[1]);
	printf("value=%d %d %d\n",value[0],value[1],value[2]);
	return (1);
}

int	verif_beg_struct(t_parse *data)
{
	if (data->ceil == NULL || check_value_color(data) == -1)
		return (output_error(CEIL_ERR));
	if (data->floor == NULL || check_value_color(data) == -1)
		return (output_error(FLOOR_ERR));
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

int	main(int ac, char **av)
{
	t_parse	data;

	init_parse(&data);
	data.map = open_map(ac, av);
	if (!data.map)
		return (0);
	init_identifier(&data);
	if (verif_beg_struct(&data))
	{
		free_parsedata(&data);
		return (1);
	}
	printf("Good\n");
	free_parsedata(&data);
}
