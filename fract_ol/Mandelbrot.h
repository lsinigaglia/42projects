/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsinigag <lsinigag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 02:11:39 by lsinigag          #+#    #+#             */
/*   Updated: 2023/03/21 20:35:11 by lsinigag         ###   ########.fr       */
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
# include "./printf/ft_printf.h"

typedef struct s_cmp{
	double	real;
	double	imag;
}				t_cmp;
typedef struct s_data {
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
	int		color_shift;
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
	t_cmp	c_julia;
}				t_data;
double	convert_pixel_x_to_point_x(t_data *img, int pixel_x);
double	convert_pixel_y_to_point_y(t_data *img, int pixel_y);
double	ft_atof(char *str);
int		render_mandelbrot(t_data *img, double point_x, double point_y);
int		render_julia(t_data *img, double point_x, double point_y);
int		render_newton(t_data *img, double point_x, double point_y);
int		create_trgb(int t, int r, int g, int b);
int		mouse_events(int keycode, int x, int y, t_data *mlx);
int		convert_point_to_number(t_data *img, double point_x, double point_y);
int		key_event(int keycode, t_data *img);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strlen(char *str);
int		convert_point_to_number(t_data *img, double point_x, double point_y);
int		check_parameters(int argc, char **argv);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	add_shade(double dark, int *trgb);
void	get_opposite_color(int *trgb);
void	zoom_in(t_data *img, double zoom, int x, int y);
void	zoom_out(t_data *img, double zoom, int x, int y);
void	render(t_data *img);
void	move(t_data *img, char direction);
void	init(t_data *img);
int		write_checks (int argc, char **argv);

#endif
