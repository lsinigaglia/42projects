/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsinigag <lsinigag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 02:18:57 by lsinigag          #+#    #+#             */
/*   Updated: 2023/03/08 21:37:38 by lsinigag         ###   ########.fr       */
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
	y = ((1.5 * pixel_y) / y_axis) - 0.75;
	return (y);
}

int	convert_point_to_number(double point_x, double point_y)
{
	double complex z;
	double complex c;
	int i;

	i = 0;
	z = 0;
	c = point_x + point_y*I;
	while (i++ < 200)
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
	int color;

	if (number == 0)
		return color = create_trgb (0, 0, 0, 0);
	color = create_trgb(0 , 255, 255 - number, 0);
	return (color);
}
// int	main()
// {
// 	int	i;
// 	int	j;
// 	int number;
// 	int color;
// 	double	point_x;
// 	double	point_y;

// 	i = 0;
// 	j = 0;
// 	while (i++ < 1920)
// 	{
// 		while (j++ < 1080)
// 		{
// 			i = 0;
// 			point_x = convert_pixel_X_to_point_x(i, 1980);
// 			point_y = convert_pixel_Y_to_point_y(j, 1080);
// 			printf("y:%f\n", point_y);
// 			printf("x:%f\n", point_x);
// 			number = convert_point_to_number(point_x, point_y);
// 			printf("number: %d\n", number);
// 			color = convert_number_to_color(number);
// 			printf("color:%d", color);
// 		}

// 	}
// }
