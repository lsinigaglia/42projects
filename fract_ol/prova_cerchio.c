/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prova_cerchio.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsinigag <lsinigag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 19:35:10 by lsinigag          #+#    #+#             */
/*   Updated: 2023/03/08 20:16:30 by lsinigag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>

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

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
    int i = 0;
    int r = 200;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
    while  (r < 300){
		while (i < 2*M_PI*r)
		{
			if (r < 200)
				my_mlx_pixel_put(&img, (r*cos(i*M_PI/r) + 960), (r*sin(i*M_PI/r) +540) , 0x55001000);
				//mlx_M_PIxel_put(&img, r*cos(2*M_PI*i/(2*M_PI*r)), r*sin(2*M_PI*i/(2*M_PI*r)) , 0x00FF0000); formula originale
			else
				my_mlx_pixel_put(&img, (r*cos(i*M_PI/r) + 960), (r*sin(i*M_PI/r) +540) , 0x0000FF00);

			i++;
		}
		i = 0;
		r++;
	}
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
