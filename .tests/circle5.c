
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
  t_cor *center;
  t_img_data *img_data;
  t_cor *cor;
}				t_data;


void ft_put_pixel(t_img_data *data, t_cor *cor, int color)
{
  char *dst;

  dst = data->addr + cor->y * data->ll + cor->x * (data->bpp / 8);
  *(unsigned int*)dst = color;
}


void ft_draw_square(t_data *data, int width, int hieght, int x, int y, int color)
{
  t_cor cor;
  cor.x = x -1;
  while (++cor.x < width + x && cor.x <= WIDTH && cor.x >= 0)
  {
    cor.y = y-1;
    while (++cor.y < hieght + y && cor.y <= HEIGHT && cor.y >= 0)
      ft_put_pixel(data->img_data, &cor, color);
  }
}

int handle_mouse_click(int button, int x, int y, t_data *data)
{
  if (button == 4)
        data->zoom *= 1.1;
  else if (button == 5)
        data->zoom /= 1.1;
  data->center->x = (data->center->x - x) * data->zoom  + x;
  data->center->y = (data->center->y - y) * data->zoom  + y;
  ft_bzero(data->img_data->addr, WIDTH * HEIGHT * data->img_data->bpp / 8);
  ft_draw_square(data, 100 * data->zoom, 100 * data->zoom,data->center->x, data->center->y, COLOR);
  mlx_put_image_to_window(data->mlx, data->win, data->img_data->img, 0 , 0);
  return (0);
}

int	destroy_event(t_data *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
  exit(0);
}

int main()
{
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

  ft_draw_square(data, 100 * data->zoom, 100 * data->zoom,data->center->x, data->center->y, COLOR);
  mlx_put_image_to_window(data->mlx, data->win, data->img_data->img, 0,0);

	mlx_hook(data->win, 17, 1L, destroy_event, data);
  mlx_mouse_hook(data->win, handle_mouse_click, data);
  mlx_loop(data->mlx);
  return 0;
}
