#include <mlx.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 800
#define HEIGHT 600
#define BOX_SIZE 200

typedef struct s_data {
    void    *mlx;
    void    *win;
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
    double  zoom;
    int     offset_x;
    int     offset_y;
} t_data;

int generate_random_errors(int x, int y)
{
    static int initialized = 0;
    if (!initialized) {
        srand(time(NULL));
        initialized = 1;
    }
    
    // 5% chance of a pixel error within the box
    if (abs(x - WIDTH/2) < BOX_SIZE/2 && 
        abs(y - HEIGHT/2) < BOX_SIZE/2 && 
        rand() % 100 < 5) {
        return rand() | 0xFF000000;
    }
    return 0x00FFFFFF; // Default white color
}

void draw_image(t_data *data)
{
    int x, y;

    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            // Apply zoom and offset
            int src_x = (x - data->offset_x) / data->zoom + WIDTH/2;
            int src_y = (y - data->offset_y) / data->zoom + HEIGHT/2;
            
            int color = generate_random_errors(src_x, src_y);
            
            // Draw main box
            if (abs(src_x - WIDTH/2) < BOX_SIZE/2 && 
                abs(src_y - HEIGHT/2) < BOX_SIZE/2) {
                color = 0x00000000; // Black for box
            }
            
            char *dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
            *(unsigned int*)dst = color;
        }
    }
}

int mouse_hook(int button, int x, int y, t_data *data)
{
    if (button == 4) { // Scroll up - zoom in
        data->zoom *= 1.1;
        data->offset_x = x - (x - data->offset_x) * 1.1;
        data->offset_y = y - (y - data->offset_y) * 1.1;
    }
    else if (button == 5) { // Scroll down - zoom out
        data->zoom /= 1.1;
        data->offset_x = x - (x - data->offset_x) / 1.1;
        data->offset_y = y - (y - data->offset_y) / 1.1;
    }
    
    draw_image(data);
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
    return 0;
}

int main(void)
{
    t_data data;

    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Zoomable Box with Errors");
    data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
    data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, 
                                &data.line_length, &data.endian);
    data.zoom = 1.0;
    data.offset_x = 0;
    data.offset_y = 0;

    // Initial draw
    draw_image(&data);
    mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);

    // Set up hooks
    mlx_mouse_hook(data.win, mouse_hook, &data);
    mlx_loop(data.mlx);

    return 0;
}
