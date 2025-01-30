/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:41:18 by znajdaou          #+#    #+#             */
/*   Updated: 2025/01/30 17:01:14 by znajdaou         ###   ########.fr       */
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
  if (ac == 1)
    ft_print_syntax_usage();


  return 0;
}
