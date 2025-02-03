/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:51:23 by znajdaou          #+#    #+#             */
/*   Updated: 2025/02/03 11:26:18 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

// includes
#include <mlx.h>
#include <math.h>

// local libs
#include "libft.h"
#include "settings.h"

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
  int itr;
	t_fractol	fractol;
	t_cor		*center;
	t_img_data	*img_data;
	t_cor		*cor;
	t_errno		errno;
}				t_data;

// functions

// fractol 
t_fractol ft_get_selected(char *name);

// init data
t_data	*ft_init_data(t_data *data,t_fractol selected);
t_data *ft_allocate_data(t_data *data);

// print syntax error
void	ft_print_syntax_usage(char *program_name);

//  on_errors
void ft_exit_error(char *msg, t_errno err);
void ft_handel_exit(t_data *data, t_errno err);
void ft_handle_window_exit(t_data *data, t_errno err);

// rewrite mlx fucntions
char *ft_mlx_get_data_addr(t_img_data *d);
void	ft_put_pixel(t_img_data *data, t_cor *cor,int color);

// events
int ft_destroy_event(t_data *data);
int ft_handle_mouse_click(int key, int x, int y, t_data *data);
int ft_key_hook(int keycode, t_data *data);

// create window
t_bool ft_create_mlx_window(t_data *data);

// draw fractol
t_bool ft_draw_fractol(t_data *data);

#endif
