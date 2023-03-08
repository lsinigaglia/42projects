#include <mlx.h>
#include <stdio.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	close(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
	}
	return (0);
}

int	print(int keycode, t_vars *vars)
{
	if (keycode != 53)
	{
		printf("ciao");
	}
	return (0);
}

int key_release(int keycode, t_vars *vars)
{
    (void)vars;
    (void)keycode;
    printf("Key released\n");
    return (0);
}



int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	// mlx_hook(vars.win, 2, 0, close, &vars);
	mlx_hook(vars.win, 2, 0, print, &vars);
	mlx_hook(vars.win, 3, 0, key_release, &vars);
	mlx_loop(vars.mlx);
}
