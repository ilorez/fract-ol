#include <mlx.h>
#include <math.h>
#include <time.h> // For nanosleep

#define WIDTH 800
#define HEIGHT 600
#define CENTER_X WIDTH / 2
#define CENTER_Y HEIGHT / 2
#define RADIUS 200
#define COLOR 0xFFFFFF // Green color


void sleep_nanoseconds(long nanoseconds)
{
    struct timespec req;
    req.tv_sec = 0;          // Seconds
    req.tv_nsec = nanoseconds; // Nanoseconds (1 second = 1,000,000,000 nanoseconds)

    // Call nanosleep
    nanosleep(&req, NULL);
}

void draw_circle(void *mlx, void *win, void *img, int center_x, int center_y, int radius, int color)
{
    int bpp, size_line, endian;
    char *data = mlx_get_data_addr(img, &bpp, &size_line, &endian);

    double angle = 0;
    double angle_increment = 1.0 / radius; // Adjust for smoother or faster drawing

    while (angle < 2 * M_PI) // Loop through 360 degrees
    {
        int x = center_x + (int)(radius * cos(angle));
        int y = center_y + (int)(radius * sin(angle));

        if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) // Ensure the pixel is within bounds
        {
            int pixel_index = y * size_line + x * (bpp / 8);
            *(int *)(data + pixel_index) = color + ((int )angle + 1) * 1000; // Set the pixel color
        }
        angle += angle_increment; // Increment the angle
        mlx_put_image_to_window(mlx, win, img, 0, 0);
        sleep_nanoseconds(1000);
    }
}

int main()
{
    void *mlx = mlx_init();
    void *win = mlx_new_window(mlx, WIDTH, HEIGHT, "Empty Circle Example");
    void *img = mlx_new_image(mlx, WIDTH, HEIGHT);

    draw_circle(mlx, win, img, CENTER_X, CENTER_Y, RADIUS, COLOR);

    // Display the image in the window
    mlx_put_image_to_window(mlx, win, img, 0, 0);

    // Keep the window open
    mlx_loop(mlx);

    return 0;
}
