
#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>

#define WIDTH 500
#define HEIGHT 500

typedef struct s_vars {
    void    *mlx;
    void    *win;
    double  zoom;
} t_vars;

void draw_square(t_vars *vars)
{
    int x, y;
    int size = (int)(50 * vars->zoom); // Scale the square size
    int start_x = WIDTH / 2 - size / 2;
    int start_y = HEIGHT / 2 - size / 2;

    mlx_clear_window(vars->mlx, vars->win);
    y = start_y;
    while (y < start_y + size)
    {
        x = start_x;
        while (x < start_x + size)
        {
            mlx_pixel_put(vars->mlx, vars->win, x, y, 0xFFFFFF); // White color
            x++;
        }
        y++;
    }
}

int mouse_hook(int button, int x, int y, t_vars *vars)
{
    (void)x;
    (void)y;
    if (button == 4) // Scroll up (zoom in)
        vars->zoom *= 1.1;
    if (button == 5) // Scroll down (zoom out)
        vars->zoom /= 1.1;
    draw_square(vars);
    return (0);
}

int main(void)
{
    t_vars vars;

    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "MLX Zoom Example");
    vars.zoom = 1.0;

    draw_square(&vars);
    mlx_mouse_hook(vars.win, mouse_hook, &vars);
    mlx_loop(vars.mlx);
    return (0);
}
