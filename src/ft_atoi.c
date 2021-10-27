/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoares <psoares@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 17:31:37 by psoares           #+#    #+#             */
/*   Updated: 2021/10/27 01:41:46 by psoares          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	point;
	int	n;

	i = 0;
	point = 1;
	n = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			point *= -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		if (n > 214748364 && (str[i + 1] - '0') >= 7)
			return (-1);
		else if (n < -214748364 && (str[i + 1] - '0') >= 8)
			return (0);
		n = 10 * n + point * (str[i] - '0');
		i++;
	}
	return (n);
}
