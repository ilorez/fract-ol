
#include <mlx.h>
#include <math.h>
#include "libft.h"

#define WIDTH 800
#define HEIGHT 800
#define SQUARE 100
#define CENTER_X WIDTH / 2
#define CENTER_Y HEIGHT / 2
#define COLOR 0x00FF0000 // Red color in ARGB format


typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_cor {
	int		x;
	int		y;
}				t_cor;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
  t_cor *cor;
	t_data	*img;


  cor = ft_calloc(sizeof(t_cor), 1);
  img = ft_calloc(sizeof(t_data), 1);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "Hello world!");
	img->img = mlx_new_image(mlx, SQUARE,  SQUARE);
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel), &(img->line_length),
								&(img->endian));

  cor->x = -1;
  cor->y = -1;
  while (++(cor->x) < SQUARE)
  {
    cor->y = -1;
    while (++(cor->y) < SQUARE)
      if (cor->x * cor->x + cor->y * cor->y <= SQUARE * SQUARE )
        my_mlx_pixel_put(img, cor->x, cor->y, COLOR);
  }
	mlx_put_image_to_window(mlx, mlx_win, img->img, (WIDTH/2 - SQUARE/2), (HEIGHT/2 - SQUARE /2));
	mlx_loop(mlx);
}
