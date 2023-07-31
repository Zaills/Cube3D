/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:59:39 by marvin            #+#    #+#             */
/*   Updated: 2023/07/31 16:59:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "../libft/libft.h"

char *open_file(char *file)
{
	int		fd;
	int		ret;
	char	str[10];
	char	*out;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	ret = read(fd, str, 10);
	if (ret == -1)
		return (0);
	out = ft_calloc(sizeof(char) * 1);
	str[ret] = 0;
	out = ft_strjoin(out, str);
	while (str[0])
	{
		ret = read(fd, str, 10);
		if (!ret)
			return (out);
		str[ret] = 0;
		out = ft_strjoin(out, str);
	}
	return (out);

}

int	verif_cub(char *str)
{
	int		i;
	int		end;
	char	*ber;

	ber = ".ber";
	i = 0;
	if (ft_strlen(str) < 4)
		return (0);
	end = ft_strlen(str) - 4;
	if (str[end - 1] == '/' || str[0] == '.')
		return (0);
	while (str[end + i] && ber[i])
	{
		if (str[end + i] != ber[i])
			return (0);
		i++;
	}
	return (1);
}

char	*open_map(int ac, char **av)
{
	char	*cub;

	if (ac != 2 )
	{
		printf("Error\nPut only the map\n");
		return (0);
	}
	if (!verif_cub(av[1]))
	{
		printf("Error\nName not valid");
		return (0);
	}
	cub = open_file(av[1]);
	if (!cub)
	{
		printf("Error\nCan not open the cub");
		return (0);
	}
	return (cub);
}
