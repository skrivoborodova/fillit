/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oearlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 23:49:12 by oearlene          #+#    #+#             */
/*   Updated: 2020/01/25 00:01:27 by oearlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_bound_y(t_piece *piece, t_map *map, int y)
{
	int i;
	int flag;

	i = 0;
	while (i <= 4)
	{
		flag = 1;
		if (map->size > piece->y[i] + y)
			flag = 0;
		i++;
	}
	if (i == 4)
		flag = 0;
	return (flag);
}

int		check_bound_x(t_piece *piece, t_map *map, int x)
{
	int i;
	int flag;

	i = 0;
	while (i <= 4)
	{
		flag = 1;
		if (map->size > piece->x[i] + x)
			flag = 0;
		i++;
	}
	if (i == 4)
		flag = 0;
	return (flag);
}

void	del_piece(t_piece *piece, t_map *map, int x, int y)
{
	int i;
	char letter;

	i = 0;
	letter = '.';
	while (i <= 4)
	{
		x = piece->x[i] + x;
		y = piece->y[i] + y;
		map->array[y][x] = letter;
		i++;
	}
}

void	put_piece(t_piece *piece, t_map *map, int x, int y)
{
	int i;
	char letter;

	i = 0;
	letter = piece->letter;
	while (i <= 4)
	{
		x = piece->x[i] + x;
		y = piece->y[i] + y;
		map->array[y][x] = letter;
		i++;
	}
}
