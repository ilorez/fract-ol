/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:22:45 by znajdaou          #+#    #+#             */
/*   Updated: 2025/02/01 16:53:03 by znajdaou         ###   ########.fr       */
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
  int itr;
  double zx;
  double zy;
  double x;
  double y;
} t_mdb_equation; 

// z = z^2 + c
// c = x + yi;
// z^2 = (x + yi)^2
// Z^2 = (x^2 - y^2) + 2xyi;
// zx = real part in Z => (x^2 - y^2)
// zy = imaginary part in Z => 2xyi

void ft_next_itr(t_mdb_equation *Z)
{
  Z->zx = Z->zx*Z->zx - Z->zy*Z->zy + Z->x;
  Z->zy = 2*Z->zx*Z->zy + Z->y;
  Z->itr++;
}

t_bool ft_is_escape(double x, double y)
{
  return !(x < 2 && x > -2 && y < 2 && y > -2);
}

int ft_get_color(int iterations)
{
  return 0xFFFFFFFF + 0 * iterations;
}

int ft_calculate_color(double x, double yi)
{
  t_mdb_equation Z;
  int max_itr = 10;


  Z.itr = 0;
  Z.zx = 0;
  Z.zy = 0;
  Z.x = x;
  Z.y = yi;
  while (max_itr--)
  {
    ft_next_itr(&Z);
    if(ft_is_escape(Z.zx, Z.zy))
      return (ft_get_color(Z.itr));
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
  printf("%f\n", data->zoom);
  while (data->cor->x < WIDTH)
  {
    data->cor->y = -1;
    x = (data->cor->x - data->center->x) / (100 * data->zoom);
    while(++data->cor->y < HEIGHT)
    {
      y = (data->cor->y - data->center->y) / (100 * data->zoom);
      color = ft_calculate_color(x, y);
      ft_put_pixel(data->img_data, data->cor, color);
    }
    data->cor->x++;
  }
}
