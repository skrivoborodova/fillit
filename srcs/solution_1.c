/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oearlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 23:49:12 by oearlene          #+#    #+#             */
/*   Updated: 2020/01/25 02:07:04 by oearlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_bound_y(t_piece *piece, t_map *map, int y)
{
	int i;
	int flag;

	i = 0;
	while (i <= 3)
	{
		flag = 1;
		if (map->size >= piece->y[i] + y + 1)
			flag = 0;
		i++;
	}
	return (flag);
}

int		check_bound_x(t_piece *piece, t_map *map, int x)
{
	int i;
	int flag;

	i = 0;
	while (i <= 3)
	{
		flag = 1;
		if (map->size >= piece->x[i] + x + 1)
			flag = 0;
		i++;
	}
	return (flag);
}

void	del_piece(t_piece *piece, t_map *map, int x, int y)
{
	int		i;
	int		x1;
	int		y1;
	char	letter;

	i = 0;
	letter = '.';
	while (i <= 3)
	{
		x1 = piece->x[i] + x;
		y1 = piece->y[i] + y;
		map->array[y1][x1] = letter;
		i++;
	}
}

void	put_piece(t_piece *piece, t_map *map, int x, int y)
{
	int		i;
	int		x1;
	int		y1;
	char	letter;

	i = 0;
	letter = piece->letter;
	while (i <= 3)
	{
		x1 = piece->x[i] + x;
		y1 = piece->y[i] + y;
		map->array[y1][x1] = letter;
		i++;
	}
}
