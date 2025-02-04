/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:21:46 by znajdaou          #+#    #+#             */
/*   Updated: 2025/02/04 13:50:50 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_exit_error(char *msg, t_errno err)
{
	ft_perror(msg, err);
	exit(err);
}

void	ft_handel_exit(t_data *data, t_errno err)
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

void	ft_handle_window_exit(t_data *data, t_errno err)
{
	mlx_destroy_image(data->mlx, data->img_data->img);
	mlx_destroy_window(data->mlx, data->win);
	free(data->mlx);
	ft_handel_exit(data, err);
}
