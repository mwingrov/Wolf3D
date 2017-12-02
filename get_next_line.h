/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwingrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 04:41:57 by mwingrov          #+#    #+#             */
/*   Updated: 2017/12/02 04:42:23 by mwingrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/libft.h"

# define BUFF_SIZE 15

typedef struct	s_static
{
	char	buff[BUFF_SIZE + 1];
	char	*save;
	char	*sub;
	int		x;
	int		ret;
}				t_static;

int				get_next_line(const int fd, char **line);

#endif
