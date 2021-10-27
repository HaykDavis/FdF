/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoares <psoares@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 01:35:15 by psoares           #+#    #+#             */
/*   Updated: 2021/10/27 01:41:52 by psoares          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	push(int key, t_fdf *data)
{
	if (key == PUSH_UP)
		data->upp += 1;
	if (key == PUSH_DOWN)
		data->upp -= 1;
}

void	shift(int key, t_fdf *data)
{
	if (key == SHIFT_UP)
		data->shift_y -= 10;
	if (key == SHIFT_DOWN)
		data->shift_y += 10;
	if (key == SHIFT_RIGHT)
		data->shift_x += 10;
	if (key == SHIFT_LEFT)
		data->shift_x -= 10;
}

void	zoom(int key, t_fdf *data)
{
	if (key == ZOOM)
		data->zoom += 1;
	if (key == UNZOOM)
		data->zoom -= 1;
}

void	do_23d(int key, t_fdf *data)
{
	if (key == DO_2D)
		data->flag = 0;
	if (key == DO_3D)
		data->flag = 1;
	if (key == ESC)
		exit(0);
}

void	rotate(int key, t_fdf *data)
{
	if (key == PUSH_UP)
		data->upp += 1;
	if (key == PUSH_DOWN)
		data->upp -= 1;
	if (key == ROTATE_X_PL)
		data->alpha -= 0.1;
	if (key == ROTATE_X_MN)
		data->alpha += 0.1;
	if (key == ROTATE_Y_PL)
		data->beta -= 0.1;
	if (key == ROTATE_Y_MN)
		data->beta += 0.1;
	if (key == ROTATE_Z_PL)
		data->gamma -= 0.1;
	if (key == ROTATE_Z_MN)
		data->gamma += 0.1;
}
