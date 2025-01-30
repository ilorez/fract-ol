#include <mlx.h>
#include <math.h>
#include "libft.h"

#define WIDTH 800
#define HEIGHT 800
#define RADIUS 200
#define CENTER_X WIDTH / 2
#define CENTER_Y HEIGHT / 2
#define BORDER 300
#define COLOR 0x00FF0000 // Red color in ARGB format

typedef struct s_img_data {
    void *img;
    char *addr;
    int bpp;
    int ll;
    int endian;
} t_img_data;

typedef struct s_cor {
    int x; // Changed to double
    int y; // Changed to double
} t_cor;

typedef struct s_data {
    void *mlx;
    void *win;
    double zoom;
    t_cor *center;
    t_img_data *img_data;
    t_cor *cor;
} t_data;

// Rounding function
int round_double(double value) {
    return (int)(value + 0.5);
}

int calculate_color(double x, double y, int color) {
    return color;
}

void ft_put_pixel(t_img_data *data, t_cor *cor, int color) {
    char *dst;

    // Round the coordinates to integers before drawing
    int x = round_double(cor->x);
    int y = round_double(cor->y);

    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
        dst = data->addr + y * data->ll + x * (data->bpp / 8);
        *(unsigned int*)dst = calculate_color(cor->x, cor->y, color);
    }
}

void draw_circle(t_data *data, double center_x, double center_y, double radius, int color) {
    double angle = 0;
    double angle_increment = 1.0 / radius;

    while (angle < 2 * M_PI) {
        data->cor->x = center_x + radius * cos(angle);
        data->cor->y = center_y + radius * sin(angle);
        ft_put_pixel(data->img_data, data->cor, color);
        angle += angle_increment;
    }
}

void circle_fractol(t_data *data, double center_x, double center_y, double radius, int color) {
    draw_circle(data, center_x, center_y, radius, color);
    if (radius < data->zoom)
        return;
    circle_fractol(data, center_x + radius, center_y + radius, radius / 2, color / 100);
    circle_fractol(data, center_x - radius, center_y - radius, radius / 2, color + 100);
    circle_fractol(data, center_x + radius, center_y - radius, radius / 2, color - 100);
    circle_fractol(data, center_x - radius, center_y + radius, radius / 2, color * 100);
}

int key_hook(int keycode, t_data *data) {
    if (keycode == 65362) // Up arrow
        data->zoom *= 1.1;
    else if (keycode == 65364) // Down arrow
        data->zoom /= 1.1;
    else if (keycode == 'w') // w
        data->center->y += 5;
    else if (keycode == 'a') // a
        data->center->x += 5;
    else if (keycode == 's') // s
        data->center->y -= 5;
    else if (keycode == 'd') // d
        data->center->x -= 5;
    else if (keycode == 65307) // ESC
    {
        mlx_destroy_window(data->mlx, data->win);
        exit(0);
    }
    mlx_clear_window(data->mlx, data->win);
    ft_bzero(data->img_data->addr, WIDTH * HEIGHT * data->img_data->bpp / 8);
    circle_fractol(data, data->center->x, data->center->y, RADIUS * data->zoom, COLOR);
    mlx_put_image_to_window(data->mlx, data->win, data->img_data->img, 0, 0);
    return 0;
}


int handle_mouse_click(int button, int x, int y, t_data *data) {
    if (button == 4) // Scroll up (zoom in)
    {
      data->center->x = x + (data->center->x - x) * 1.1;
      data->center->y = y + (data->center->y - y) * 1.1;
      data->zoom *= 1.1;
    }
    else if (button == 5) // Scroll down (zoom out)
    {
      data->center->x = x + (data->center->x - x) / 1.1;
      data->center->y = y + (data->center->y - y) / 1.1;
      data->zoom /= 1.1;
    }

    mlx_clear_window(data->mlx, data->win);
    ft_bzero(data->img_data->addr, WIDTH * HEIGHT * data->img_data->bpp / 8);
    circle_fractol(data, data->center->x, data->center->y, RADIUS * data->zoom, COLOR);
    mlx_put_image_to_window(data->mlx, data->win, data->img_data->img, 0, 0);
    return 0;
}

int destroy_event(t_data *vars) {
    mlx_destroy_window(vars->mlx, vars->win);
    exit(0);
}

int main() {
    t_data *data;
    t_cor *cor;
    t_cor *center;
    t_img_data *img_data;

    data = ft_calloc(sizeof(t_data), 1);
    cor = ft_calloc(sizeof(t_cor), 1);
    center = ft_calloc(sizeof(t_cor), 1);
    img_data = ft_calloc(sizeof(t_img_data), 1);

    data->mlx = mlx_init();
    data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "moving obj");
    img_data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
    img_data->addr = mlx_get_data_addr(img_data->img, &img_data->bpp, &img_data->ll, &img_data->endian);
    data->cor = cor;
    center->x = CENTER_X;
    center->y = CENTER_Y;
    data->center = center;
    data->img_data = img_data;
    data->zoom = 1;

    circle_fractol(data, CENTER_X, CENTER_Y, RADIUS * data->zoom, COLOR);
    mlx_put_image_to_window(data->mlx, data->win, img_data->img, 0, 0);

    mlx_hook(data->win, 2, 1L, key_hook, data);
    mlx_hook(data->win, 17, 1L, destroy_event, data);
    mlx_mouse_hook(data->win, handle_mouse_click, data);

    mlx_loop(data->mlx);
    return 0;
}
