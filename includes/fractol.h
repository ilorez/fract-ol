/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:51:23 by znajdaou          #+#    #+#             */
/*   Updated: 2025/01/31 16:42:20 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

#define WIDTH 500
#define

// includes
#include "libft.h"

// fractol
typedef enum s_fractol
{
  NO_SELECT = 0,
	F_JULIA,
	F_MANDELBROT
}				t_fractol;

// structs

typedef struct s_cor
{
	int			x;
	int			y;
}				t_cor;

typedef struct s_img_data
{
	void		*img;
	char		*addr;
	int			bpp;
	int			ll;
	int			endian;
}				t_img_data;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	double		zoom;
	double		zoom_inc;
	t_fractol	fractol;
	t_cor		*center;
	t_img_data	*img_data;
	t_cor		*cor;
	t_errno		errno;
}				t_data;

// functions

// init data
t_data	*ft_init_data(t_data *data,t_fractol selected);
t_data *ft_allocate_data(t_data *data);

// print syntax error
void	ft_print_syntax_usage(char *program_name);

//  on_errors
void ft_exit_error(char *msg, t_errno err);

#endif
