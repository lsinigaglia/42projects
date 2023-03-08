/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsinigag <lsinigag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 02:11:39 by lsinigag          #+#    #+#             */
/*   Updated: 2023/03/08 03:10:25 by lsinigag         ###   ########.fr       */
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

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		create_trgb(int t, int r, int g, int b);
void	add_shade (double dark, int *trgb);
void	get_opposite_color (int *trgb);
double	convert_pixel_X_to_point_x(int pixel_x, int x_axis);
double	convert_pixel_Y_to_point_y(int pixel_y, int y_axis);


#endif
