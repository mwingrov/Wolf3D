/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwingrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 20:03:09 by mwingrov          #+#    #+#             */
/*   Updated: 2017/12/05 15:37:43 by mwingrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "../libft/libft.h"
# include <SDL2/SDL.h>
# include "../get_next_line.h"
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <openGL/gl.h>

typedef struct			s_coo
{
	double				x;
	double				y;
	int					i;
}						t_coo;

typedef struct			s_sizexy
{
	int					x;
	int					y;
	int					fd;
	int					i;
	int					j;
	int					index;
}						t_sizexy;

typedef struct			s_map
{
	int					x;
	int					y;
	int					w;
	int					h;
	int					stepx;
	int					stepy;
	int					mapx;
	int					mapy;
	int					hit;
	int					side;
	int					lineheight;
	int					drawstart;
	int					drawend;
	int					quit;
	double				distwall;
	double				distplayer;
	double				currentdist;
	double				frametime;
	double				movespeed;
	double				rotspeed;
	double				sidedistx;
	double				sidedisty;
	double				deltadistx;
	double				deltadisty;
	double				perpwalldist;
	double				posx;
	double				posy;
	double				dirx;
	double				diry;
	double				planex;
	double				planey;
	double				oldplanex;
	double				olddirx;
	double				time;
	double				oldtime;
	double				camerax;
	double				rayposx;
	double				rayposy;
	double				raydirx;
	double				raydiry;
	double				**res;
	SDL_Window			*win;
	SDL_Renderer		*rend;
	SDL_Event			event;
	Uint32				render_flags;
	t_sizexy			size;
}						t_map;

double					**two_arr(char *filename);
t_sizexy				get_xy(char *filename);
double					**alloc_sp(t_sizexy z);
t_map					keypress(t_map *z);
t_map					ft_render_map(t_map *z);
int						ft_error_handel(t_map *z);
t_map					ft_initialize(t_map *z);
t_map					ft_render_map_side(t_map *z);
t_map					ft_calc_ray(t_map *z);
t_map					ft_cal_sidedist(t_map *z);
t_map					ft_draw_map(t_map *z);
t_map					ft_calc_dda(t_map *z);
t_map					sidedraw_x(t_map *z);
t_map					sidedraw_y(t_map *z);
t_map					ft_ceiling(t_map *z);
t_map					ft_floor(t_map *z);
#endif
