
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


typedef struct	s_img_data {

	void	*img;
	char	*addr;
	int		bpp;
	int		ll;
	int		endian;
}				t_img_data;

typedef struct	s_cor {
	int		x;
	int		y;
}				t_cor;

typedef struct	s_data {
  void *mlx;
  void *win;
  double zoom;
  t_img_data *img_data;
  t_cor *cor;
}				t_data;

void ft_put_pixel(t_img_data *data, t_cor *cor, int color)
{
  char *dst;

  dst = data->addr + cor->y * data->ll + cor->x * (data->bpp / 8);
  *(unsigned int*)dst = color;
}




void draw_circle(t_data *data, int center_x, int center_y, int radius, int color)
{
    double angle = 0;
    double angle_increment = 1.0 / radius; // Adjust for smoother or faster drawing
    

    while (angle < 2 * M_PI) // Loop through 360 degrees
    {
        data->cor->x = center_x + (int)(radius * cos(angle));
        data->cor->y = center_y + (int)(radius * sin(angle));
        if (data->cor->x >= 0 && data->cor->x < WIDTH && data->cor->y >= 0 && data->cor->y < HEIGHT) // Ensure the pixel is within bounds
            ft_put_pixel(data->img_data, data->cor, color);
        angle += angle_increment;
    }
}


void circle_fractol(t_data *data, int center_x, int center_y, int radius, int color)
{
  draw_circle(data, center_x, center_y, radius, color);
  //mlx_clear_window(data->mlx, data->win);
  //mlx_put_image_to_window(data->mlx, data->win, data->img_data->img, 0, 0);
  if (radius < 1 * data->zoom / 2)
    return ;
  circle_fractol(data, center_x + radius, center_y + radius, radius / 2, color / 100);
  circle_fractol(data, center_x - radius, center_y - radius, radius / 2, color + 100);
  circle_fractol(data, center_x + radius, center_y - radius, radius / 2, color - 100);
  circle_fractol(data, center_x - radius, center_y + radius, radius / 2, color * 100);
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
    mlx_clear_window(data->mlx, data->win);
    ft_bzero(data->img_data->addr, WIDTH * HEIGHT * data->img_data->bpp / 8);
    circle_fractol(data, CENTER_X, CENTER_Y, RADIUS * data->zoom, COLOR);
    mlx_put_image_to_window(data->mlx, data->win, data->img_data->img, 0, 0);
    return (0);
}

int main()
{
  t_data *data;
  t_cor *cor;
  t_img_data *img_data;

  data = ft_calloc(sizeof(t_data), 1);
  cor = ft_calloc(sizeof(t_cor), 1);
  img_data = ft_calloc(sizeof(t_img_data), 1);

  data->mlx = mlx_init();
  data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "moving obj");
  img_data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
  img_data->addr = mlx_get_data_addr(img_data->img, &img_data->bpp, &img_data->ll, &img_data->endian);
  data->cor = cor;
  data->img_data = img_data;
  data->zoom = 1;

  circle_fractol(data, CENTER_X, CENTER_Y, RADIUS * data->zoom, COLOR);
    // Display the image in the window
  mlx_put_image_to_window(data->mlx, data->win, img_data->img, 0, 0);

  mlx_hook(data->win, 2, 1L, key_hook, data);
  // Keep the window open
  mlx_loop(data->mlx);
  return 0;
}   // Display the image in the window

