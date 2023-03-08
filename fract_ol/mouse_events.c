#include <mlx.h>
#include <stdio.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	key_hook(int keycode, int x, int y, t_vars *vars)
{
	if (keycode == 1)
		printf("1\n");
	if (keycode == 2)
		printf("2\n");
	if (keycode == 3)
		printf("3\n");
	return (0);
}
int key_move(int x, int y, t_vars *vars)
{
	printf("x:%d; y:%d", x, y);
	return 0;
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	// mlx_mouse_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 6, 0, key_move, &vars);

	mlx_loop(vars.mlx);
}
