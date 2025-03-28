/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:51:23 by znajdaou          #+#    #+#             */
/*   Updated: 2025/02/07 12:30:41 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

// includes
# include <math.h>
# include <mlx.h>

// local libs
# include "libft.h"
# include "settings.h"

// fractol
typedef enum s_fractol
{
	NO_SELECT = 0,
	F_JULIA,
	F_MANDELBROT,
	F_BURNING_SHIP
}				t_fractol;

typedef enum s_theme
{
	TH_DEFAULT = 0,
	TH_GRAY,
	TH_BLUE,
	TH_GREEN,
	TH_RED,
	TH_AQUA,
	TH_YELLOW,
	TH_PINK
}				t_theme;

// structs
typedef struct s_cor
{
	double		x;
	double		y;
}				t_cor;

typedef struct s_img_data
{
	void		*img;
	char		*addr;
	int			bpp;
	int			ll;
	int			endian;
}				t_img_data;

typedef struct s_mdb_equation
{
	double		x;
	double		y;
	int			itr;
}				t_mdb_equation;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	double		zoom;
	double		zoom_inc;
	double		setx;
	double		sety;
	int			itr;
	t_theme		theme;
	t_fractol	fractol;
	t_cor		*center;
	t_img_data	*img_data;
	t_cor		*cor;
	t_errno		errno;
}				t_data;

// functions

// fractol
t_fractol		ft_get_selected(char *name);

// init data
t_data			*ft_init_data(t_data *data, t_fractol selected, char **av);
t_data			*ft_allocate_data(t_data *data);

// print syntax error
void			ft_print_syntax_usage(char *program_name);

//  on_errors
void			ft_exit_error(char *msg, t_errno err);
void			ft_handel_exit(t_data *data, t_errno err);
void			ft_handle_window_exit(t_data *data, t_errno err);
void			ft_free_data(t_data *data);

// rewrite mlx fucntions
char			*ft_mlx_get_data_addr(t_img_data *d);
void			ft_put_pixel(t_img_data *data, t_cor *cor, int color);

// events
int				ft_destroy_event(t_data *data);
int				ft_handle_mouse_click(int key, int x, int y, t_data *data);
int				ft_key_hook(int keycode, t_data *data);
int				ft_loop_hook(t_data *data);

// create window
t_bool			ft_create_mlx_window(t_data *data);

// draw fractol
t_bool			ft_draw_fractol(t_data *data);

// fractols
int				ft_julia(t_data *data, double x, double y);
int				ft_mandelbrot(t_data *data, double x, double y);
int				ft_burning_ship(t_data *data, double x, double y);
int				ft_degree_color(t_data *data, int itr);

// utils
// ft_walk function is a function that go in all pixel in scree
// and send to fun()
// fun() return a color that curent pixel in loop should colored with
void			ft_walk(t_data *data, int (*fun)(t_data *, double, double));
double			ft_abs(double x);
int				ft_create_trgb(int t, int r, int g, int b);
int				ft_degree_color(t_data *data, int itr);
void			ft_rezero(t_data *data);

#endif
