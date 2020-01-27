/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oearlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 23:15:43 by oearlene          #+#    #+#             */
/*   Updated: 2020/01/28 00:40:49 by oearlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Allocates a new map structure
*/

t_map	*new_map(int map_size)
{
	t_map	*map;
	int		i;
	int		j;

	map = (t_map *)ft_memalloc(sizeof(t_map));
	map->size = map_size;
	map->array = (char **)ft_memalloc(sizeof(char *) * map_size);
	i = 0;
	while (i < map_size)
	{
		map->array[i] = ft_strnew(map_size);
		j = 0;
		while (j < map_size)
		{
			map->array[i][j] = '.';
			j++;
		}
		i++;
	}
	return (map);
}

void	free_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->size)
	{
		ft_memdel((void **)&(map->array[i]));
		i++;
	}
	ft_memdel((void **)&(map->array));
	ft_memdel((void **)&map);
}

void	print_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->size)
	{
		ft_putstr(map->array[i]);
		ft_putchar('\n');
		i++;
	}
}
