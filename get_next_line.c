/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwingrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 04:41:35 by mwingrov          #+#    #+#             */
/*   Updated: 2017/12/02 04:41:48 by mwingrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*transfer_text(char *s1, char *s2, int flag)
{
	int			len;

	len = ft_strlen(s2) + ft_strlen(s1);
	s1 = (char*)ft_realloc(s1, len + 1);
	if (flag == 2)
		s1 = ft_strcpy(s1, s2);
	else
		s1 = ft_strcat(s1, s2);
	if (flag == 1)
		free(s2);
	return (s1);
}

int		get_line(char **save, char ***line)
{
	int		x;
	char	*sub;

	if (ft_strchr(*save, '\n'))
	{
		x = 0;
		while (save[0][x] != '\n')
			x++;
		**line = ft_strnew(1);
		**line = transfer_text(**line, ft_strsub(*save, 0, x), 1);
		sub = ft_strchr(*save, '\n');
		*save = ft_strcpy(*save, sub + 1);
		return (1);
	}
	else
	{
		**line = ft_strjoin(**line, *save);
	}
	return (0);
}

int		return_states(char *line, char **save, int ret)
{
	if (ft_strlen(line) > 0 && ret != -1)
	{
		*save = "";
		return (1);
	}
	if (ret == -1)
		return (-1);
	return (0);
}

int		read_text(int fd, char **line)
{
	static	char	*save = "";
	t_static		stat;
	static int		x = 0;

	if (get_line(&save, &line) == 1)
		return (1);
	while ((stat.ret = read(fd, stat.buff, BUFF_SIZE)) > 0)
	{
		stat.buff[stat.ret] = '\0';
		if (ft_strchr(stat.buff, '\n'))
		{
			stat.x = 0;
			while (stat.buff[stat.x] != '\n')
				stat.x++;
			*line = transfer_text(*line, ft_strsub(stat.buff, 0, stat.x), 1);
			stat.sub = ft_strchr(stat.buff, '\n');
			save = (x == 0) ? ft_strnew(1) : save;
			x++;
			save = transfer_text(save, stat.sub + 1, 2);
			return (1);
		}
		else
			*line = transfer_text(*line, stat.buff, 0);
	}
	return (return_states(*line, &save, stat.ret));
}

int		get_next_line(const int fd, char **line)
{
	int		x;
	char	*str;

	str = "";
	if (str)
		ft_bzero(str, ft_strlen(str));
	if (fd < 0)
		return (-1);
	x = read_text(fd, &str);
	*line = str;
	if (x == 0)
		free(*line);
	return (x);
}
