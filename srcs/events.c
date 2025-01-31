/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:44:16 by znajdaou          #+#    #+#             */
/*   Updated: 2025/01/31 18:55:02 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int ft_destroy_event(t_data *data)
{
    mlx_destroy_image(data->mlx, data->img_data->img);
    mlx_destroy_window(data->mlx, data->win);
    free(data->mlx);
    ft_handel_exit(data, ERR_SUCCESS);
    return (0);
}

int ft_handle_mouse_click(int key, int x, int y, t_data *data)
{
    if (key == ZOOM_IN)
    {
      data->center->x = x + (data->center->x - x) * 1.1;
      data->center->y = y + (data->center->y - y) * 1.1;
      data->zoom *= 1.1;
    }
    else if (key == ZOOM_OUT)
    {
      data->center->x = x + (data->center->x - x) / 1.1;
      data->center->y = y + (data->center->y - y) / 1.1;
      data->zoom /= 1.1;
    }

    ft_bzero(data->img_data->addr, WIDTH * HEIGHT * data->img_data->bpp / 8);
    if (!ft_draw_fractol(data))
        ft_handle_window_exit(data, ERR_UNKNOWN);
    return 0;
}
