/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ci_hanno_rubato_i_colori.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsinigag <lsinigag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 20:33:48 by lsinigag          #+#    #+#             */
/*   Updated: 2023/03/01 01:57:44 by lsinigag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx/mlx.h"

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

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int	i;
	int j;
	int asseY = 1080;
	int asseX = 1920;
	int unit = 108;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	i = asseX/3;
	while (i <= (asseX*2)/3)
	{
		my_mlx_pixel_put(&img, i, asseY/3, 0x00000F00);
		my_mlx_pixel_put(&img, i, (asseY*2)/3, 0x0000F000);
		i++;
	}
	j = asseY/3;
	while (j <= (asseY*2)/3)
	{
		my_mlx_pixel_put(&img, asseX/3, j, 0x00FF00F0);
		my_mlx_pixel_put(&img, (asseX*2)/3, j, 0x0F0F00FF);
		j++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
