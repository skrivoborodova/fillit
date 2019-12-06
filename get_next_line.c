/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrhaena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 06:50:44 by vrhaena           #+#    #+#             */
/*   Updated: 2019/11/27 09:01:03 by vrhaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_output(int ret, char **line, char *rest)
{
	if (ret > 0 || ft_strlen(rest) || ft_strlen(*line))
		return (1);
	else if (ret < 0)
	{
		ft_strdel(line);
		return (-1);
	}
	else
	{
		ft_strdel(line);
		return (0);
	}
}

char	*check_rest(char *rest, char **p)
{
	char	*str;

	str = NULL;
	if ((*p = ft_strchr(rest, '\n')))
	{
		**p = '\0';
		str = ft_strdup(rest);
		(*p)++;
		ft_strcpy(rest, *p);
	}
	else if (*(rest) != '\0')
	{
		str = ft_strdup(rest);
		ft_strclr(rest);
	}
	else
		str = ft_strnew(0);
	return (str);
}

int		get_line(const int fd, char **line, char *rest)
{
	int			ret;
	char		buff[BUFF_SIZE + 1];
	char		*p;
	char		*tmp;

	p = NULL;
	tmp = NULL;
	ret = 1;
	*line = check_rest(rest, &p);
	while ((!p && ((ret = read(fd, buff, BUFF_SIZE)) > 0)))
	{
		buff[ret] = '\0';
		if ((p = ft_strchr(buff, '\n')))
		{
			ft_strcpy(rest, ++p);
			ft_strclr(--p);
		}
		tmp = *line;
		if (!(*line = ft_strjoin(*line, buff)) || ret < 0)
			return (get_output(ret, line, rest));
		ft_strdel(&tmp);
	}
	return (get_output(ret, line, rest));
}

t_lst	*get_new_lst(int fd)
{
	t_lst	*new;

	new = (t_lst *)malloc(sizeof(t_lst));
	if (new == NULL)
		return (NULL);
	new->fd = fd;
	new->rest = ft_strnew(BUFF_SIZE);
	new->next = NULL;
	return (new);
}

int		get_next_line(const int fd, char **line)
{
	static t_lst	*head;
	t_lst			*tmp;

	if (!line || fd < 0)
		return (-1);
	if (head == NULL)
		head = get_new_lst(fd);
	tmp = head;
	while (tmp != NULL)
	{
		if (tmp->fd == fd)
			break ;
		tmp = tmp->next;
	}
	if (tmp == NULL)
	{
		tmp = get_new_lst(fd);
		tmp->next = head;
		head = tmp;
	}
	return (get_line(tmp->fd, line, tmp->rest));
}
