/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoares <psoares@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 01:36:49 by psoares           #+#    #+#             */
/*   Updated: 2021/10/27 01:41:33 by psoares          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	my_mlx_pixel_put(t_amg *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->size_line + x * (data->pixel_bits / 8));
	*(unsigned int *)dst = color;
}

void	map_init(t_fdf *data)
{
	data->z = data->z_matrix[(int)data->y][(int)data->x];
	data->z1 = data->z_matrix[(int)data->y1][(int)data->x1];
	data->x1 *= data->zoom;
	data->x *= data->zoom;
	data->y1 *= data->zoom;
	data->y *= data->zoom;
	data->z *= data->upp;
	data->z1 *= data->upp;
	data->color = 0xffffff;
	if (data->z || data->z1)
		data->color = 0xe80c0c;
}

void	do_shift(t_fdf *data)
{
	data->x += data->shift_x;
	data->y += data->shift_y;
	data->x1 += data->shift_x;
	data->y1 += data->shift_y;
}

void	rotate_map(t_fdf *data)
{
	rotate_x(&data->y, &data->z, data->alpha);
	rotate_x(&data->y1, &data->z1, data->alpha);
	rotate_y(&data->x, &data->z, data->beta);
	rotate_y(&data->x1, &data->z1, data->beta);
	rotate_z(&data->x, &data->y, data->gamma);
	rotate_z(&data->x1, &data->y1, data->gamma);
}
