/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:01:08 by znajdaou          #+#    #+#             */
/*   Updated: 2025/02/03 14:37:52 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SETTINGS_H
#define SETTINGS_H

#define WIDTH 400
#define HEIGHT 400
#define ZOOM_INCREMENT 1.3
#define ZOOM_MIN 1
#define ZOOM_MAX 18000000 
#define DEFAULT_ITERATIONS 42
#define MAX_ITERATIONS 421337
#define END_COLOR  0x00FF00  
#define START_COLOR  0x0055FF
#define BLACK 0x000000

// keys enums
typedef enum s_keys
{
  KEY_LEFT = 65361,
  KEY_UP,
  KEY_RIGHT,
  KEY_DOWN,
  ZOOM_IN = 4, 
  ZOOM_OUT,
  KEY_ESC = 65307
} t_keys;

#endif



