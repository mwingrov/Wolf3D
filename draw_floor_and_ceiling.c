/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor_and_ceiling.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwingrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 15:27:44 by mwingrov          #+#    #+#             */
/*   Updated: 2017/12/05 15:30:19 by mwingrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/wolf3d.h"

t_map			ft_ceiling(t_map *z)
{
	z->distwall = z->perpwalldist;
	if (z->drawend < 0)
		z->drawend = z->h;
	z->y = z->drawend + 1;
	while (z->y < z->h)
	{
		z->currentdist = z->h / (2.0 * z->y - z->h);
		if (z->res[z->mapx][z->mapy] == 1)
			SDL_SetRenderDrawColor(z->rend, 237, 190, 149, 255);
		else if (z->res[z->mapx][z->mapy] == 2)
			SDL_SetRenderDrawColor(z->rend, 237, 190, 149, 255);
		else if (z->res[z->mapx][z->mapy] == 3)
			SDL_SetRenderDrawColor(z->rend, 237, 190, 149, 255);
		else if (z->res[z->mapx][z->mapy] == 4)
			SDL_SetRenderDrawColor(z->rend, 237, 190, 149, 255);
		else if (z->res[z->mapx][z->mapy] == 5)
			SDL_SetRenderDrawColor(z->rend, 237, 190, 149, 255);
		SDL_RenderDrawPoint(z->rend, z->x, z->h - z->y);
		z->y++;
	}
	ft_floor(z);
	return (*z);
}

t_map			ft_floor(t_map *z)
{
	z->y = z->drawend + 1;
	while (z->y < z->h)
	{
		z->currentdist = z->h / (2.0 * z->y - z->h);
		if (z->res[z->mapx][z->mapy] == 1)
			SDL_SetRenderDrawColor(z->rend, 55, 55, 55, 255);
		else if (z->res[z->mapx][z->mapy] == 2)
			SDL_SetRenderDrawColor(z->rend, 55, 55, 55, 255);
		else if (z->res[z->mapx][z->mapy] == 3)
			SDL_SetRenderDrawColor(z->rend, 55, 55, 55, 255);
		else if (z->res[z->mapx][z->mapy] == 4)
			SDL_SetRenderDrawColor(z->rend, 55, 55, 55, 255);
		else if (z->res[z->mapx][z->mapy] == 5)
			SDL_SetRenderDrawColor(z->rend, 55, 55, 55, 255);
		SDL_RenderDrawPoint(z->rend, z->x, z->y);
		z->y++;
	}
	return (*z);
}
