/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oearlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 12:10:50 by oearlene          #+#    #+#             */
/*   Updated: 2020/01/24 23:49:05 by oearlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	Checks for any invalid characters
**	Checks for '\n' at end of piece block
**	Returns 1 if any checks are failed
**	Counts and returns number of '#' characters
*/

int		char_counter(char *buf)
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
**	A valid piece with 4 '#' characters will have 6 or 8 contacts
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
		if (char_counter(buf + i) != 4)
			return (1);
		if (contacts_counter(buf + i) != 6 && contacts_counter(buf + i) != 8)
			return (1);
		i += 21;
	}
	return (0);
}
