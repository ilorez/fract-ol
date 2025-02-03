/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:22:45 by znajdaou          #+#    #+#             */
/*   Updated: 2025/02/03 12:12:58 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


void draw_circle(t_data *data, double radius, int color) {
    double angle = 0;
    double angle_increment = 1.0 / radius;

    while (angle < 2 * M_PI) {
        data->cor->x = data->center->x + radius * cos(angle);
        data->cor->y = data->center->y + radius * sin(angle);
        ft_put_pixel(data->img_data, data->cor, color);
        angle += angle_increment;
    }
}

void draw_mandelbrot(t_data *data);

t_bool ft_draw_fractol(t_data *data)
{
  //draw_circle(data, 50 * data->zoom, 0x00FF0000);
  draw_mandelbrot(data);
  ft_printf("ooo\n");
  mlx_put_image_to_window(data->mlx, data->win, data->img_data->img, 0, 0);
  return (true);
}

// now i have all things x and y 
// we know that in mandelbrot c = x + yi
// at start z = 0;
// and change using formula z = z^2 + c;
// Tasks
//  - create a function that get the corrent color based on x & y;
//  - this function should call other function that use recuresion
//  to find that if that number is outside or inside mandelbrot
//  and return a number represent how fast this number to infinty
//  - the return value should use to find the corrent color use mod(%) or another way
//  - and just you got the color just go to next pixel

typedef struct s_mdb_equation
{
  double x;
  double y;
  int itr;
} t_mdb_equation; 

// z = z^2 + c
// c = x + yi;
// z^2 = (x + yi)^2
// Z^2 = (x^2 - y^2) + 2xyi;
// zx = real part in Z => (x^2 - y^2)
// zy = imaginary part in Z => 2xyi

int ft_calculate_color(t_data *data, double x, double y)
{
  t_mdb_equation Z;
  double tmpzx;

  Z.x = 0;
  Z.y = 0;
  Z.itr = 0;
  while (Z.itr < data->itr)
  {
    tmpzx = (Z.x*Z.x - Z.y*Z.y) + x;
    Z.y = 2*Z.x*Z.y + y;
    Z.x = tmpzx;
    if(Z.x*Z.x + Z.y*Z.y > 4)// is escape
      return ((WHITE - BLACK) * Z.itr / DEFAULT_ITERATIONS + BLACK);
    Z.itr++;
  }
  return (0x00000000);
}

#include <stdio.h>
void draw_mandelbrot(t_data *data)
{
  double x;
  double y;
  int color;

  x = 0;
  y = 0;
  data->cor->x = 0;
  data->cor->y = 0;
  printf("%f\n", data->zoom);
  while (data->cor->x < WIDTH)
  {
    data->cor->y = -1;
    x = (data->cor->x - data->center->x) / (100 * data->zoom);
    while(++data->cor->y < HEIGHT)
    {
      y = (data->cor->y - data->center->y) / (100 * data->zoom);
      color = ft_calculate_color(data, x, y);
      ft_put_pixel(data->img_data, data->cor, color);
    }
    data->cor->x++;
  }
}
