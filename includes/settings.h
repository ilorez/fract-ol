/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:01:08 by znajdaou          #+#    #+#             */
/*   Updated: 2025/02/06 10:05:08 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETTINGS_H
# define SETTINGS_H

# define WIDTH 1000
# define HEIGHT 1000
# define ZOOM_INCREMENT 1.3
# define ZOOM_MIN 1
# define ZOOM_MAX 180000000000000000
# define DEFAULT_ITERATIONS 42
# define MAX_ITERATIONS 42133700
# define START_COLOR 0x00FF00
# define END_COLOR 0x000000
# define INSIDE_COLOR 0x000000
# define MOVE_STEP_SIZE 10

// keys enums
typedef enum s_keys
{
	KEY_LEFT = 65361,
	KEY_UP,
	KEY_RIGHT,
	KEY_DOWN,
	KEY_ITR_INC = 1,
	KEY_ITR_DEC = 3,
	ZOOM_IN,
	ZOOM_OUT,
	KEY_ESC = 65307
}	t_keys;

#endif
