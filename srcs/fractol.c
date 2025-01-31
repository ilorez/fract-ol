/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:41:18 by znajdaou          #+#    #+#             */
/*   Updated: 2025/01/31 10:56:50 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


typedef struct s_cor {
    int x;
    int y;
} t_cor;

typedef struct s_img_data {
    void *img;
    char *addr;
    int bpp;
    int ll;
    int endian;
} t_img_data;

typedef enum s_fractol
{
  F_JULIA = 1,
  F_MANDERBROT
} t_fractol;


typedef struct s_data {
    void *mlx;
    void *win;
    double zoom;
    t_fractol fractol;
    t_cor *center;
    t_img_data *img_data;
    t_cor *cor;
    t_errno errno;
} t_data;


void ft_print_syntax_usage()
{
  ft_printf("usage:\n");
  exit(1);
}

t_data *fractol_init()
{
  t_data *data;
  data = ft_calloc(sizeof(t_data), 1);


  data->mlx = 

}

int main(int ac, char **av)
{
  t_fractol selected;
  t_data *data;
  if (ac < 2 || !av[1][0])
    ft_print_syntax_usage();
  selected = ft_get_selected(av[1]); 
  data = ft_init_data(data, selected);
  if (!data)
      ft_free_and_show_error(data);
  if (!ft_create_mlx_window(data))
      ft_free_and_show_error(data);
  if (!ft_draw_fractol(data))
      return (1);
  // get params
  // get check if first param contain valid fractol
  // init data using the selected fractol






  return 0;
}
