/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwingrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 02:24:50 by mwingrov          #+#    #+#             */
/*   Updated: 2017/12/01 19:59:09 by mwingrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/wolf3d.h"

t_map		ft_updown(t_map *z)
{
	if (z->event.type == SDL_KEYDOWN)
	{
		if (z->event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
			exit(1);
		if (z->event.key.keysym.scancode == SDL_SCANCODE_UP)
		{
			if (z->res[(int)(z->posx + z->dirx *
						z->movespeed)][(int)(z->posy)] == 0)
				z->posx += z->dirx * z->movespeed;
			if (z->res[(int)(z->posx)][(int)(z->posy +
						z->diry * z->movespeed)] == 0)
				z->posy += z->diry * z->movespeed;
		}
		if (z->event.key.keysym.scancode == SDL_SCANCODE_DOWN)
		{
			if (z->res[(int)(z->posx - z->dirx *
						z->movespeed)][(int)(z->posy)] == 0)
				z->posx -= z->dirx * z->movespeed;
			if (z->res[(int)(z->posx)][(int)(z->posy -
						z->diry * z->movespeed)] == 0)
				z->posy -= z->diry * z->movespeed;
		}
	}
	return (*z);
}

t_map		ft_leftright(t_map *z)
{
	if (z->event.key.keysym.sym == SDLK_d ||
			z->event.key.keysym.scancode == SDL_SCANCODE_RIGHT)
	{
		z->olddirx = z->dirx;
		z->dirx = z->dirx * cos(-z->rotspeed) - z->diry * sin(-z->rotspeed);
		z->diry = z->olddirx * sin(-z->rotspeed) + z->diry * cos(-z->rotspeed);
		z->oldplanex = z->planex;
		z->planex = z->planex * cos(-z->rotspeed) -
			z->planey * sin(-z->rotspeed);
		z->planey = z->oldplanex * sin(-z->rotspeed) +
			z->planey * cos(-z->rotspeed);
	}
	if (z->event.key.keysym.sym == SDLK_a ||
			z->event.key.keysym.scancode == SDL_SCANCODE_LEFT)
	{
		z->olddirx = z->dirx;
		z->dirx = z->dirx * cos(z->rotspeed) - z->diry * sin(z->rotspeed);
		z->diry = z->olddirx * sin(z->rotspeed) + z->diry * cos(z->rotspeed);
		z->oldplanex = z->planex;
		z->planex = z->planex * cos(z->rotspeed) -
			z->planey * sin(z->rotspeed);
		z->planey = z->oldplanex * sin(z->rotspeed) +
			z->planey * cos(z->rotspeed);
	}
	return (*z);
}

t_map		keypress(t_map *z)
{
	z->x = 0;
	z->oldtime = z->time;
	z->time = SDL_GetTicks();
	z->frametime = (z->time - z->oldtime) / 1000.0;
	SDL_RenderPresent(z->rend);
	SDL_SetRenderDrawColor(z->rend, 0, 0, 0, 255);
	SDL_RenderClear(z->rend);
	z->movespeed = z->frametime * 5.0;
	z->rotspeed = z->frametime * 3.0;
	while (SDL_PollEvent(&z->event))
	{
		if (z->event.type == SDL_QUIT)
			z->quit = 1;
		ft_updown(z);
		ft_leftright(z);
	}
	return (*z);
}
