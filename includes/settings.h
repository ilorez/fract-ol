/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:01:08 by znajdaou          #+#    #+#             */
/*   Updated: 2025/02/07 16:59:13 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETTINGS_H
# define SETTINGS_H

# define WIDTH 500
# define HEIGHT 500
# define ZOOM_INCREMENT 1.1
# define ZOOM_MIN 0.01
# define ZOOM_MAX 1844674407370955161
# define DEFAULT_ITERATIONS 42
# define MAX_ITERATIONS 42133700
# define START_COLOR 0xFFFFFF
# define END_COLOR 0x000000
# define INSIDE_COLOR 0x000000
# define MOVE_STEP_SIZE 10
# define ITRATIONS_INC 40

// keys enums
typedef enum s_keys
{
	KEY_ITR_INC = 1,
	KEY_REZERO,
	KEY_ITR_DEC,
	ZOOM_IN,
	ZOOM_OUT,
	KEY_0 = 48,
	KEY_1,
	KEY_2,
	KEY_3,
	KEY_4,
	KEY_5,
	KEY_6,
	KEY_7,
	KEY_8,
	KEY_9,
	KEY_PRINT_ZOOM = 'z',
	KEY_PRINT_ITR = 'i',
	KEY_ESC = 65307,
	KEY_LEFT = 65361,
	KEY_UP,
	KEY_RIGHT,
	KEY_DOWN
}	t_keys;

#endif
