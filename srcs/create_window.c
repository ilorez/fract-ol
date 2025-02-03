/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:35:14 by znajdaou          #+#    #+#             */
/*   Updated: 2025/02/03 11:36:46 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"

t_bool ft_create_mlx_window(t_data *data)
{
    data->mlx = mlx_init();
    if (!data->mlx)
        ft_handel_exit(data, ERR_MLX_CONNECTION_FIELED);
    data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Fract-ol");
    data->img_data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
    data->img_data->addr = ft_mlx_get_data_addr(data->img_data);
    mlx_hook(data->win, 17, 1L, ft_destroy_event, data);
    mlx_hook(data->win, 2, 1L, ft_key_hook, data);
    mlx_mouse_hook(data->win, ft_handle_mouse_click, data);
    return (true);
}
