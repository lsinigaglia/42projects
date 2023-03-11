/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsinigag <lsinigag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 02:18:57 by lsinigag          #+#    #+#             */
/*   Updated: 2023/03/11 21:45:05 by lsinigag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Mandelbrot.h"

/*Converti i pixel nel corrispettivo punto del piano complesso */
double	convert_pixel_X_to_point_x(t_data *img, int pixel_x)
{
	double	x;


	// x : 3 = pixel_x : x_axis
	// x = ((img->x_axis_plane_max * pixel_x) / img->x_axis) + img->x_move - (img->x_axis_plane_max / 2);
	x = ((img->x_axis_plane_total * pixel_x) / img->x_axis) + (img->x_axis_plane_min) + img->x_move;

	return (x);
}


double	convert_pixel_Y_to_point_y(t_data *img, int pixel_y)
{
	double	y;

	// y : 4 = pixel_x : x_axis
	y = ((img->y_axis_plane_total * pixel_y) / img->y_axis)  + (img->y_axis_plane_min) - img->y_move;
	return (y);
}

// double	convert_pixel_Y_to_point_y(int pixel_y, int y_axis)
// {
// 	double	y;
// 	// y : 4 = pixel_x : x_axis
// 	y = ((3.0 * pixel_y) / y_axis) - 1.5;
// 	return (y);
// }

int	convert_point_to_number(double point_x, double point_y)
{
	double complex z;
	double complex c;
	int i;

	i = 0;
	z = 0;
	c = point_x + point_y*I;
	while (i++ < 1000)
	{
		z = z * z + c;
		// printf("%i Z value: %f\n", i, creal(z));
		if (cabs(z) >= 2)
			return (i);
	}
	return (0);
}


int	convert_number_to_color(int number)
{
	int	color;

	if (number == 0)
		return color = create_trgb (0, 0, 0, 0);
	// color = create_trgb(0 , 0 + number/4, 255 - (number/4), 0);

	if (number % 4 == 0)
		color = create_trgb(0, 0 , 255, 0);
	if (number % 4 == 1)
		color = create_trgb (0, 0, 0, 255);
	if (number % 4 == 2)
		color = create_trgb(0, 255, 0, 0);
	if (number % 4 == 3)
		color = create_trgb(0, 0, 255, 255);

	return (color);
}

// int	ft_close(int keycode, t_data *img)
// {
// 	if (keycode == 53)
// 	{
// 		mlx_destroy_window(img->mlx, img->win);
// 		exit(0);
// 	}
// 	return (0);
// }


void render (t_data *img)
{
	int	i;
	int	j;
	int	color;
	int	number;

	i = 0;
	j = 0;
	while (i < 900)
	{
		while (j++ < 900)
		{
			img->point_x = convert_pixel_X_to_point_x(img, i);
			img->point_y = convert_pixel_Y_to_point_y(img, j);
			number = convert_point_to_number(img->point_x, img->point_y);
			color = convert_number_to_color(number);
			my_mlx_pixel_put(img, i, j, color);
			j++;
		}
		j = 0;
		i++;
	}
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
}
