/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_equations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:23:04 by znajdaou          #+#    #+#             */
/*   Updated: 2025/02/07 12:14:19 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_mandelbrot(t_data *data, double x, double y)
{
	t_mdb_equation	z;
	double			tmpzx;

	z.x = 0;
	z.y = 0;
	z.itr = -1;
	while (++z.itr < data->itr)
	{
		if (z.x * z.x + z.y * z.y > 4)
			return (ft_degree_color(data, z.itr));
		tmpzx = (z.x * z.x - z.y * z.y) + x;
		z.y = 2 * z.x * z.y + y;
		z.x = tmpzx;
	}
	return (INSIDE_COLOR);
}

int	ft_julia(t_data *data, double x, double y)
{
	t_mdb_equation	z;
	double			tmpzx;

	z.x = x;
	z.y = y;
	z.itr = -1;
	while (++z.itr < data->itr)
	{
		if (z.x * z.x + z.y * z.y > 4)
			return (ft_degree_color(data, z.itr));
		tmpzx = (z.x * z.x - z.y * z.y) + data->setx;
		z.y = 2 * z.x * z.y + data->sety;
		z.x = tmpzx;
	}
	return (INSIDE_COLOR);
}

int	ft_burning_ship(t_data *data, double x, double y)
{
	t_mdb_equation	z;
	double			tmpzx;

	z.x = x;
	z.y = y;
	z.itr = -1;
	while (++z.itr < data->itr)
	{
		if (z.x * z.x + z.y * z.y > 4)
			return (ft_degree_color(data, z.itr));
		tmpzx = (z.x * z.x - z.y * z.y) + x;
		z.y = ft_abs(2 * z.x * z.y) + y;
		z.x = tmpzx;
	}
	return (INSIDE_COLOR);
}
