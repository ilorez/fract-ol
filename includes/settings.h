/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:01:08 by znajdaou          #+#    #+#             */
/*   Updated: 2025/02/03 16:00:37 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SETTINGS_H
#define SETTINGS_H

#define WIDTH 1000
#define HEIGHT 1000
#define ZOOM_INCREMENT 1.3
#define ZOOM_MIN 1
#define ZOOM_MAX 1800000000 
#define DEFAULT_ITERATIONS 42
#define MAX_ITERATIONS 42133700
#define END_COLOR  0xFFFFFF  
#define START_COLOR  0x000000
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



