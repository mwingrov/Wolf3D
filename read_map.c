/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwingrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 05:26:49 by mwingrov          #+#    #+#             */
/*   Updated: 2017/12/05 15:43:47 by mwingrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/wolf3d.h"

double			**alloc_sp(t_sizexy z)
{
	double		**a;
	int			i;

	i = 0;
	a = (double **)malloc(sizeof(double *) * z.y);
	while (i < z.y)
	{
		a[i] = (double *)malloc(sizeof(double) * z.x);
		i++;
	}
	return (a);
}

t_sizexy		get_xy(char *filename)
{
	char		*line;
	t_sizexy	z;
	char		**cnt;

	z.i = 0;
	z.x = 0;
	z.y = 0;
	{
		z.fd = open(filename, O_RDONLY);
		while (get_next_line(z.fd, &line) > 0)
		{
			while (line[z.i] != '\0')
			{
				cnt = ft_strsplit(line, ' ');
				z.x = 0;
				z.index = 0;
				while (cnt[z.index++])
					z.x++;
				z.i++;
			}
			z.y++;
		}
	}
	close(z.fd);
	return (z);
}

double			**two_arr(char *filename)
{
	double		**arr;
	t_sizexy	z;
	char		*line;
	char		**newl;

	z = get_xy(filename);
	z.j = 0;
	arr = alloc_sp(z);
	z.fd = open(filename, O_RDONLY);
	while (z.j < z.y)
	{
		z.i = 0;
		get_next_line(z.fd, &line);
		newl = ft_strsplit(line, ' ');
		while (z.i < z.x)
		{
			arr[(int)z.j][(int)z.i] = ft_atoi(newl[(int)z.i]);
			z.i++;
		}
		z.j++;
		free(line);
	}
	close(z.fd);
	return (arr);
}
