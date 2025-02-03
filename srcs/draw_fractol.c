/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:22:45 by znajdaou          #+#    #+#             */
/*   Updated: 2025/02/03 16:47:34 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
void draw_circle(t_data *data, double radius, int color) {
    double angle = 0;
    double angle_increment = 1.0 / radius;

    while (angle < 2 * M_PI) {
        data->cor->x = data->center->x + radius * cos(angle);
        data->cor->y = data->center->y + radius * sin(angle);
        ft_put_pixel(data->img_data, data->cor, color);
        angle += angle_increment;
    }
}*/
//draw_circle(data, 50 * data->zoom, 0x00FF0000);


t_bool ft_draw_fractol(t_data *data)
{
  if (data->fractol == F_MANDELBROT)
    ft_walk(data, &ft_mandelbrot);
  else if (data->fractol == F_JULIA)
    ft_walk(data, &ft_julia);
  else if (data->fractol == F_BURNING_SHIP)
    ft_walk(data, &ft_burning_ship);
  mlx_put_image_to_window(data->mlx, data->win, data->img_data->img, 0, 0);
  return (true);
}
