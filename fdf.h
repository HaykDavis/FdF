/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoares <psoares@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 01:19:24 by psoares           #+#    #+#             */
/*   Updated: 2021/10/27 01:50:35 by psoares          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include "mlx/mlx.h"
# include "gnl/get_next_line.h"

# define WIDTH			1500.0
# define HEIGHT			1500.0

# define SHIFT_UP		126
# define SHIFT_DOWN		125
# define SHIFT_LEFT		123
# define SHIFT_RIGHT	124
# define ZOOM			6
# define UNZOOM			7
# define PUSH_UP		8
# define PUSH_DOWN		9
# define ROTATE_X_PL	32
# define ROTATE_X_MN	34
# define ROTATE_Y_PL	38
# define ROTATE_Y_MN	40
# define ROTATE_Z_PL	45
# define ROTATE_Z_MN	46
# define DO_3D			20
# define DO_2D			19
# define ESC			53

typedef struct s_amg
{
	void		*image;
	char		*addr;
	int			pixel_bits;
	int			size_line;
	int			endian;
}				t_amg;

typedef struct s_fdf
{
	int		width;
	int		height;
	int		**z_matrix;
	int		zoom;
	int		color;
	int		shift_x;
	int		shift_y;
	float	upp;
	float	alpha;
	float	beta;
	float	gamma;
	int		flag;
	int		z;
	int		z1;
	float	x;
	float	y;
	float	x1;
	float	y1;

	void	*mlx_ptr;
	void	*win_ptr;
	t_amg	img;
}				t_fdf;

float	mod(float i);
void	brew(t_fdf data);
void	draw(t_fdf *data);
void	map_init(t_fdf *data);
void	do_shift(t_fdf *data);
void	rotate_map(t_fdf *data);
int		ft_atoi(const char *str);
void	do_isometry(t_fdf *data);
void	push(int key, t_fdf *data);
float	max_step(float a, float b);
void	zoom(int key, t_fdf *data);
void	shift(int key, t_fdf *data);
void	rotate(int key, t_fdf *data);
void	do_23d(int key, t_fdf *data);
int		temp_exit(int key, t_fdf *data);
char	**ft_split(char const *s, char c);
void	isometric(float *x, float *y, int z);
void	rotate_y(float *x, int *z, float beta);
void	read_file(char *file_name, t_fdf *data);
void	rotate_x(float *y, int *z, float alpha);
void	rotate_z(float *x, float *y, float gamma);
void	my_mlx_pixel_put(t_amg *data, int x, int y, int color);

#endif