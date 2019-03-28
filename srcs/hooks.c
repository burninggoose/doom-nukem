/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghalvors <ghalvors@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 15:40:50 by fmacgyve          #+#    #+#             */
/*   Updated: 2019/03/28 23:28:57 by ghalvors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

/*
**	key_press
**	Hooks for pressing keys on keyboard
*/

int	key_press(SDL_Event event, t_doom *doom)
{
	if ((SDL_QUIT == doom->event.type) || (SDL_KEYDOWN == doom->event.type
			&& SDL_SCANCODE_ESCAPE == doom->event.key.keysym.scancode))
		doom->running = 0;
	if (event.type == SDL_KEYDOWN)
	{
		if (event.key.keysym.scancode == SDL_SCANCODE_RIGHT)
			rotate_right(&doom);
		if (event.key.keysym.scancode == SDL_SCANCODE_LEFT)
			rotate_left(&doom);
		if (event.key.keysym.scancode == SDL_SCANCODE_W)
			move_forward(&doom);
		if (event.key.keysym.scancode == SDL_SCANCODE_S)
			move_back(&doom);
		if (event.key.keysym.scancode == SDL_SCANCODE_L)
			if (doom->vertical >= -200)
				doom->vertical -= 20;
		if (event.key.keysym.scancode == SDL_SCANCODE_O)
			if (doom->vertical <= 200)
				doom->vertical += 20;
		return (1);
	}
	doom->changed = 1;
	return (0);
}
