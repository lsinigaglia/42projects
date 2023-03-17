/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsinigag <lsinigag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:41:32 by lsinigag          #+#    #+#             */
/*   Updated: 2023/03/17 01:20:02 by lsinigag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Mandelbrot.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

// void	add_shade(double dark, int *trgb)
// {
// 	int	t = (*trgb >> 24 & 0xFF) * dark;
// 	int	r = (*trgb >> 16 & 0xFF) * dark;
// 	int	g = (*trgb >> 8 & 0xFF) * dark;
// 	int	b = (*trgb & 0xFF) * dark;

// 	*trgb = (t << 24 | r << 16 | g << 8 | b);
// }

// void	get_opposite_color(int *trgb)
// {
// 	int	t = (*trgb >> 24 & 0xFF);
// 	int	r = (*trgb >> 16 & 0xFF);
// 	int	g = (*trgb >> 8 & 0xFF);
// 	int	b = (*trgb & 0xFF);

// 	*trgb = (t << 24 | (255 - r) << 16 | (255 - g) << 8 | 255 - b);
// }

void	init(t_data *img)
{
	img->mlx = mlx_init();
	img->win = mlx_new_window(img->mlx, 900, 900, "Hello world!");
	img->img = mlx_new_image(img->mlx, 900, 900);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	img->x_axis = 900;
	img->y_axis = 900;
	img->x_axis_plane_max = 1.5;
	img->x_axis_plane_min = -1.5;
	img->y_axis_plane_max = 1.5;
	img->y_axis_plane_min = -1.5;
	img->x_axis_plane_total = 3.0;
	img->y_axis_plane_total = 3.0;
	img->color_shift = 0;
}

int	main(int argc, char **argv)
{
	t_data	img;
	int		number;
	int		color;
	int		x;

	if (write_checks(argc, argv))
		return (0);
	init(&img);
	if (ft_strncmp(argv[1], "mandelbrot", 5) == 0)
		img.set = 1;
	if (ft_strncmp(argv[1], "julia", 5) == 0)
	{
		img.set = 2;
		img.c_julia.real = atof(argv[2]);
		img.c_julia.imag = atof(argv[3]);
	}
	render(&img);
	mlx_mouse_hook(img.win, mouse_events, &img);
	mlx_key_hook(img.win, key_event, &img);
	mlx_loop(img.mlx);
}
