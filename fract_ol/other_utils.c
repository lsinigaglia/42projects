/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsinigag <lsinigag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:45:08 by lsinigag          #+#    #+#             */
/*   Updated: 2023/03/23 21:20:35 by lsinigag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Mandelbrot.h"

int	convert_number_to_color(t_data *img, int number)
{
	int	color;

	if (number == 0)
		return (color = create_trgb (0, 0, 0, 0));
	if ((number + img->color_shift) % 4 == 0)
		color = create_trgb (0, 96, 175, 221);
	if ((number + img->color_shift) % 4 == 1)
		color = create_trgb (0, 236, 108, 91);
	if ((number + img->color_shift) % 4 == 2)
		color = create_trgb(0, 169, 209, 142);
	if ((number + img->color_shift) % 4 == 3)
		color = create_trgb(0, 255, 234, 167);
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
	while (i < 1920)
	{
		while (j < 1080)
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
