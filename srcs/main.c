/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 15:19:26 by fmacgyve          #+#    #+#             */
/*   Updated: 2019/03/31 12:25:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

static void	clean_up(t_doom *doom)
{
	int i;

	i = -1;
	while (++i < 6)
		SDL_FreeSurface(doom->textures[i]);
	SDL_FreeSurface(doom->gun);
	Mix_FreeMusic(doom->music);
	Mix_CloseAudio();
	SDL_DestroyWindow(doom->window);
	Mix_Quit();
	SDL_Quit();
}

void		process_error(void)
{
	const char	*sdl_error;

	sdl_error = SDL_GetError();
	if (*sdl_error && *sdl_error != '\n')
		ft_putendl(sdl_error);
	else
		ft_putendl("invalid map");
	exit(0);
}

int			main(int argc, char **argv)
{
	t_doom		*doom;

	if (argc == 2)
	{
		doom = create_doom(argv[1]);
		if (!doom)
			process_error();
		SDL_SetRelativeMouseMode(SDL_TRUE);
		draw_sdl_threads(doom);
		while (doom->running)
			if (SDL_WaitEvent(&(doom->event)) >= 0)
			{
				if (key_press(doom->event, doom)
				|| mouse_movement(doom->event, &doom))
					draw_sdl_threads(doom);
			}
		clean_up(doom);
	}
	else
		ft_putendl("usage: ./doom3d [map_name]");
	return (0);
}
