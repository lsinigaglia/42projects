/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsinigag <lsinigag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 02:18:57 by lsinigag          #+#    #+#             */
/*   Updated: 2023/03/17 01:44:13 by lsinigag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Mandelbrot.h"

/*Converti i pixel nel corrispettivo punto del piano complesso
x : 3 = pixel_x : x_axis */

int	convert_point_to_number(t_data *img, double point_x, double point_y)
{
	int		i;
	t_cmp	z;
	t_cmp	c;
	double	temp;
	int		result;

	i = 0;
	if (img->set == 1)
	{
		result = render_mandelbrot(img, point_x, point_y);
		return (result);
	}
	if (img->set == 2)
	{
		result = render_julia(img, point_x, point_y);
		return (result);
	}
	return (0);
}

int	render_mandelbrot(t_data *img, double point_x, double point_y)
{
	int		i;
	t_cmp	z;
	t_cmp	c;
	double	temp;

	i = 0;
	z.real = 0;
	z.imag = 0;
	c.real = point_x;
	c.imag = point_y;
	while (i++ < 150)
	{
		temp = z.real;
		z.real = (z.real) * (z.real) - (z.imag * z.imag) + c.real;
		z.imag = (2 * (temp * z.imag)) + c.imag;
		if (sqrt(z.real * z.real + z.imag * z.imag) >= 2)
			return (i);
	}
	return (0);
}

int	render_julia(t_data *img, double point_x, double point_y)
{
	int		i;
	t_cmp	z;
	double	temp;

	i = 0;
	z.real = point_x;
	z.imag = point_y;
	while (i++ < 150)
	{
		temp = z.real;
		z.real = (z.real) * (z.real) - (z.imag * z.imag) + img->c_julia.real;
		z.imag = (2 * (temp * z.imag)) + img->c_julia.imag;
		if (sqrt(z.real * z.real + z.imag * z.imag) >= 2)
			return (i);
	}
	return (0);
}

int	convert_number_to_color(t_data *img, int number)
{
	int	color;

	if (number == 0)
		return (color = create_trgb (0, 0, 0, 0));
	if ((number + img->color_shift) % 4 == 0)
		color = create_trgb (0, 255, 165, 0);
	if ((number + img->color_shift) % 4 == 1)
		color = create_trgb (0, 180, 180, 180);
	if ((number + img->color_shift) % 4 == 2)
		color = create_trgb(0, 200, 200, 200);
	if ((number + img->color_shift) % 4 == 3)
		color = create_trgb(0, 200, 200, 200);
	return (color);
}

void	render(t_data *img)
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
			img->point_x = convert_pixel_x_to_point_x(img, i);
			img->point_y = convert_pixel_y_to_point_y(img, j);
			number = convert_point_to_number(img, img->point_x, img->point_y);
			color = convert_number_to_color(img, number);
			my_mlx_pixel_put(img, i, j, color);
			j++;
		}
		j = 0;
		i++;
	}
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
}
