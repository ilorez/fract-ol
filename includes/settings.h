/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:01:08 by znajdaou          #+#    #+#             */
/*   Updated: 2025/02/03 10:44:52 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SETTINGS_H
#define SETTINGS_H

#define WIDTH 400
#define HEIGHT 400
#define ZOOM_INCREMENT 1.1
#define ZOOM_MIN 0.000001
#define ZOOM_MAX 10000

#define BLACK  0x000000  // RGB(0,0,0)
#define WHITE  0xFFFFFF  // RGB(255,255,255)
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



