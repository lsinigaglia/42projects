/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ci_hanno_rubato_i_colori.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsinigag <lsinigag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 20:33:48 by lsinigag          #+#    #+#             */
/*   Updated: 2023/03/08 01:13:07 by lsinigag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx/mlx.h"
#include <stdio.h>
#include <mlx.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void add_shade (double dark, int *trgb)
{
	int	t = (*trgb >> 24 & 0xFF);
	int	r = (*trgb >> 16 & 0xFF) * dark;
	int	g = (*trgb >> 8 & 0xFF) * dark;
	int	b = (*trgb & 0xFF) * dark;

	*trgb = (t << 24 | r << 16 | g << 8 | b);
}

void get_opposite_color (int *trgb)
{
	int	t = (*trgb >> 24 & 0xFF);
	int	r = (*trgb >> 16 & 0xFF);
	int	g = (*trgb >> 8 & 0xFF);
	int	b = (*trgb & 0xFF);

	*trgb = (t << 24 | (255 - r) << 16 | (255 - g) << 8 | 255 - b);
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int	i;
	int j;
	int blu;
	int asseY = 1080;
	int asseX = 1920;
	int unit = 108;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	i = asseX / 3;
	blu = create_trgb(1, 0, 71, 171);
	printf("colore:%d\n", blu);
	add_shade(1, &blu);
	printf("colore:%d\n", blu);
	while (i <= (asseX*2)/3)
	{
		my_mlx_pixel_put(&img, i, asseY/3, blu);
		my_mlx_pixel_put(&img, i, (asseY*2)/3, blu);
		i++;
	}
	get_opposite_color(&blu);
	// add_shade(0.3, &blu);
	j = asseY/3;
	while (j <= (asseY * 2)/3)
	{
		my_mlx_pixel_put(&img, asseX/3, j, blu);
		my_mlx_pixel_put(&img, (asseX*2)/3, j, blu);
		j++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
