/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsinigag <lsinigag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 02:11:39 by lsinigag          #+#    #+#             */
/*   Updated: 2023/03/11 21:40:20 by lsinigag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANDELBROT_H
# define MANDELBROT_H
# include "./mlx/mlx.h"
# include <stdio.h>
# include <mlx.h>
# include <math.h>
# include <complex.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx;
	void	*win;
	double	point_x;
	double	point_y;
	int		x_axis;
	int		y_axis;
	double	x_axis_plane_max;
	double	y_axis_plane_max;
	double	x_axis_plane_min;
	double	y_axis_plane_min;
	double	x_axis_plane_total;
	double	y_axis_plane_total;
	double	x_move;
	double	y_move;
}				t_data;
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		create_trgb(int t, int r, int g, int b);
void	add_shade (double dark, int *trgb);
void	get_opposite_color (int *trgb);
double  convert_pixel_X_to_point_x(t_data *img, int pixel_x);
double	convert_pixel_Y_to_point_y(t_data *img, int pixel_y);
int		convert_number_to_color(int);
int		convert_point_to_number(double point_x, double point_y);
// int		ft_close(int keycode, t_data *img);
void	zoom(t_data *img, double zoom, int x, int y);
int		mouse_events(int keycode, int x, int y, t_data *mlx);
void	render (t_data *img);
void	move(t_data *img, char direction);
int		key_event(int keycode, t_data *img);



#endif
