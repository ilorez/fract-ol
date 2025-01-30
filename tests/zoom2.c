#include <mlx.h>
#include <stdlib.h>
#include <math.h>

typedef struct	s_data {
    void	*mlx;
    void	*win;
    void	*img;
    char	*addr;
    int		bits_per_pixel;
    int		line_length;
    int		endian;
    double	zoom;
    int		win_width;
    int		win_height;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char	*dst;

    if (x >= 0 && x < data->win_width && y >= 0 && y < data->win_height)
    {
        dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
        *(unsigned int*)dst = color;
    }
}

void	draw_square(t_data *data)
{
    int		x;
    int		y;
    int		size;
    int		center_x;
    int		center_y;

    // Clear the image
    for (int i = 0; i < data->win_height; i++)
        for (int j = 0; j < data->win_width; j++)
            my_mlx_pixel_put(data, j, i, 0x000000);

    // Calculate square parameters
    size = 50 * data->zoom;
    center_x = data->win_width / 2;
    center_y = data->win_height / 2;

    // Draw a square
    y = center_y - size / 2;
    while (y < center_y + size / 2)
    {
        x = center_x - size / 2;
        while (x < center_x + size / 2)
        {
            my_mlx_pixel_put(data, x, y, 0xFF0000);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

int	key_hook(int keycode, t_data *data)
{
    if (keycode == 65362) // Up arrow
        data->zoom *= 1.1;
    else if (keycode == 65364) // Down arrow
        data->zoom /= 1.1;
    else if (keycode == 65307) // ESC
    {
        mlx_destroy_window(data->mlx, data->win);
        exit(0);
    }
    draw_square(data);
    return (0);
}

int	main(void)
{
    t_data	data;

    data.win_width = 800;
    data.win_height = 600;
    data.zoom = 1.0;

    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, data.win_width, data.win_height, "Zoom Example");
    data.img = mlx_new_image(data.mlx, data.win_width, data.win_height);
    data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);

    draw_square(&data);
    mlx_hook(data.win,2, 1L, key_hook, &data);
    mlx_loop(data.mlx);

    return (0);
}
