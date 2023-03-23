/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsinigag <lsinigag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 02:18:57 by lsinigag          #+#    #+#             */
/*   Updated: 2023/03/23 18:47:01 by lsinigag         ###   ########.fr       */
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
	if (img->set == 3)
	{
		result = render_newton(img, point_x, point_y);
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
	while (i++ < 500)
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

int	render_newton(t_data *img, double point_x, double point_y)
{
	int		i;
	t_cmp	z;

	i = 0;
	z.real = point_x;
	z.imag = point_y;
	return (make_newton(img, z, i));
}

int	make_newton(t_data *img, t_cmp z, int i)
{
	while (i++ < 300)
	{
		img->temp_real = z.real;
		img->temp_imag = z.imag;
		img->fz.real = (z.real * z.real * z.real)
			- (3 * z.real * z.imag * z.imag) - 1;
		img->fz.imag = (3 * z.real * z.real * z.imag)
			- (z.imag * z.imag * z.imag);
		img->dfz.real = (3 * z.real * z.real) - (3 * z.imag * z.imag);
		img->dfz.imag = 6 * z.real * z.imag;
		img->denominator = (img->dfz.real * img->dfz.real)
			+ (img->dfz.imag * img->dfz.imag);
		z.real -= (img->fz.real * img->dfz.real + img->fz.imag * img->dfz.imag)
			/ img->denominator;
		z.imag -= (img->fz.imag * img->dfz.real - img->fz.real * img->dfz.imag)
			/ img->denominator;
		img->diff = sqrt((z.real - img->temp_real) * (z.real - img->temp_real)
				+ (z.imag - img->temp_imag) * (z.imag - img->temp_imag));
		if (img->diff < 0.000000001)
			return (i);
	}
	return (0);
}
