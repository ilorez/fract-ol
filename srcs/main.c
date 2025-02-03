/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:41:18 by znajdaou          #+#    #+#             */
/*   Updated: 2025/02/03 18:45:56 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_fractol	selected;
	t_data		*data;

  data = NULL;
	if (ac < 2 || !av[1][0])
		ft_print_syntax_usage(av[0]);
	selected = ft_get_selected(av[1]);
  if ((selected == F_JULIA && ac != 4) || (selected != F_JULIA && ac != 2))
		ft_print_syntax_usage(av[0]);
  if (!selected)
		ft_print_syntax_usage(av[0]);
	data = ft_init_data(data, selected, av);
	if (!data)
		ft_exit_error("Error Malloc", ERR_MALLOC_FAIL);
	if (!ft_create_mlx_window(data))
		ft_handel_exit(data, ERR_UNKNOWN);
	if (!ft_draw_fractol(data))
		ft_handel_exit(data, ERR_UNKNOWN);
  mlx_loop(data->mlx);
	return (0);
}

t_fractol ft_get_selected(char *name)
{
  if (ft_strncmp(ft_strlowcase(name), "julia", 6) == 0)
    return (F_JULIA);
  if (ft_strncmp(ft_strlowcase(name), "mandelbrot", 11) == 0)
    return (F_MANDELBROT);
  if (ft_strncmp(ft_strlowcase(name), "burning_ship", 13) == 0)
    return (F_BURNING_SHIP);
    
  return (NO_SELECT);
}
