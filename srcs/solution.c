/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oearlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 23:05:13 by oearlene          #+#    #+#             */
/*   Updated: 2020/01/25 01:42:15 by oearlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		high_sqrt(int nbr)
{
	int size;

	size = 2;
	while (size * size < nbr)
		size++;
	return (size);
}

int		backtracking(t_map *map, t_piece *piece)
{
	int			x;
	int			y;
	t_piece		*ptr;

	if (piece == NULL)
		return (1);
	ptr = piece;
	y = 0;
	while (!check_bound_y(ptr, map, y))
	{
		x = 0;
		while (!check_bound_x(ptr, map, x))
		{
			if (!outside_map(map, ptr, x, y))
			{
				put_piece(ptr, map, x, y);
				if (backtracking(map, piece->next))
					return (1);
				else
					del_piece(ptr, map, x, y);
			}
			x++;
		}
		y++;
	}
	return (0);
}

/*
** Start with the smallest map
*/

t_map	*solve(t_piece *list)
{
	t_map	*map;
	int		map_size;

	map_size = high_sqrt(count_pieces(list) * 4);
	map = new_map(map_size);
	while (!backtracking(map, list))
	{
		free_map(map);
		map_size++;
		map = new_map(map_size);
	}
	return (map);
}
