/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:22:45 by znajdaou          #+#    #+#             */
/*   Updated: 2025/02/01 13:58:02 by znajdaou         ###   ########.fr       */
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

t_bool ft_draw_fractol(t_data *data)
{
  draw_circle(data, 50 * data->zoom, 0x00FF0000);
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

int ft_calculate_color(double z, double oldz, double x, double y, int op)
{
  if (z < -2 || z > 2)
          return (z - oldz);
  z = 
  return (ft_calculate_color(z * z, z, x, y, ))
}

void draw_mandelbrot(t_data *data)
{
  double x;
  double y;
  int color;

  x = 0;
  y = 0;
  while (data->cor->x < WIDTH)
  {
    data->cor->y = -1
    x = (data->cor->x - data->center->x) / (100 * data->zoom);
    while(++data->cor->y < HEIGHT)
    {
      y = (data->cor->y - data->center->y) / (100 * data->zoom);
      color = ft_calculate_color(0.0, 0.0, x, y, 1);
      ft_put_pixel(data->img_data, data->cor, color);
    }
    data->cor->x++;
  }
}
