/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:44:16 by znajdaou          #+#    #+#             */
/*   Updated: 2025/02/07 15:43:13 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_loop_hook(t_data *data)
{
	if (!data)
		return (1);
	ft_draw_fractol(data);
	return (0);
}

int	ft_destroy_event(t_data *data)
{
	ft_handle_window_exit(data, ERR_SUCCESS);
	return (0);
}

int	ft_handle_mouse_click(int key, int x, int y, t_data *data)
{
	if (key == KEY_ITR_INC)
		data->itr += ITRATIONS_INC;
	else if (key == KEY_ITR_DEC)
		data->itr -= ITRATIONS_INC;
	else if (key == KEY_REZERO)
		ft_rezero(data);
	else if (key == ZOOM_IN)
	{
		if (data->zoom * data->zoom_inc > ZOOM_MAX)
			return (0);
		data->center->x = x + (data->center->x - x) * data->zoom_inc;
		data->center->y = y + (data->center->y - y) * data->zoom_inc;
		data->zoom *= data->zoom_inc;
	}
	else if (key == ZOOM_OUT)
	{
		if (data->zoom / data->zoom_inc < ZOOM_MIN)
			return (0);
		data->center->x = x + (data->center->x - x) / data->zoom_inc;
		data->center->y = y + (data->center->y - y) / data->zoom_inc;
		data->zoom /= data->zoom_inc;
	}
	return (0);
}

void	ft_change_theme_color(int k, t_data *data)
{
	if (k == KEY_0)
		data->theme = TH_DEFAULT;
	else if (k == KEY_1)
		data->theme = TH_GRAY;
	else if (k == KEY_2)
		data->theme = TH_RED;
	else if (k == KEY_3)
		data->theme = TH_GREEN;
	else if (k == KEY_4)
		data->theme = TH_BLUE;
	else if (k == KEY_5)
		data->theme = TH_AQUA;
	else if (k == KEY_6)
		data->theme = TH_YELLOW;
	else if (k == KEY_7)
		data->theme = TH_PINK;
}

int	ft_key_hook(int keycode, t_data *data)
{
	if (keycode == KEY_UP)
		data->center->y += MOVE_STEP_SIZE;
	else if (keycode == KEY_LEFT)
		data->center->x += MOVE_STEP_SIZE;
	else if (keycode == KEY_DOWN)
		data->center->y -= MOVE_STEP_SIZE;
	else if (keycode == KEY_RIGHT)
		data->center->x -= MOVE_STEP_SIZE;
	else if (keycode == KEY_ESC)
		ft_handle_window_exit(data, ERR_SUCCESS);
	else if (keycode == KEY_PRINT_ITR)
		ft_printf("current Iteration number is => %d\n", data->itr);
	else if (keycode == KEY_PRINT_ZOOM)
		ft_printf("current zoom level is ~= %d\n", (int)(data->zoom));
	ft_change_theme_color(keycode, data);
	return (0);
}
