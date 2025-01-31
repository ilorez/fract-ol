/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:01:08 by znajdaou          #+#    #+#             */
/*   Updated: 2025/01/31 18:53:08 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SETTINGS_H
#define SETTINGS_H

#define WIDTH 500
#define HEIGHT 500
#define ZOOM_INCREMENT 500

// keys enums
typedef enum s_moves
{
  KEY_UP,
  KEY_DOWN,
  KEY_LEFT,
  KEY_RIGHT,
  ZOOM_IN, 
  ZOOM_OUT
} t_moves;

#endif



