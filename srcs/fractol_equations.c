/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:23:04 by znajdaou          #+#    #+#             */
/*   Updated: 2025/02/03 15:27:31 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
// z = z^2 + c
// c = x + yi;
// z^2 = (x + yi)^2
// Z^2 = (x^2 - y^2) + 2xyi;
// zx = real part in Z => (x^2 - y^2)
// zy = imaginary part in Z => 2xyi

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
  return (BLACK);
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
    tmpzx = (Z.x*Z.x - Z.y*Z.y) + 0.28; //data->set->x;
    Z.y = 2*Z.x*Z.y + 0.008;
    Z.x = tmpzx;
  }
  return (BLACK);
}

