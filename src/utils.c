/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:19:00 by gouz              #+#    #+#             */
/*   Updated: 2023/08/11 16:14:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/parsing.h"

int output_error(int code)
{
	if (code == FLOOR_ERR)
		printf("Parse error : invalid floor value\n");
	if (code == CEIL_ERR)
		printf("Parse error : invalid ceil value\n");
	return (1);
}
