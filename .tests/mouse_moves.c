#include <mlx.h>
#include <stdio.h>

typedef struct s_data {
    void    *mlx;
    void    *win;
    int     width;
    int     height;
    int     mouse_in_window; // Flag to track if mouse is in the window
} t_data;

// Function to handle mouse movement
int handle_mouse_move(int x, int y, t_data *data)
{
    // Check if the mouse is inside the window
    if (x >= 0 && x < data->width && y >= 0 && y < data->height)
    {
        if (!data->mouse_in_window)
        {
            printf("Mouse entered the window!\n");
            data->mouse_in_window = 1; // Set flag to indicate mouse is inside
        }
    }
    else
    {
        if (data->mouse_in_window)
        {
            printf("Mouse left the window!\n");
            data->mouse_in_window = 0; // Set flag to indicate mouse is outside
        }
    }
    return (0);
}

// Function to handle mouse clicks (optional)
int handle_mouse_click(int button, int x, int y, t_data *data)
{
    printf("button: %d\n", button);
    printf("Mouse click at (%d, %d)\n", x, y);
    return (0);
}

int main(void)
{
    t_data data;

    data.mlx = mlx_init();
    data.width = 800;
    data.height = 600;
    data.mouse_in_window = 0; // Initialize flag

    data.win = mlx_new_window(data.mlx, data.width, data.height, "Mouse Enter/Leave Example");

    // Set up mouse movement hook
    mlx_hook(data.win, 6, 1L << 6, handle_mouse_move, &data); // MotionNotify event

    // Set up mouse click hook (optional)
    mlx_mouse_hook(data.win, handle_mouse_click, &data);

    // Start the main loop
    mlx_loop(data.mlx);

    return (0);
}
