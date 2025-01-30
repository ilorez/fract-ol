#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_data {
    void    *mlx;
    void    *win;
    int     width;
    int     height;
} t_data;

int handle_event(int event, void *param)
{
    t_data *data = (t_data *)param;

    if (event == 12) // Expose event
    {
        // Redraw the window content here
        mlx_clear_window(data->mlx, data->win);
        // Example: Draw a simple rectangle
        mlx_string_put(data->mlx, data->win, data->width / 2 - 50, data->height / 2, 0xFFFFFF, "Resized Window");
    }
    else if (event == 22) // ResizeRequest event
    {
        // Update the window size
        mlx_clear_window(data->mlx, data->win);
        mlx_get_screen_size(data->mlx, &data->width, &data->height);
        mlx_string_put(data->mlx, data->win, data->width / 2 - 50, data->height / 2, 0xFFFFFF, "Resized Window");
    }
    return (0);
}

int main(void)
{
    t_data data;

    data.mlx = mlx_init();
    if (data.mlx == NULL)
        return (1);

    data.width = 800;
    data.height = 600;

    data.win = mlx_new_window(data.mlx, data.width, data.height, "Resizable Window");
    if (data.win == NULL)
    {
        free(data.mlx);
        return (1);
    }

    // Set up event hooks
    mlx_expose_hook(data.win, handle_event, &data);
    mlx_loop_hook(data.mlx, handle_event, &data);

    // Start the main loop
    mlx_loop(data.mlx);

    return (0);
}
