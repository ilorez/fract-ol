/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rewrite_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:24:20 by znajdaou          #+#    #+#             */
/*   Updated: 2025/01/31 18:59:03 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

char	*ft_mlx_get_data_addr(t_img_data *d)
{
	return (mlx_get_data_addr(d->img, &d->bpp, &d->ll, &d->endian));
}

void	ft_put_pixel(t_img_data *data, t_cor *cor,int color)
{
	char	*dst;

	if (cor->x >= 0 && cor->x < WIDTH && cor->y >= 0 && cor->y < HEIGHT)
	{
		dst = data->addr + cor->y * data->ll + cor->x * (data->bpp / 8);
		*(unsigned int *)dst = color;
	}
}
