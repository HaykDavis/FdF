/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoares <psoares@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 01:36:59 by psoares           #+#    #+#             */
/*   Updated: 2021/10/27 16:26:36 by psoares          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

float	mod(float i)
{
	if (i < 0)
		return (-i);
	return (i);
}

float	max_step(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

int	temp_exit(int key)
{
	(void) key;
	exit(0);
	return (0);
}

void	error(void)
{
	write(1, "Error\n", 6);
	exit(0);
}
