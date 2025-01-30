
#include "libft.h"
#include <mlx.h>
#include <X11/X.h>
#include <X11/keysym.h>


typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	destroy_event(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);

	return (0);
}

int	key_down(int keycode, t_vars *vars)
{
  if (keycode == 65307)
    return destroy_event(vars);
  

  mlx_string_put(vars->mlx, vars->win, 100 / 2 - 50, 100 / 2, 0xFFFFFF, "Window Resized");
  ft_printf("keycode: %d\n", keycode);
	// mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int focus_in(t_vars *vars)
{
  ft_printf("focus_in\n");
}

int focus_out(t_vars *vars)
{
  ft_printf("focus_out\n");
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 500, 500, "Hello world!");
	mlx_hook(vars.win, 17, 1L, destroy_event, &vars);
	mlx_hook(vars.win, 2, 1L, key_down, &vars);
	mlx_hook(vars.win, 7, 1L, focus_in, &vars);
	mlx_hook(vars.win, 25, 1L, focus_out, &vars);
	mlx_loop(vars.mlx);
}
