/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:52:42 by marvin            #+#    #+#             */
/*   Updated: 2023/09/15 14:52:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	close_map(t_parse *data)
{
	int	i;

	i = 0;
	while (data->file[i])
	{
		free(data->file[i]);
		i++;
	}
	free(data->file);
}
