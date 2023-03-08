/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsinigag <lsinigag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 02:18:57 by lsinigag          #+#    #+#             */
/*   Updated: 2023/03/08 03:39:26 by lsinigag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Mandelbrot.h"

/*Converti i pixel nel corrispettivo punto del piano complesso */
double	convert_pixel_X_to_point_x(int pixel_x, int x_axis)
{
	double	x;
	// x : 3 = pixel_x : x_axis
	x = ((3.0 * pixel_x) / x_axis) - 1.5;
	return (x);
}

double	convert_pixel_Y_to_point_y(int pixel_y, int y_axis)
{
	double	y;
	// y : 4 = pixel_x : x_axis
	y = ((3.0 * pixel_y) / y_axis) - 1.5;
	return (y);
}

int	convert_point_to_number(double point_x, double point_y)
{
	double z;
	int i;

	i = 0;
	z = 0;

	while (i++ < 5)
	{
		z = pow(z, 2) + (point_x + point_y);
		printf("%i Z value: %f\n", i, z);
		if (z >= 100)
			break ;
	}
	return (0);
}

int	main()
{
	int	i;
	int	j;
	int number;
	double	point_x;
	double	point_y;

	i = 168;
	j = 180;
	// while (i++ < 1920)
	// {
	// 	while (j++ < 1080)
	// 	{
	// 		i = 0;
			point_x = convert_pixel_X_to_point_x(i, 300);
			point_y = convert_pixel_Y_to_point_y(j, 300);
			printf("y:%f\n", point_y);
			printf("x:%f\n", point_x);
			number = convert_point_to_number(point_x, point_y);
			printf("%d", number);
	// 		print_color(number);
	// 	}

	// }
}
