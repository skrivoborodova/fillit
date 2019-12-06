/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrhaena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 21:24:51 by vrhaena           #+#    #+#             */
/*   Updated: 2019/11/27 09:47:00 by vrhaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 1

# include "libft/libft.h"
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>

# include <stdio.h>

typedef struct		s_lst
{
	int				fd;
	char			*rest;
	struct s_lst	*next;
}					t_lst;

int					get_next_line(const int fd, char **line);

#endif
