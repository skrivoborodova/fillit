/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oearlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 23:05:13 by oearlene          #+#    #+#             */
/*   Updated: 2020/01/22 00:10:52 by oearlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t	count_pieces(t_piece *list)
{
	size_t	count;

	count = 0;
	while (list)
	{
		list = list->next;
		count++;
	}
	return (count);
}


int		high_sqrt(int nbr)
{
	int size;

	size = 2;
	while (size * size < nbr)
		size++;
	return (size);
}

/*
** Backtracking implementation of the solver.
*/

int		solve_map(t_map *map, t_piece *piece)
{
	int			x;
	int			y;
	t_piece		*ptr;

	if (piece == NULL)
		return (1);
	ptr = piece;
	y = 0;
	while (y < (map->size - ptr->y + 1))
	{
		x = 0;
		while (x < (map->size - ptr->x + 1))
		{
			if () //функция которая проверяет за пределами ли карты мы
			{
				//функция которая размещает фигуру на карте
				if (solve_map(map, piece->next))
					return (1);
				else
					//функция которая удаляет фигуру с карты
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
	while (!solve_map(map, list))
	{
		free_map(map);
		map_size++;
		map = new_map(map_size);
	}
	return (map);
}
