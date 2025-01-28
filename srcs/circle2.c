#include <mlx.h>
#include <stdio.h>

#define WIDTH 800
#define HEIGHT 600
#define CENTER_X WIDTH / 2
#define CENTER_Y HEIGHT / 2
#define RADIUS 200
#define COLOR 0x00FF00
#define BORDER 2

void draw_circle(void *mlx, void *win, void *img, int center_x, int center_y, int radius, int color)
{
    int bpp, size_line, endian;
    char *data = mlx_get_data_addr(img, &bpp, &size_line, &endian);

    int x = radius;
    int y = 0;
    int err = 0;

    while (x >= y)
    {
        // Draw the circle boundary pixels in all octants
        for (int i = -BORDER; i <= BORDER; i++)
        {
            int px1 = center_x + x + i;
            int py1 = center_y + y;
            if (px1 >= 0 && px1 < WIDTH && py1 >= 0 && py1 < HEIGHT)
            {
                int pixel_index = py1 * size_line + px1 * (bpp / 8);
                *(int *)(data + pixel_index) = color;
            }

            int px2 = center_x + y + i;
            int py2 = center_y + x;
            if (px2 >= 0 && px2 < WIDTH && py2 >= 0 && py2 < HEIGHT)
            {
                int pixel_index = py2 * size_line + px2 * (bpp / 8);
                *(int *)(data + pixel_index) = color;
            }

            int px3 = center_x - y + i;
            int py3 = center_y + x;
            if (px3 >= 0 && px3 < WIDTH && py3 >= 0 && py3 < HEIGHT)
            {
                int pixel_index = py3 * size_line + px3 * (bpp / 8);
                *(int *)(data + pixel_index) = color;
            }

            int px4 = center_x - x + i;
            int py4 = center_y + y;
            if (px4 >= 0 && px4 < WIDTH && py4 >= 0 && py4 < HEIGHT)
            {
                int pixel_index = py4 * size_line + px4 * (bpp / 8);
                *(int *)(data + pixel_index) = color;
            }

            int px5 = center_x - x + i;
            int py5 = center_y - y;
            if (px5 >= 0 && px5 < WIDTH && py5 >= 0 && py5 < HEIGHT)
            {
                int pixel_index = py5 * size_line + px5 * (bpp / 8);
                *(int *)(data + pixel_index) = color;
            }

            int px6 = center_x - y + i;
            int py6 = center_y - x;
            if (px6 >= 0 && px6 < WIDTH && py6 >= 0 && py6 < HEIGHT)
            {
                int pixel_index = py6 * size_line + px6 * (bpp / 8);
                *(int *)(data + pixel_index) = color;
            }

            int px7 = center_x + y + i;
            int py7 = center_y - x;
            if (px7 >= 0 && px7 < WIDTH && py7 >= 0 && py7 < HEIGHT)
            {
                int pixel_index = py7 * size_line + px7 * (bpp / 8);
                *(int *)(data + pixel_index) = color;
            }

            int px8 = center_x + x + i;
            int py8 = center_y - y;
            if (px8 >= 0 && px8 < WIDTH && py8 >= 0 && py8 < HEIGHT)
            {
                int pixel_index = py8 * size_line + px8 * (bpp / 8);
                *(int *)(data + pixel_index) = color;
            }
        }

        if (err <= 0)
        {
            y += 1;
            err += 2 * y + 1;
        }
        if (err > 0)
        {
            x -= 1;
            err -= 2 * x + 1;
        }
    }
}

void circle_fractol(void *mlx, void *win, void *img, int center_x, int center_y, int radius, int color)
{
    if (radius < 1)
        return;

    draw_circle(mlx, win, img, center_x, center_y, radius, color);
    mlx_put_image_to_window(mlx, win, img, 0, 0);

    // Recursively draw smaller circles
    circle_fractol(mlx, win, img, center_x + radius, center_y + radius, radius / 2, color / 100);
    circle_fractol(mlx, win, img, center_x - radius, center_y - radius, radius / 2, color + 100);
    circle_fractol(mlx, win, img, center_x + radius, center_y - radius, radius / 2, color - 100);
    circle_fractol(mlx, win, img, center_x - radius, center_y + radius, radius / 2, color * 100);
}

int main()
{
    void *mlx = mlx_init();
    void *win = mlx_new_window(mlx, WIDTH, HEIGHT, "Circle Fractal");
    void *img = mlx_new_image(mlx, WIDTH, HEIGHT);

    circle_fractol(mlx, win, img, CENTER_X, CENTER_Y, RADIUS, COLOR);

    // Keep the window open
    mlx_loop(mlx);

    return 0;
}
