/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:01:08 by znajdaou          #+#    #+#             */
/*   Updated: 2025/02/01 11:15:37 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SETTINGS_H
#define SETTINGS_H

#define WIDTH 500
#define HEIGHT 500
#define ZOOM_INCREMENT 1.3

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



