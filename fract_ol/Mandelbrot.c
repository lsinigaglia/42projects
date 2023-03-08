#include "Mandelbrot.h"

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
	int	t = (*trgb >> 24 & 0xFF) * dark;
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
	int	j;
	int number;
	int color;
	double	point_x;
	double	point_y;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	i = 0;
	j = 0;
	while (i < 1920)
	{
		while (j++ < 1080)
		{
			point_x = convert_pixel_X_to_point_x(i, 1920);
			point_y = convert_pixel_Y_to_point_y(j, 1080);
			// printf("y:%f\n", point_y);
			// printf("x:%f\n", point_x);
			number = convert_point_to_number(point_x, point_y);
			// printf("number: %d\n", number);
			color = convert_number_to_color(number);
			// printf("color:%d", color);
			my_mlx_pixel_put(&img, i, j, color);
			j++;
		}
		j = 0;
		i++;
	}

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
