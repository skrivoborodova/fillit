/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oearlene <oearlene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 05:08:20 by oearlene          #+#    #+#             */
/*   Updated: 2019/11/07 22:51:56 by oearlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 32

# include <unistd.h>
# include <fcntl.h>
# include "libft.h"

# include <stdio.h>

/*
** t_gnl		Struct for file descriptors
** fd			File descriptor
** buff			Buffer to keep already reading content from the first '\n'
** next			Next element in chained list
*/

typedef struct		s_gnl
{
	int				fd;
	char			*buff;
	struct s_gnl	*next;
}					t_gnl;

t_gnl				*ft_add_fd(int fd);
char				*ft_check(char *buff, char **p_to_n);
int					ft_get_line(const int fd, char **line, char *buff);
int					get_next_line(const int fd, char **line);

#endif
