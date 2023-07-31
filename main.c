/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gouz <gouz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:34:01 by gouz              #+#    #+#             */
/*   Updated: 2023/07/31 17:13:44 by gouz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/parsing.h"
#include "stdio.h"

void init_texture(t_parse *data, char **map)
{
	int	i;

	i = 0;
	while (map[0][i] == ' ')
		i++;
	if (ft_strncmp(&map[0][i], "NO", 2) == 0 && map[0][i+2] == ' ')
		data->no_text = ft_strjoin("", &map[0][i]);
	printf("%s\n",data->no_text);
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

int	main(void)
{
	t_parse	data;
	char *test[] = {"NO ./coins.xpm",
		"SO ./coins.xpm",
		"WE ./coins.xpm",
		"EA ./coins.xpm"
	};
	init_parse(&data);
	init_texture(&data, test);
	printf("Hello\n");
}
