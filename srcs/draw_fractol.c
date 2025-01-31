/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:22:45 by znajdaou          #+#    #+#             */
/*   Updated: 2025/01/31 19:14:57 by znajdaou         ###   ########.fr       */
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
