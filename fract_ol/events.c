/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsinigag <lsinigag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:57:34 by lsinigag          #+#    #+#             */
/*   Updated: 2023/03/11 22:29:02 by lsinigag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Mandelbrot.h"

void	zoom(t_data *img, double zoom, int x, int y)
{
	// double left;
	double right_x;
	double right_y;
	double temp;

	printf("x: %d", x);
	printf("y: %d", y);
	// es. x = 600; zoom = 0.8
	right_x = 1 - ((double)x / img->x_axis );
	// 1 - (600 / 900) = 0.6666
	right_y = 1 - ((double)y / img->y_axis );

	// left = 1 - right;

	printf ("maxX:%f\n", img->x_axis_plane_max);
	temp = img->x_axis_plane_max;
	img->x_axis_plane_max -= right_x * zoom * (img->x_axis_plane_max - img->x_axis_plane_min);
	printf ("maxX:%f\n", img->x_axis_plane_max);
	/* maxX = maxX - (right * Xaxis *zoom)*/

	// x axis = 900 * 0.66 * 0.8 = 432
	// x axis = 432;
	img->x_axis_plane_min += (1 - right_x) * zoom * (temp - img->x_axis_plane_min); /* 1 - right =  left */
	printf ("minX:%f\n", img->x_axis_plane_min);
	/* minX = minX - (left * Xaxis *zoom)*/
	// x center = 450  * 0.444 * 0.8
	// x center = 159.4
	temp = img->y_axis_plane_max;
	img->y_axis_plane_max -= right_y * zoom * ((img->y_axis_plane_max) - (img->y_axis_plane_min));
	printf ("maxY:%f\n", img->y_axis_plane_max);
	img->y_axis_plane_min += ((1 - right_y) * zoom * (temp - img->y_axis_plane_min)); /* 1 - right =  left */
	printf ("minY:%f\n", img->y_axis_plane_min);
	img->x_axis_plane_total = img->x_axis_plane_max - img->x_axis_plane_min;
	printf ("x_axis_plane_total:%f\n", img->x_axis_plane_total);
	img->y_axis_plane_total = img->y_axis_plane_max - img->y_axis_plane_min;


}

void	move(t_data *img, char direction)
{
	if (direction == 'R')
		img->x_move += 0.5;
	if (direction == 'L')
		img->x_move -= 0.5;
	if (direction == 'U')
		img->y_move += 0.5;
	if (direction == 'D')
		img->y_move -= 0.5;
}
int	mouse_events(int keycode, int x, int y, t_data *img)
{

	if (keycode == 4 || keycode == 1) /*scroll up*/
		zoom(img, 0.5, x, y);
	if (keycode == 5 || keycode == 2) /*scroll down*/
		zoom(img, 1.2, x, y);
	render (img);
	return 0;
}



// int	mouse_events(int keycode, int x, int y, t_data *img)
// {

// 	if (keycode == 4) /*scroll up*/
// 	{
// 		zoom(img, 0.8);
// 		if (y * 2 < img->y_axis) /*up arrow*/
// 			move(img, 'U');
// 		if (y * 2 > img->y_axis) /*down arrow*/
// 			move(img, 'D');
// 		if (x * 2 < img->x_axis) /*left arrow*/
// 			move(img, 'L');
// 		if (x * 2 > img->x_axis) /*right arrow*/
// 			move(img, 'R');
// 	}
// 	if (keycode == 5) /*scroll down*/
// 		zoom(img, 1.2);
// 	render (img);
// 	return 0;
// }

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
// if (keycode == 35 ) /* 'p'*/
// 	zoom(img, 1.2);
// if (keycode == 31) /* 'o'*/
// 	zoom(img, 0.8);
if (keycode == 53) /* ESC*/
{
	write(1, "ciao", 4);
	mlx_destroy_window(img->mlx, img->win);
	exit(0);
}
render (img);
	return 0;
}
