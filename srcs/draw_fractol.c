/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:22:45 by znajdaou          #+#    #+#             */
/*   Updated: 2025/02/04 13:51:52 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_bool	ft_draw_fractol(t_data *data)
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
