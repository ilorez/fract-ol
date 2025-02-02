/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:44:16 by znajdaou          #+#    #+#             */
/*   Updated: 2025/02/01 21:58:30 by znajdaou         ###   ########.fr       */
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
      if (data->zoom * data->zoom_inc> ZOOM_MAX)
          return (0);
      data->center->x = x + (data->center->x - x) * data->zoom_inc;
      data->center->y = y + (data->center->y - y) * data->zoom_inc;
      data->zoom *= data->zoom_inc;
    }
    else if (key == ZOOM_OUT)
    {
      if (data->zoom / data->zoom_inc < ZOOM_MIN)
          return (0);
      data->center->x = x + (data->center->x - x) / data->zoom_inc;
      data->center->y = y + (data->center->y - y) / data->zoom_inc;
      data->zoom /= data->zoom_inc;
    }
    else 
      return (0);
    ft_bzero(data->img_data->addr, WIDTH * HEIGHT * data->img_data->bpp / 8);
    if (!ft_draw_fractol(data))
        ft_handle_window_exit(data, ERR_UNKNOWN);
    return 0;
}

// okay no thing checked here 
int ft_key_hook(int keycode, t_data *data)
{
    ft_printf("key: %d\n", keycode);
    if (keycode == KEY_UP) // w
        data->center->y += 5;
    else if (keycode == KEY_LEFT) // a
        data->center->x += 5;
    else if (keycode == KEY_DOWN) // s
        data->center->y -= 5;
    else if (keycode == KEY_RIGHT) // d
        data->center->x -= 5;
    else if (keycode == KEY_ESC) // ESC 65307
        ft_handle_window_exit(data, ERR_SUCCESS);
    else
        return 0;
    ft_bzero(data->img_data->addr, WIDTH * HEIGHT * data->img_data->bpp / 8);
    if (!ft_draw_fractol(data))
        ft_handle_window_exit(data, ERR_UNKNOWN);
    return 0;
}
