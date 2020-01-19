/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oearlene <oearlene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 23:43:38 by oearlene          #+#    #+#             */
/*   Updated: 2019/11/08 00:02:51 by oearlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_gnl	*ft_add_fd(int fd)
{
	t_gnl	*new;

	if (!(new = (t_gnl *)malloc(sizeof(t_gnl))))
		return (NULL);
	new->fd = fd;
	new->buff = ft_strnew(BUFF_SIZE);
	new->next = NULL;
	return (new);
}

char	*ft_check(char *buff, char **p_to_n)
{
	char *str;

	if ((*p_to_n = ft_strchr(buff, '\n')) != NULL)
	{
		str = ft_strsub(buff, 0, *p_to_n - buff);
		ft_strcpy(buff, ++(*p_to_n));
	}
	else
	{
		str = ft_strnew(ft_strlen(buff) + 1);
		ft_strcat(str, buff);
		ft_strclr(buff);
	}
	return (str);
}

int		ft_get_line(const int fd, char **line, char *buff)
{
	char	buff_read[BUFF_SIZE + 1];
	char	*p_to_n;
	char	*tmp;
	int		byte_read;

	p_to_n = NULL;
	byte_read = 1;
	*line = ft_check(buff, &p_to_n);
	while (!p_to_n && ((byte_read = read(fd, buff_read, BUFF_SIZE))))
	{
		buff_read[byte_read] = '\0';
		if ((p_to_n = ft_strchr(buff_read, '\n')) != NULL)
		{
			ft_strcpy(buff, ++p_to_n);
			ft_strclr(--p_to_n);
		}
		tmp = *line;
		if (!(*line = ft_strjoin(tmp, buff_read)) || byte_read < 0)
			return (-1);
		ft_strdel(&tmp);
	}
	return ((ft_strlen(*line) || ft_strlen(buff) || byte_read) ? 1 : 0);
}

int		get_next_line(const int fd, char **line)
{
	static t_gnl	*head;
	t_gnl			*tmp;

	if (fd < 0 || line == 0)
		return (-1);
	if (!head)
		head = ft_add_fd(fd);
	tmp = head;
	while (tmp->fd != fd)
	{
		if (tmp->next == NULL)
			tmp->next = ft_add_fd(fd);
		tmp = tmp->next;
	}
	return ((ft_get_line(fd, line, tmp->buff)));
}
