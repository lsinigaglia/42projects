/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsinigag <lsinigag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 02:11:39 by lsinigag          #+#    #+#             */
/*   Updated: 2023/03/14 20:36:13 by lsinigag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANDELBROT_H
# define MANDELBROT_H
# include "./mlx/mlx.h"
# include <stdio.h>
# include <mlx.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_cmp{
	double	real;
	double	imag;
}				t_cmp;
typedef struct	s_data {
	void	*img;
	void	*mlx;
	void	*win;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		set;
	int		x_axis;
	int		y_axis;
	double	point_x;
	double	point_y;
	double	x_axis_plane_max;
	double	y_axis_plane_max;
	double	x_axis_plane_min;
	double	y_axis_plane_min;
	double	x_axis_plane_total;
	double	y_axis_plane_total;
	double	x_move;
	double	y_move;
	t_cmp	comple;
}				t_data;
double  convert_pixel_X_to_point_x(t_data *img, int pixel_x);
double	convert_pixel_Y_to_point_y(t_data *img, int pixel_y);
double	ft_atof(char *str);
int		create_trgb(int t, int r, int g, int b);
int		convert_number_to_color(int);
int		mouse_events(int keycode, int x, int y, t_data *mlx);
int		convert_point_to_number(t_data *img, double point_x, double point_y);
int		key_event(int keycode, t_data *img);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strlen(char *str);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	add_shade (double dark, int *trgb);
void	get_opposite_color (int *trgb);
void	zoom_in(t_data *img, double zoom, int x, int y);
void	zoom_out(t_data *img, double zoom, int x, int y);
void	render (t_data *img);
void	move(t_data *img, char direction);



#endif
