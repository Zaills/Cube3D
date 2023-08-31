/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_to_cubed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorandi <nmorandi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 16:12:02 by marvin            #+#    #+#             */
/*   Updated: 2023/08/31 14:05:21 by nmorandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "parsing.h"

int	get_num_line(char *cub)
{
	int	i;
	int	out;

	i = 0;
	out = 0;
	while (cub[i])
	{
		if (cub[i] == '\n')
			out++;
		i++;
	}
	return (out);
}

char	*copy_till_n(char *cub)
{
	int		i;
	int		j;
	char	*out;

	i = 0;
	j = 0;
	while (cub[i] != '\n' && cub[i])
		i++;
	out = ft_calloc(sizeof(char), i + 1);
	if (!out)
		return (0);
	i = 0;
	while (cub[i] != '\n' && cub[i])
	{
		out[j] = cub[i];
		i++;
		j++;
	}
	return (out);
}

char	**cub_to_cubed(char *cub)
{
	char	**out;
	int		i;
	int		j;
	int		num;

	i = 0;
	j = 0;
	num = get_num_line(cub) + 1;
	out = ft_calloc(sizeof(char *), num + 1);
	if (!out)
		return (0);
	while (cub[i])
	{
		out[j] = copy_till_n(cub + i);
		i += ft_strlen(out[j]) + 1;
		j++;
	}
	return (out);
}

void	free_cubed(char **cubed)
{
	int	i;

	i = 0;
	while (cubed[i])
	{
		free(cubed[i]);
		i++;
	}
	free(cubed);
}
