/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:19:11 by znajdaou          #+#    #+#             */
/*   Updated: 2025/01/28 19:04:32 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
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
  void *img;
  t_cor *cor;
}				t_data;



void ft_put_pixel(t_img_data *data, t_cor *cor, int color)
{
  char *dst;

  dst = data->addr + cor->y * data->ll + cor->x * (data->bpp / 8);
  *(unsigned int*)dst = color;
}

// return img
void *ft_draw_square(t_data *data, int width, int hieght, int color)
{
  t_cor *cor;
  t_img_data *img_data;
  
  cor = ft_calloc(sizeof(t_cor), 1);
  img_data = ft_calloc(sizeof(t_img_data), 1);
  img_data->img = mlx_new_image(data->mlx, width, width);
  img_data->addr = mlx_get_data_addr(img_data->img, &img_data->bpp, &img_data->ll, &img_data->endian);

  cor->x = -1;
  while (++cor->x < width)
  {
    cor->y = -1;
    while (++cor->y < hieght)
      ft_put_pixel(img_data, cor, color);
  }
  return img_data->img;
}

int	key_hook(int keycode, t_data *data)
{
  if (ft_strchr("wasd", keycode))
  {
    mlx_clear_window(data->mlx, data->win);
    mlx_put_image_to_window(data->mlx, data->win, data->img, data->cor->x,data->cor->y);
    if (keycode == 'w' && data->cor->y > 10)
      (data->cor->y)-=10;
    else if (keycode == 'a' && data->cor->x > 10)
      (data->cor->x)-=10;
    else if (keycode == 's' && data->cor->y < HEIGHT - 10)
      (data->cor->y)+=10;
    else if (keycode == 'd' && data->cor->x < WIDTH - 10)
      (data->cor->x)+=10;
  }

}

int main()
{
  t_data *data;
  t_cor *cor;

  data = ft_calloc(sizeof(t_data), 1);
  cor = ft_calloc(sizeof(t_cor), 1);
  data->mlx = mlx_init();
  data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "moving obj");
  data->img  = ft_draw_square(data, 100, 100, COLOR);
  data->cor = cor;


  mlx_key_hook(data->win, key_hook, data);
	mlx_loop(data->mlx);
}
