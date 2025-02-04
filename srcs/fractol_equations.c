/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_equations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:23:04 by znajdaou          #+#    #+#             */
/*   Updated: 2025/02/04 11:50:41 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int ft_degree_color(int itr)
{
  return ((END_COLOR - START_COLOR) * itr / DEFAULT_ITERATIONS + START_COLOR);
}

int ft_mandelbrot(t_data *data, double x, double y)
{
  t_mdb_equation Z;
  double tmpzx;

  Z.x = 0;
  Z.y = 0;
  Z.itr = -1;
  while (++Z.itr < data->itr)
  {
    if(Z.x*Z.x + Z.y*Z.y > 4)
      return (ft_degree_color(Z.itr));
    tmpzx = (Z.x*Z.x - Z.y*Z.y) + x;
    Z.y = 2*Z.x*Z.y + y;
    Z.x = tmpzx;
  }
  return (INSIDE_COLOR);
}

int ft_julia(t_data *data, double x, double y)
{
  t_mdb_equation Z;
  double tmpzx;

  Z.x = x;
  Z.y = y;
  Z.itr = -1;
  while (++Z.itr < data->itr)
  {
    if(Z.x*Z.x + Z.y*Z.y > 4)
      return (ft_degree_color(Z.itr));
    tmpzx = (Z.x*Z.x - Z.y*Z.y) + data->setx;
    Z.y = 2*Z.x*Z.y + data->sety;
    Z.x = tmpzx;
  }
  return (INSIDE_COLOR);
}

int ft_burning_ship(t_data *data, double x, double y)
{
  t_mdb_equation Z;
  double tmpzx;

  Z.x = x;
  Z.y = y;
  Z.itr = -1;
  while (++Z.itr < data->itr)
  {
    if(Z.x*Z.x + Z.y*Z.y > 4)
      return (ft_degree_color(Z.itr));
    tmpzx = (Z.x*Z.x - Z.y*Z.y) + x;
    Z.y = ft_abs(2*Z.x*Z.y) + y;
    Z.x = tmpzx;
  }
  return (INSIDE_COLOR);
}

