/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwingrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 15:28:02 by mwingrov          #+#    #+#             */
/*   Updated: 2017/12/01 20:00:30 by mwingrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/wolf3d.h"

t_map	ft_calc_ray(t_map *z)
{
	z->camerax = 2 * z->x / (double)z->w - 1;
	z->rayposx = z->posx;
	z->rayposy = z->posy;
	z->raydirx = z->dirx + z->planex * z->camerax;
	z->raydiry = z->diry + z->planey * z->camerax;
	z->mapx = (int)z->rayposx;
	z->mapy = (int)z->rayposy;
	z->deltadistx = sqrt(1 + (z->raydiry * z->raydiry) /
			(z->raydirx * z->raydirx));
	z->deltadisty = sqrt(1 + (z->raydirx * z->raydirx) /
			(z->raydiry * z->raydiry));
	z->hit = 0;
	return (*z);
}

t_map	ft_cal_sidedist(t_map *z)
{
	if (z->raydirx < 0)
	{
		z->stepx = -1;
		z->sidedistx = (z->rayposx - z->mapx) * z->deltadistx;
	}
	else
	{
		z->stepx = 1;
		z->sidedistx = (z->mapx + 1.0 - z->rayposx) * z->deltadistx;
	}
	if (z->raydiry < 0)
	{
		z->stepy = -1;
		z->sidedisty = (z->rayposy - z->mapy) * z->deltadisty;
	}
	else
	{
		z->stepy = 1;
		z->sidedisty = (z->mapy + 1.0 - z->rayposy) * z->deltadisty;
	}
	return (*z);
}

t_map	ft_calc_dda(t_map *z)
{
	while (z->hit == 0)
	{
		if (z->sidedistx < z->sidedisty)
		{
			z->sidedistx += z->deltadistx;
			z->mapx += z->stepx;
			z->side = 0;
		}
		else
		{
			z->sidedisty += z->deltadisty;
			z->mapy += z->stepy;
			z->side = 1;
		}
		if (z->res[z->mapx][z->mapy] > 0)
			z->hit = 1;
	}
	return (*z);
}

t_map	ft_draw_map(t_map *z)
{
	if (z->side == 0)
		z->perpwalldist = (z->mapx - z->rayposx +
				(1 - z->stepx) / 2) / z->raydirx;
	else
		z->perpwalldist = (z->mapy - z->rayposy +
				(1 - z->stepy) / 2) / z->raydiry;
	z->lineheight = (int)(z->h / z->perpwalldist);
	z->drawstart = -z->lineheight / 2 + z->h / 2;
	if (z->drawstart < 0)
		z->drawstart = 0;
	z->drawend = z->lineheight / 2 + z->h / 2;
	if (z->drawend >= z->h)
		z->drawend = z->h - 1;
	return (*z);
}
