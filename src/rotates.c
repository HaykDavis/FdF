/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoares <psoares@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 01:36:36 by psoares           #+#    #+#             */
/*   Updated: 2021/10/27 12:06:19 by psoares          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.9);
	*y = (*x + *y) * sin(0.9) - z;
}

void	rotate_x(float *y, int *z, float alpha)
{
	int	prev_y;

	prev_y = *y;
	*y = prev_y * cos(alpha) + *z * sin(alpha);
	*z = -prev_y * sin(alpha) + *z * cos(alpha);
}

void	rotate_y(float *x, int *z, float beta)
{
	int	prev_x;

	prev_x = *x;
	*x = prev_x * cos(beta) - *z * sin(beta);
	*z = prev_x * sin(beta) + *z * cos(beta);
}

void	rotate_z(float *x, float *y, float gamma)
{
	int	prev_x;
	int	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = prev_x * cos(gamma) + prev_y * sin(gamma);
	*y = -prev_x * sin(gamma) + prev_y * cos(gamma);
}

void	do_isometry(t_fdf *data)
{
	if (data->flag == 1)
	{
		isometric(&data->x, &data->y, data->z);
		isometric(&data->x1, &data->y1, data->z1);
	}
}
