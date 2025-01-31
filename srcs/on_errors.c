/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:21:46 by znajdaou          #+#    #+#             */
/*   Updated: 2025/01/31 16:49:35 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void ft_exit_error(char *msg, t_errno err)
{
  ft_perror(msg, err);
  exit(err);
}

void ft_handel_exit(t_data *data, t_errno err)
{
  if (!data)
    exit(0);
  free(data->center);
  free(data->cor);
  free(data->img_data);
  free(data);
  if (err)
    ft_perror("Error", err);
  exit(err);
}
