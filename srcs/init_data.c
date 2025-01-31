/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:32:00 by znajdaou          #+#    #+#             */
/*   Updated: 2025/01/31 19:08:39 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_data	*ft_init_data(t_data *data,t_fractol selected)
{
  data = ft_allocate_data(data);
  if (!data)
    return (NULL);
  data->fractol = selected;
  data->zoom = 1;
  data->zoom_inc = ZOOM_INCREMENT;
  data->center->x = WIDTH / 2;
  data->center->y = HEIGHT / 2;
  data->errno = ERR_SUCCESS;
  return (data);
}

t_data *ft_allocate_data(t_data *data)
{
  t_cor *center;
  t_cor *cor;
  t_img_data *img_data;

	data = ft_calloc(sizeof(t_data), 1);
  if (!data)
    return (NULL);
	center = ft_calloc(sizeof(t_cor), 1);
  if (!center)
    return (free(data),NULL);
	cor = ft_calloc(sizeof(t_cor), 1);
  if (!cor)
    return (free(data), free(center), NULL);
	img_data = ft_calloc(sizeof(t_img_data), 1);
  if (!img_data)
    return (free(data), free(center), free(cor), NULL);
  data->center = center;
  data->img_data = img_data;
  data->cor = cor;
  return data;
}
