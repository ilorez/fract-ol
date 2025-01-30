#include <mlx.h>
#include <stdlib.h>

typedef struct s_data {
    void    *mlx;
    void    *win;
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
    double  zoom;
    int     win_width;
    int     win_height;
}   t_data;

void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    if (x >= 0 && x < data->win_width && y >= 0 && y < data->win_height)
    {
        dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
        *(unsigned int*)dst = color;
    }
}

void    draw_zoomed_square(t_data *data)
{
    int base_size = 50;
    int zoomed_size = base_size * data->zoom;
    int start_x = (data->win_width - zoomed_size) / 2;
    int start_y = (data->win_height - zoomed_size) / 2;

    // Clear only the previous area
    int clear_margin = base_size * 2;  // Extra margin to clear
    int clear_start_x = (data->win_width - clear_margin) / 2;
    int clear_start_y = (data->win_height - clear_margin) / 2;
    
    for (int y = clear_start_y; y < clear_start_y + clear_margin; y++)
        for (int x = clear_start_x; x < clear_start_x + clear_margin; x++)
            my_mlx_pixel_put(data, x, y, 0x000000);

    // Draw only the square area
    for (int y = start_y; y < start_y + zoomed_size; y++)
        for (int x = start_x; x < start_x + zoomed_size; x++)
            my_mlx_pixel_put(data, x, y, 0xFF0000);

    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

int    key_hook(int keycode, t_data *data)
{
    if (keycode == 65362)      // Up arrow
        data->zoom *= 1.1;
    else if (keycode == 65364) // Down arrow
        data->zoom /= 1.1;
    else if (keycode == 65307) // ESC
    {
        mlx_destroy_window(data->mlx, data->win);
        exit(0);
    }
    draw_zoomed_square(data);
    return (0);
}

int    main(void)
{
    t_data    data;

    data.win_width = 800;
    data.win_height = 600;
    data.zoom = 1.0;

    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, data.win_width, data.win_height, "Zoom Example");
    data.img = mlx_new_image(data.mlx, data.win_width, data.win_height);
    data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, 
                                 &data.line_length, &data.endian);

    draw_zoomed_square(&data);
    mlx_key_hook(data.win, key_hook, &data);
    mlx_loop(data.mlx);

    return (0);
}
