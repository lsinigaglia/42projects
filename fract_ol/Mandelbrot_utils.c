/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsinigag <lsinigag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 02:18:57 by lsinigag          #+#    #+#             */
/*   Updated: 2023/03/14 20:52:05 by lsinigag         ###   ########.fr       */
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

// int	convert_point_to_number(t_data *img, double point_x, double point_y)
// {
// 	double complex z;
// 	double complex c;
// 	int i;

// 	i = 0;
// 	z = 0;
// 	c = point_x + point_y*I;
// 	if (img->set == 1)
// 	{
// 		while (i++ < 1000)
// 		{
// 			z = z * z + c;
// 			// printf("%i Z value: %f\n", i, creal(z));
// 			if (cabs(z) >= 2)
// 				return (i);
// 		}
// 		return 0;
// 	}
// 	if (img->set == 2)
// 	{
// 		z = point_x + point_y*I;
// 		c = 0.5 + 0.6*I;
// 		// c = 0;
// 		while (i++ < 500)
// 		{
// 			z = (z * z) + c;
// 			// printf("%i Z value: %f\n", i, creal(z));
// 			if (cabs(z) >= 2)
// 				return (i);
// 		}
// 	return (0);
// 	}
// 	return (0);
// }
int	convert_point_to_number(t_data *img, double point_x, double point_y)
{
	int i;

	i = 0;
	if (img->set == 1)
	{
		t_cmp z;
		t_cmp c;
		double temp;
		z.real = 0;
		z.imag = 0;
		c.real = point_x;
		c.imag = point_y;
		while (i++ < 1000)
		{
			temp = z.real;
			z.real = (z.real) * (z.real) - (z.imag * z.imag) + c.real;
			z.imag = (2 * (temp * z.imag)) + c.imag;
			if (sqrt(z.real * z.real + z.imag * z.imag )>= 2)
				return (i);
		}
		return 0;
	}
	if (img->set == 2) /* julia */
	{
		t_cmp z;
		t_cmp c;
		double temp;
		z.real = point_x;
		z.imag = point_y;
		while (i++ < 1000)
		{
			temp = z.real;
			z.real = (z.real) * (z.real) - (z.imag * z.imag) + img->comple.real;
			z.imag = (2 * (temp * z.imag)) + img->comple.imag;
			if (sqrt(z.real * z.real + z.imag * z.imag) >= 2)
				return (i);
		}
		return 0;
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
			number = convert_point_to_number(img, img->point_x, img->point_y);
			color = convert_number_to_color(number);
			my_mlx_pixel_put(img, i, j, color);
			j++;
		}
		j = 0;
		i++;
	}
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

		ptr1 = (unsigned char *) s1;

	ptr2 = (unsigned char *) s2;
	i = 0;
	while ((ptr1[i] != '\0' || ptr2[i] != '\0') && i < n)
	{
		if (ptr1[i] > ptr2[i])
		{
			return (1);
		}
		else if (ptr1[i] < ptr2[i])
		{
			return (-1);
		}
		i++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}
double	ft_atof(char *str)
{
	int		i;
	int		sign;
	double	res;
	int		floater;

	i = 0;
	sign = 1;
	res = 0;
	floater = 1;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == 32)
		i++;
	if (str[i] == '+')
			i++;
	else if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') || str[i] == '.')
	{
		res = str[i] - 48 + (res * 10);
		i++;
		if (str[i] == '.')
		{
			floater = 10;
			floater = pow(floater, (ft_strlen(str + i) - 1));
			i++;
		}
	}
	res *= (double)1/floater;
	return (res * sign);
}

