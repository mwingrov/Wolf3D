/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_walls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwingrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 15:30:45 by mwingrov          #+#    #+#             */
/*   Updated: 2017/12/05 15:39:57 by mwingrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/wolf3d.h"

t_map			ft_render_map(t_map *z)
{
	ft_ceiling(z);
	z->y = z->drawstart;
	while (z->y < z->drawend)
	{
		if (z->side == 0)
		{
			if (z->res[z->mapx][z->mapy] == 1)
				SDL_SetRenderDrawColor(z->rend, 183, 179, 176, 255);
			else if (z->res[z->mapx][z->mapy] == 2)
				SDL_SetRenderDrawColor(z->rend, 183, 179, 176, 255);
			else if (z->res[z->mapx][z->mapy] == 3)
				SDL_SetRenderDrawColor(z->rend, 183, 179, 176, 255);
			else if (z->res[z->mapx][z->mapy] == 4)
				SDL_SetRenderDrawColor(z->rend, 183, 179, 176, 255);
			else if (z->res[z->mapx][z->mapy] == 5)
				SDL_SetRenderDrawColor(z->rend, 183, 179, 176, 255);
		}
		sidedraw_x(z);
		ft_render_map_side(z);
		sidedraw_y(z);
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
			SDL_SetRenderDrawColor(z->rend, 10, 78, 204, 255);
		else if (z->res[z->mapx][z->mapy] == 2)
			SDL_SetRenderDrawColor(z->rend, 10, 78, 204, 255);
		else if (z->res[z->mapx][z->mapy] == 3)
			SDL_SetRenderDrawColor(z->rend, 10, 78, 204, 255);
		else if (z->res[z->mapx][z->mapy] == 4)
			SDL_SetRenderDrawColor(z->rend, 10, 78, 204, 255);
		else if (z->res[z->mapx][z->mapy] == 5)
			SDL_SetRenderDrawColor(z->rend, 10, 78, 204, 255);
	}
	return (*z);
}

t_map			sidedraw_x(t_map *z)
{
	if (z->side != 0)
	{
		if (z->res[z->mapx][z->mapy] == 1)
			SDL_SetRenderDrawColor(z->rend, 168, 28, 63, 255);
		else if (z->res[z->mapx][z->mapy] == 2)
			SDL_SetRenderDrawColor(z->rend, 168, 28, 63, 255);
		else if (z->res[z->mapx][z->mapy] == 3)
			SDL_SetRenderDrawColor(z->rend, 168, 28, 63, 255);
		else if (z->res[z->mapx][z->mapy] == 4)
			SDL_SetRenderDrawColor(z->rend, 168, 28, 63, 255);
		else if (z->res[z->mapx][z->mapy] == 5)
			SDL_SetRenderDrawColor(z->rend, 168, 28, 63, 255);
	}
	return (*z);
}

t_map			sidedraw_y(t_map *z)
{
	if (z->side == 1 && z->raydiry < 0)
	{
		if (z->res[z->mapx][z->mapy] == 1)
			SDL_SetRenderDrawColor(z->rend, 242, 144, 2, 255);
		else if (z->res[z->mapx][z->mapy] == 2)
			SDL_SetRenderDrawColor(z->rend, 242, 144, 2, 255);
		else if (z->res[z->mapx][z->mapy] == 3)
			SDL_SetRenderDrawColor(z->rend, 242, 144, 2, 255);
		else if (z->res[z->mapx][z->mapy] == 4)
			SDL_SetRenderDrawColor(z->rend, 242, 114, 2, 255);
		else if (z->res[z->mapx][z->mapy] == 5)
			SDL_SetRenderDrawColor(z->rend, 242, 114, 2, 255);
	}
	return (*z);
}
