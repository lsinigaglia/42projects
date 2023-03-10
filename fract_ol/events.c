/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsinigag <lsinigag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:57:34 by lsinigag          #+#    #+#             */
/*   Updated: 2023/03/10 03:06:51 by lsinigag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Mandelbrot.h"

void	zoom(t_data *img, double zoom )
{
	img->x_axis_plane *= zoom;
	img->y_axis_plane *= zoom;
}

void	move(t_data *img, char direction)
{
	if (direction == 'R')
		img->x_axis_plane_min += 0.5;
	if (direction == 'L')
		img->x_axis_plane_min -= 0.5;
	if (direction == 'U')
		img->y_axis_plane_min += 0.5;
	if (direction == 'D')
		img->y_axis_plane_min -= 0.5;
}



int	mouse_events(int keycode, int x, int y, t_data *img)
{

	if (keycode == 4) /*scroll up*/
	{
		zoom(img, 0.8);
		if (y * 2 < img->y_axis) /*up arrow*/
			move(img, 'U');
		if (y * 2 > img->y_axis) /*down arrow*/
			move(img, 'D');
		if (x * 2 < img->x_axis) /*left arrow*/
			move(img, 'L');
		if (x * 2 > img->x_axis) /*right arrow*/
			move(img, 'R');
	}
	if (keycode == 5) /*scroll down*/
		zoom(img, 1.2);
	render (img);
	return 0;
}

int	key_event(int keycode, t_data *img)
{
if (keycode == 126 || keycode == 13) /*up arrow, w*/
	move(img, 'U');
if (keycode == 125 || keycode == 1) /*down arrow, 's'*/
	move(img, 'D');
if (keycode == 123 || keycode == 0) /*left arrow, 'a'*/
	move(img, 'L');
if (keycode == 124 || keycode == 2) /*right arrow, 'd'*/
	move(img, 'R');
if (keycode == 35 ) /* 'p'*/
	zoom(img, 1.2);
if (keycode == 31) /* 'o'*/
	zoom(img, 0.8);
if (keycode == 53) /* ESC*/
{
	write(1, "ciao", 4);
	mlx_destroy_window(img->mlx, img->win);
	exit(0);
}
render (img);
	return 0;
}
