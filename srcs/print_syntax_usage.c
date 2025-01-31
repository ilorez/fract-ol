/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_syntax_usage.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:31:03 by znajdaou          #+#    #+#             */
/*   Updated: 2025/01/31 19:05:00 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_print_syntax_usage(char *program_name)
{
  ft_putstr_fd("usage:\n", STDERR_FILENO);
  ft_putstr_fd("\t", STDERR_FILENO);
  ft_putstr_fd(program_name, STDERR_FILENO);
  ft_putstr_fd(" <*fractol_name> <sets>\n", STDERR_FILENO);
  ft_putstr_fd("fractol_names:\n\t- Julia\n\t- Mandelbrot\n", STDERR_FILENO);
	exit(1);
}
