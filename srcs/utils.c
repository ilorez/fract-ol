/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:21:45 by znajdaou          #+#    #+#             */
/*   Updated: 2025/02/07 12:14:22 by znajdaou         ###   ########.fr       */
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
		x = (data->cor->x - data->center->x) / (200 * data->zoom);
		while (++data->cor->y < HEIGHT)
		{
			y = (data->cor->y - data->center->y) / (200 * data->zoom);
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

int	ft_create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	ft_degree_color(t_data *data, int itr)
{
	int	degree;

	degree = (255 * itr / DEFAULT_ITERATIONS);
	if (data->theme == TH_GRAY)
		return (ft_create_trgb(0, degree, degree, degree));
	else if (data->theme == TH_BLUE)
		return (ft_create_trgb(0, 0, 0, degree));
	else if (data->theme == TH_GREEN)
		return (ft_create_trgb(0, 0, degree, 0));
	else if (data->theme == TH_RED)
		return (ft_create_trgb(0, degree, 0, 0));
	else if (data->theme == TH_AQUA)
		return (ft_create_trgb(0, 0, degree, degree));
	else if (data->theme == TH_YELLOW)
		return (ft_create_trgb(0, degree, degree, 0));
	else if (data->theme == TH_PINK)
		return (ft_create_trgb(0, degree, 0, degree));
	return ((END_COLOR - START_COLOR) * itr / DEFAULT_ITERATIONS + START_COLOR);
}
