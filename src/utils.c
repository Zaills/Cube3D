/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmorandi <nmorandi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:19:00 by gouz              #+#    #+#             */
/*   Updated: 2023/08/21 18:20:52 by nmorandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/parsing.h"

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
