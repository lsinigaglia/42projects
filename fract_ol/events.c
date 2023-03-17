/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsinigag <lsinigag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:57:34 by lsinigag          #+#    #+#             */
/*   Updated: 2023/03/17 00:45:51 by lsinigag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Mandelbrot.h"

/* to zoom in use this formula: (max)X=(max(X)-(right * X(axis) * zoom)
and (min)X = (min)X - (left * X(axis) * zoom). basically i take out a portion*/
/*of the "right" axis and of the "left" of the axis adjusted on the location of the point.
The zoom factor is how much we want to zoom. i set it at 0.5.
Right = 1 - x / X(axis). it varies beteewn 0 and 1. */
/*if i have an x axis = {-1, +2} and x = 1 the x axis has to become {0, +1,5}. out of
that result i came up with this formula. so in this case i have:
max(X) = 2 - ((1/3 * 3) * 0.5) =*/
/*max(X) = 2 - 1.5
max(X) = 0.5
to make max X i have to add instead of subtracting. i do the same for the Y as if
if works on a line it works on a plane. */
void	zoom_in(t_data *img, double zoom, int x, int y)
{
	double	right_x;
	double	right_y;
	double	temp;

	right_x = 1 - ((double)x / img->x_axis);
	right_y = 1 - ((double)y / img->y_axis);
	temp = img->x_axis_plane_max;
	img->x_axis_plane_max -= right_x * zoom * (img->x_axis_plane_max
			- img->x_axis_plane_min);
	img->x_axis_plane_min += (1 - right_x) * zoom * (temp
			- img->x_axis_plane_min);
	temp = img->y_axis_plane_max;
	img->y_axis_plane_max -= right_y * zoom * ((img->y_axis_plane_max)
			- (img->y_axis_plane_min));
	img->y_axis_plane_min += ((1 - right_y) * zoom * (temp
				- img->y_axis_plane_min));
	img->x_axis_plane_total = img->x_axis_plane_max - img->x_axis_plane_min;
	img->y_axis_plane_total = img->y_axis_plane_max - img->y_axis_plane_min;
}
/* zoom_out works in the same way of zoom_in but instead of
(max)X = (max(X) - (right * X(axis) * zoom) i have to add.
(max)X = (max(X) + (right * X(axis) * zoom) this way the axis
gets bigger and not smaller. i have to invert the sign for min(x)
and then do the same for Y.  */

void	zoom_out(t_data *img, double zoom, int x, int y)
{
	double	right_x;
	double	right_y;
	double	temp;

	right_x = 1 - ((double)x / img->x_axis);
	right_y = 1 - ((double)y / img->y_axis);
	temp = img->x_axis_plane_max;
	img->x_axis_plane_max += right_x * zoom * (img->x_axis_plane_max
			- img->x_axis_plane_min);
	img->x_axis_plane_min -= (1 - right_x) * zoom * (temp
			- img->x_axis_plane_min);
	temp = img->y_axis_plane_max;
	img->y_axis_plane_max += right_y * zoom * ((img->y_axis_plane_max)
			- (img->y_axis_plane_min));
	img->y_axis_plane_min -= ((1 - right_y) * zoom * (temp
				- img->y_axis_plane_min));
	img->x_axis_plane_total = img->x_axis_plane_max - img->x_axis_plane_min;
	img->y_axis_plane_total = img->y_axis_plane_max - img->y_axis_plane_min;
}

/* to move on the plane i set four arrows. this is pretty straightforward
but it's worthy noting that i move by a fraction of the current axis.
if i move by a fixed amount when i zoom a lot i will have trouble.
for example if i fix the move amount at 0.5 it will work if the axis is big,
but if the X(axis) is {0.0005; 0.0010} it will move by way too much.  */
void	move(t_data *img, char direction)
{
	if (direction == 'R')
		img->x_move += (img->x_axis_plane_max - img->x_axis_plane_min) / 5;
	if (direction == 'L')
		img->x_move -= (img->x_axis_plane_max - img->x_axis_plane_min) / 5;
	if (direction == 'U')
		img->y_move += (img->y_axis_plane_max - img->y_axis_plane_min) / 5;
	if (direction == 'D')
		img->y_move -= (img->y_axis_plane_max - img->y_axis_plane_min) / 5;
}

int	mouse_events(int keycode, int x, int y, t_data *img)
{
	if (keycode == 4 || keycode == 1)
		zoom_in(img, 0.5, x, y);
	if (keycode == 5 || keycode == 2)
		zoom_out(img, 1.2, x, y);
	render (img);
	return (0);
}

int	key_event(int keycode, t_data *img)
{
	if (keycode == 126 || keycode == 13)
		move(img, 'U');
	if (keycode == 125 || keycode == 1)
		move(img, 'D');
	if (keycode == 123 || keycode == 0)
		move(img, 'L');
	if (keycode == 124 || keycode == 2)
		move(img, 'R');
	if (keycode == 35)
		zoom_in(img, 0.5, 450, 450);
	if (keycode == 31)
		zoom_out(img, 1.2, 450, 450);
	if (keycode == 53)
	{
		write(1, "ciao", 4);
		mlx_destroy_window(img->mlx, img->win);
		exit(0);
	}
	if (keycode == 6)
	{
		img->color_shift++;
	}
	render (img);
	return (0);
}
