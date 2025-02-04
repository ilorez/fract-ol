/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:32:00 by znajdaou          #+#    #+#             */
/*   Updated: 2025/02/04 13:36:32 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "stdio.h"

double ft_strtod(const char *nptr, char **endptr)
{
	unsigned long long				div;
	int					signe;
	double	re;

	signe = 1;
  div = 10;
	re = 0.0;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
		if (*nptr++ == '-')
			signe = -1;
	while (ft_isdigit(*nptr))
		re = re * 10 + (*nptr++ - 48);
  if (*nptr == '.')
    nptr++;
	while (ft_isdigit(*nptr))
  {
		re += (double)(*nptr++ - 48)/div;
    if (div * 10 > LLONG_MAX)
      break;
    div *= 10;
  }
  if (*nptr)
    *endptr = (char *)nptr;
	return (re * signe);
}

t_data	*ft_init_data(t_data *data,t_fractol selected, char **av)
{
  char *is_anyleft;

  data = ft_allocate_data(data);
  if (!data)
    return (NULL);
  if (selected == F_JULIA)
  {
    is_anyleft = NULL;
    data->setx = ft_strtod(av[2], &is_anyleft); // TODO
    // if data->setx > choose a number return error number so big
    //
    printf("setx=>%lf\n", data->setx);
    if (is_anyleft)
    {
      //ft_free_data(data); // TODO
      ft_exit_error("Error", ERR_INVALID_ARG);
    }
    data->sety = 0.008;
  }
  data->fractol = selected;
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
