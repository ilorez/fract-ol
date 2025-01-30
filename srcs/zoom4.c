#include <mlx.h>
#include <math.h>


#define COLOR 0x00FF0000 // Red color in ARGB format


typedef struct s_data {
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}               t_data;

typedef struct s_vars {
    void    *mlx;
    void    *win;
    t_data  img;
    double  zoom;
    int     mouse_x;
    int     mouse_y;
}               t_vars;

void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}
int     zoom_hook(int button, int x, int y, t_vars *vars)
{
    if (button == 4) // Scroll up
        vars->zoom *= 1.1;
    else if (button == 5) // Scroll down
        vars->zoom /= 1.1;
    vars->mouse_x = x;
    vars->mouse_y = y;
    // Redraw the image with the new zoom
    // You need to implement the drawing logic here
    return (0);
}
int calculate_color(int x, int y)
{
  int sum = x * y;
  if (sum > 0)
    return (COLOR + sum );
  else if (sum < 0)
    return (COLOR / sum * -1);
  return (COLOR);

}

int    draw_fractal(t_vars *vars)
{
    int x, y;
    double new_x, new_y;

    for (y = 0; y < 800; y++)
    {
        for (x = 0; x < 800; x++)
        {
            // Translate to mouse position, apply zoom, translate back
            new_x = (x - vars->mouse_x) * vars->zoom + vars->mouse_x;
            new_y = (y - vars->mouse_y) * vars->zoom + vars->mouse_y;

            // Use new_x and new_y to calculate the color
            int color = calculate_color(new_x, new_y); // Implement this function

            my_mlx_pixel_put(&vars->img, x, y, color);
        }
    }
    mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}

int     main(void)
{
    t_vars  vars;

    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 800, 800, "Zoom to Mouse");
    vars.img.img = mlx_new_image(vars.mlx, 800, 800);
    vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel, &vars.img.line_length, &vars.img.endian);
    vars.zoom = 1.0;
    vars.mouse_x = 400;
    vars.mouse_y = 400;

    mlx_mouse_hook(vars.win, zoom_hook, &vars);
    mlx_loop_hook(vars.mlx, draw_fractal, &vars);
    mlx_loop(vars.mlx);
    return (0);
}
