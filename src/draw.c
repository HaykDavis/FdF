/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoares <psoares@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 17:23:53 by psoares           #+#    #+#             */
/*   Updated: 2021/10/27 01:44:25 by psoares          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	brew(t_fdf data)
{
	int		max;
	float	x_step;
	float	y_step;

	map_init(&data);
	rotate_map(&data);
	do_isometry(&data);
	do_shift(&data);
	x_step = data.x1 - data.x;
	y_step = data.y1 - data.y;
	max = max_step(mod(x_step), mod(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(data.x - data.x1) || (int)(data.y - data.y1))
	{
		if (data.x < WIDTH && data.x >= 0.0
			&& data.y < HEIGHT && data.y >= 0.0)
			my_mlx_pixel_put(&data.img, data.x, data.y, data.color);
		data.x += x_step;
		data.y += y_step;
	}
}

void	do_init_image(t_fdf *data)
{
	if (data->img.image)
		mlx_destroy_image(data->mlx_ptr, data->img.image);
	data->img.image = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.image, &data->img.pixel_bits,
			&data->img.size_line, &data->img.endian);
}

void	draw(t_fdf *data)
{
	do_init_image(data);
	data->y = 0;
	while (data->y < data->height)
	{
		data->x = 0;
		while (data->x < data->width)
		{
			if (data->x < data->width - 1)
			{
				data->x1 = data->x + 1;
				data->y1 = data->y;
				brew(*data);
			}
			if (data->y < data->height - 1)
			{
				data->x1 = data->x;
				data->y1 = data->y + 1;
				brew(*data);
			}
			data->x++;
		}
		data->y++;
	}
	mlx_put_image_to_window(data->mlx_ptr,
		data->win_ptr, data->img.image, 0, 0);
}
