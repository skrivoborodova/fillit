/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oearlene <oearlene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 12:10:50 by oearlene          #+#    #+#             */
/*   Updated: 2020/01/20 00:08:35 by oearlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	Checks for any invalid characters
**	Checks for '\n' at end of piece block
**	Returns 1 if any checks are failed
**	Counts and returns number of '#' characters
*/

int		charcount(char *buf)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (i < 19)
	{
		if (buf[i] && buf[i] != '\n' && buf[i] != '#' && buf[i] != '.')
			return (1);
		if (buf[i] == '\n' && (((i + 1) % 5) != 0))
			return (1);
		if (buf[i] == '#')
			count++;
		i++;
	}
	if (!buf[i] || buf[i] != '\n')
		return (1);
	return (count);
}

/*
**	Checks each '#' character to see if it's neighboring to another
**	Returns a count of these neighbor's contacts to validate piece shape
**	A valid piece with 4 '#' characters will either have 6 or 8 contacts
*/

int		contacts_counter(char *buf)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < 19)
	{
		if (buf[i] == '#')
		{
			if (i + 1 <= 18 && buf[i + 1] == '#')
				count++;
			if (i - 1 >= 0 && buf[i - 1] == '#')
				count++;
			if (i + 5 <= 18 && buf[i + 5] == '#')
				count++;
			if (i - 5 >= 0 && buf[i - 5] == '#')
				count++;
		}
		i++;
	}
	return (count);
}

/*
**	Iterates through buf 21 char (one piece + '\n') at a time
**	Calls checking functions to confirm validity
**	Returns 1 if any checks are failed
*/

int		valid(char *buf, int size)
{
	int i;

	i = 0;
	while (i <= size)
	{
		if (charcount(buf + i) != 4)
			return (1);
		if (contacts_counter(buf + i) != 6 && contacts_counter(buf + i) != 8)
			return (1);
		i += 21;
	}
	return (0);
}

t_piece			*makelist(char *buf, int size)
{
	/*
	 * need to be done
	 */
}

/*
** Opens & reads file into a buffer of size 545 (max file size + 1)
** Calls valid() to check validity of file
** Returns list of piece structs
*/

t_piece		*parser(char *filename)
{
	char	buf[545];
	int		fd;
	int		byte_read;

	fd = open(filename, O_RDONLY);
	byte_read = read(fd, buf, 545);
	close(fd);
	if (byte_read > 544 || byte_read < 19)
		return (NULL);
	buf[byte_read] = '\0';
	if (valid(buf, byte_read) == 1)
		return (NULL);
	return (makelist(buf, byte_read));
}
