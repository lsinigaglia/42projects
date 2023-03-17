/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot_other_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsinigag <lsinigag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 01:40:55 by lsinigag          #+#    #+#             */
/*   Updated: 2023/03/17 01:42:16 by lsinigag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Mandelbrot.h"

double	convert_pixel_x_to_point_x(t_data *img, int pixel_x)
{
	double	x;

	x = ((img->x_axis_plane_total * pixel_x) / img->x_axis)
		+ (img->x_axis_plane_min) + img->x_move;
	return (x);
}

double	convert_pixel_y_to_point_y(t_data *img, int pixel_y)
{
	double	y;

	y = ((img->y_axis_plane_total * pixel_y) / img->y_axis)
		+ (img->y_axis_plane_min) - img->y_move;
	return (y);
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
	if (str[i++] == '-')
		sign = -1;
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
	res *= (double)1 / floater;
	ft_printf("res: %f\n", res);
	return (res * sign);
}
