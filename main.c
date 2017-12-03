/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwingrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 20:17:39 by mwingrov          #+#    #+#             */
/*   Updated: 2017/12/02 05:34:00 by mwingrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/wolf3d.h"
#include <stdio.h>

int				ft_error_handel(t_map *z)
{
	z->quit = 0;
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		return (1);
	z->win = SDL_CreateWindow("Wolf3D!", SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			640, 480, 0);
	z->render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
	z->rend = SDL_CreateRenderer(z->win, -1, z->render_flags);
	SDL_SetRenderDrawColor(z->rend, 0, 0, 0, 255);
	SDL_RenderClear(z->rend);
	if (!z->win)
	{
		ft_putendl("Error Initializing SDL:");
		return (1);
	}
	if (!z->rend)
	{
		ft_putendl("Error_Creating renderer:");
		SDL_DestroyWindow(z->win);
		return (1);
	}
	return (0);
}

t_map			ft_render_map(t_map *z)
{
	z->y = z->drawstart;
	while (z->y < z->drawend)
	{
		if (z->side == 0)
		{
			if (z->res[z->mapx][z->mapy] == 1)
				SDL_SetRenderDrawColor(z->rend, 255, 0, 0, 255);
			else if (z->res[z->mapx][z->mapy] == 2)
				SDL_SetRenderDrawColor(z->rend, 255, 0, 0, 255);
			else if (z->res[z->mapx][z->mapy] == 3)
				SDL_SetRenderDrawColor(z->rend, 255, 0, 0, 255);
			else if (z->res[z->mapx][z->mapy] == 4)
				SDL_SetRenderDrawColor(z->rend, 255, 0, 0, 255);
			else if (z->res[z->mapx][z->mapy] == 5)
				SDL_SetRenderDrawColor(z->rend, 255, 0, 0, 255);
		}
		else
		{
			if (z->res[z->mapx][z->mapy] == 1)
				SDL_SetRenderDrawColor(z->rend, 0, 255, 0, 255);
			else if (z->res[z->mapx][z->mapy] == 2)
				SDL_SetRenderDrawColor(z->rend, 0, 255, 0, 255);
			else if (z->res[z->mapx][z->mapy] == 3)
				SDL_SetRenderDrawColor(z->rend, 0, 255, 0, 255);
			else if (z->res[z->mapx][z->mapy] == 4)
				SDL_SetRenderDrawColor(z->rend, 0, 255, 0, 255);
			else if (z->res[z->mapx][z->mapy] == 5)
				SDL_SetRenderDrawColor(z->rend, 0, 255, 0, 255);
		}
		ft_render_map_side(z);
		SDL_RenderDrawPoint(z->rend, z->x, z->y);
		z->y++;
	}
	return (*z);
}

t_map			ft_render_map_side(t_map *z)
{
	if (z->side == 0 && z->raydirx < 0)
	{
		if (z->res[z->mapx][z->mapy] == 1)
			SDL_SetRenderDrawColor(z->rend, 0, 0, 255, 255);
		else if (z->res[z->mapx][z->mapy] == 2)
			SDL_SetRenderDrawColor(z->rend, 0, 0, 255, 255);
		else if (z->res[z->mapx][z->mapy] == 3)
			SDL_SetRenderDrawColor(z->rend, 0, 0, 255, 255);
		else if (z->res[z->mapx][z->mapy] == 4)
			SDL_SetRenderDrawColor(z->rend, 0, 0, 255, 255);
		else if (z->res[z->mapx][z->mapy] == 5)
			SDL_SetRenderDrawColor(z->rend, 0, 0, 255, 255);
	}
	if (z->side == 1 && z->raydiry < 0)
	{
		if (z->res[z->mapx][z->mapy] == 1)
			SDL_SetRenderDrawColor(z->rend, 255, 255, 0, 255);
		else if (z->res[z->mapx][z->mapy] == 2)
			SDL_SetRenderDrawColor(z->rend, 255, 255, 0, 255);
		else if (z->res[z->mapx][z->mapy] == 3)
			SDL_SetRenderDrawColor(z->rend, 255, 255, 0, 255);
		else if (z->res[z->mapx][z->mapy] == 4)
			SDL_SetRenderDrawColor(z->rend, 255, 255, 0, 255);
		else if (z->res[z->mapx][z->mapy] == 5)
			SDL_SetRenderDrawColor(z->rend, 255, 255, 0, 255);
	}
	return (*z);
}

t_map			ft_initialize(t_map *z)
{
	z->posx = 2;
	z->posy = 2;
	z->dirx = -1;
	z->diry = 0;
	z->planex = 0;
	z->planey = 0.66;
	z->time = 0;
	z->oldtime = 0;
	z->x = 0;
	z->y = 0;
	z->w = 640;
	z->h = 480;
	return (*z);
}

int				main(int ac, char **av)
{
	t_map		z;

	if (ac == 2)
	{
		z.res = two_arr(av[1]);
		ft_error_handel(&z);
		ft_initialize(&z);
		while (z.quit == 0)
		{
			while (z.x++ < z.w)
			{
				ft_calc_ray(&z);
				ft_cal_sidedist(&z);
				ft_calc_dda(&z);
				ft_draw_map(&z);
				ft_render_map(&z);
			}
			keypress(&z);
		}
		free(z.res);
		SDL_DestroyWindow(z.win);
		SDL_Quit();
	}
	else
		ft_putendl("Error!!!!! Invalid or no Arguments.");
}
