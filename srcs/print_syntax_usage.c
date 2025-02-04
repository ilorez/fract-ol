/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_syntax_usage.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:31:03 by znajdaou          #+#    #+#             */
/*   Updated: 2025/02/04 11:52:36 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_print_syntax_usage(char *program_name)
{
  ft_putstr_fd("usage:\n", STDERR_FILENO);
  ft_putstr_fd("\t", STDERR_FILENO);
  ft_putstr_fd(program_name, STDERR_FILENO);
  ft_putstr_fd(" <*fractol_name>\n", STDERR_FILENO);
  ft_putstr_fd("fractol_names:\n\t- Mandelbrot\n\t- Julia <sets>\n\t- Burning_ship\n", STDERR_FILENO);
  ft_putstr_fd("sets examples:\n\t- 0.28 0.008\n\t- .28 .008\n", STDERR_FILENO);
	exit(1);
}
