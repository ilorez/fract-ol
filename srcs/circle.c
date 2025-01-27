
#include <mlx.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600
#define RADIUS 100
#define CENTER_X WIDTH / 2
#define CENTER_Y HEIGHT / 2
#define COLOR 0x00FF0000 // Red color in ARGB format

void draw_circle(void *img, int center_x, int center_y, int radius, int color)
{
    int bpp, size_line, endian;
    char *data = mlx_get_data_addr(img, &bpp, &size_line, &endian);

    for (int x = -radius; x <= radius; x++)
    {
        for (int y = -radius; y <= radius; y++)
        {
            if (x * x + y * y <= radius * radius) // Check if the pixel is inside the circle
            {
                int px = center_x + x;
                int py = center_y + y;
                if (px >= 0 && px < WIDTH && py >= 0 && py < HEIGHT) // Ensure the pixel is within the image bounds
                {
                    int pixel_index = py * size_line + px * (bpp / 8);
                    *(int *)(data + pixel_index) = color; // Set the pixel color
                }
            }
        }
    }
}

int main()
{
    void *mlx = mlx_init();
    void *win = mlx_new_window(mlx, WIDTH, HEIGHT, "Circle Example");
    void *img = mlx_new_image(mlx, WIDTH, HEIGHT);

    // Draw a circle
    draw_circle(img, CENTER_X, CENTER_Y, RADIUS, COLOR);

    // Display the image in the window
    mlx_put_image_to_window(mlx, win, img, 0, 0);

    // Keep the window open
    mlx_loop(mlx);

    return 0;
}   // Display the image in the window
