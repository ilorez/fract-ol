/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:32:00 by znajdaou          #+#    #+#             */
/*   Updated: 2025/02/03 19:28:10 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	_ft_isspace(int c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

double ft_strtod(const char *nptr)
{
	size_t				i;
	long int				div;
	int					signe;
	double	re;

	i = 0;
	signe = 1;
  div = 10;
	re = 0;
	while (_ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		if (nptr[i++] == '-')
			signe = -1;
	while (ft_isdigit(nptr[i]))
		re = re * 10 + (nptr[i++] - 48);
  if (nptr[i] == '.')
    i++;
	while (ft_isdigit(nptr[i]))
  {
		re = re + (nptr[i++] - 48)/div;
    div *= 10;
  }
	return ((int)(re * signe));
}

#include "stdio.h"
t_data	*ft_init_data(t_data *data,t_fractol selected, char **av)
{
  data = ft_allocate_data(data);
  if (!data)
    return (NULL);
  data->fractol = selected;
  if (selected == F_JULIA)
  {
    data->setx = ft_strtod(av[2]); // TODO
    data->sety = ft_strtod(av[3]);
    printf("x: %lf\n", data->setx);
    printf("y: %lf\n", data->sety);
  }
  data->zoom = 1;
  data->zoom_inc = ZOOM_INCREMENT;
  data->center->x = WIDTH / 2;
  data->center->y = HEIGHT / 2;
  data->errno = ERR_SUCCESS;
  data->itr = DEFAULT_ITERATIONS;
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
