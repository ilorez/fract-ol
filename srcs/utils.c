/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:21:45 by znajdaou          #+#    #+#             */
/*   Updated: 2025/02/03 16:47:37 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_walk(t_data *data, int (*fun)(t_data *, double, double))
{
	double	x;
	double	y;

	data->cor->x = 0;
	data->cor->y = 0;
	while (data->cor->x < WIDTH)
	{
		data->cor->y = -1;
		x = (data->cor->x - data->center->x) / (100 * data->zoom);
		while (++data->cor->y < HEIGHT)
		{
			y = (data->cor->y - data->center->y) / (100 * data->zoom);
			ft_put_pixel(data->img_data, data->cor, fun(data, x, y));
		}
		data->cor->x++;
	}
}

double	ft_abs(double x)
{
	if (x < 0)
		return (x * -1);
	return (x);
}
