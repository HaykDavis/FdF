/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoares <psoares@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 14:18:17 by psoares           #+#    #+#             */
/*   Updated: 2022/04/01 13:49:04 by psoares          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	first_init(t_fdf *data)
{
	data->zoom = 55;
	data->shift_y = 280;
	data->shift_x = 825;
	data->upp = 5;
	data->alpha = 0;
	data->beta = 0;
	data->gamma = 0;
	data->flag = 1;
}

int	deal_key(int key, t_fdf *data)
{
	if (key == ZOOM || key == UNZOOM)
		zoom(key, data);
	if (key == PUSH_UP || key == PUSH_DOWN)
		push(key, data);
	if (key == DO_2D || key == DO_3D || key == ESC)
		do_23d(key, data);
	if (key == SHIFT_UP || key == SHIFT_DOWN || key == SHIFT_RIGHT
		|| key == SHIFT_LEFT)
		shift(key, data);
	if (key == ROTATE_X_PL || key == ROTATE_X_MN || key == ROTATE_Y_PL
		|| key == ROTATE_Y_MN || key == ROTATE_Z_PL || key == ROTATE_Z_MN)
		rotate(key, data);
	draw(data);
	return (0);
}

int	main(int argc, char **argv)
{
	int		len;
	t_fdf	*data;

	len = (int)ft_strlen(argv[1]);
	if (argc != 2 || argv[1][len - 1] != 'f' || argv[1][len - 2] != 'd'
	|| argv[1][len - 3] != 'f' || argv[1][len - 4] != '.')
		error();
	data = malloc(sizeof(t_fdf));
	read_file(argv[1], data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "FdF");
	first_init(data);
	draw(data);
	mlx_hook(data->win_ptr, 2, 0, deal_key, data);
	mlx_hook(data->win_ptr, 17, 0, temp_exit, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
