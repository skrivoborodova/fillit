/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_stock.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oearlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 20:27:34 by oearlene          #+#    #+#             */
/*   Updated: 2020/01/25 02:53:09 by oearlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t			count_pieces(t_piece *list)
{
	size_t		count;

	count = 0;
	while (list)
	{
		list = list->next;
		count++;
	}
	return (count);
}

/*
** Malloc a new piece struct
** Find & store coordinates of '#' characters
**
**	####\n....\n....\n....\n\n
**	x = i % 5
**	y = 1 / 5
*/

t_piece			*stock_piece(char *buf, char piece_letter)
{
	t_piece		*ptr;
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (!(ptr = (t_piece*)malloc(sizeof(t_piece))))
		return (NULL);
	while (i < 20)
	{
		if (buf[i] == '#')
		{
			ptr->x[j] = i % 5;
			ptr->y[j] = i / 5;
			j++;
		}
		i++;
	}
	ptr->letter = piece_letter;
	return (ptr);
}

/*
** Passes the buffer to stock_piece func one piece (21 chars)
** Assigns letter to the made piece
** Returns a linked list of piece structs
*/

t_piece			*new_list(char *buf, int size)
{
	t_piece		*head;
	t_piece		*tmp;
	int			i;
	char		piece_letter;

	i = 0;
	piece_letter = 'A';
	while (i < size)
	{
		if (piece_letter == 'A')
		{
			head = stock_piece(buf + i, piece_letter);
			tmp = head;
		}
		else
		{
			tmp->next = stock_piece(buf + i, piece_letter);
			tmp = tmp->next;
		}
		piece_letter++;
		i += 21;
	}
	tmp->next = NULL;
	return (head);
}

/*
** Opens & reads file into a buffer of max file size + 1 ('\0')
** Calls valid func to check validity of file
** Returns list of piece structs
*/

t_piece			*read_and_stock(char *file)
{
	char		buf[FILE_SIZE_MAX + 1];
	int			fd;
	int			byte_read;

	fd = open(file, O_RDONLY);
	byte_read = read(fd, buf, (FILE_SIZE_MAX + 1));
	close(fd);
	if (byte_read > FILE_SIZE_MAX || byte_read < FILE_SIZE_MIN)
		return (NULL);
	buf[byte_read] = '\0';
	if (valid(buf, byte_read) == 1)
		return (NULL);
	return (new_list(buf, byte_read));
}

void			free_list(t_piece *list)
{
	t_piece		*tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
}
