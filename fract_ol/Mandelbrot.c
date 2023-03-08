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
	int j;
	int white;
	int asseY = 1080;
	int asseX = 1920;
	int unit = 108;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	i = 0;
	white = create_trgb(100, 200, 200, 200);

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
