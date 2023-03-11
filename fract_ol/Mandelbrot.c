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
	t_data	img;
	// int	i;
	// int	j;
	int number;
	int color;

	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, 900, 900, "Hello world!");
	img.img = mlx_new_image(img.mlx, 900, 900);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	// i = 0;
	// j = 0;
	img.x_axis = 900;
	img.y_axis = 900;
	img.x_axis_plane_max = 1.5;
	img.x_axis_plane_min = -1.5;
	img.y_axis_plane_max = 1.5;
	img.y_axis_plane_min = -1.5;
	img.x_axis_plane_total = 3.0;
	img.y_axis_plane_total = 3.0;

	render(&img);
	// mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
	// mlx_hook(img.win, 2, 0, ft_close, &img);
	mlx_mouse_hook(img.win, mouse_events, &img);
	mlx_key_hook(img.win, key_event, &img);
	// mlx_hook(img.win, 4, 0, zoom_in, &img);
	// mlx_hook(vars.win, 3, 0, zoom_out, &img);

	mlx_loop(img.mlx);
}
