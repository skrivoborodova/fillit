/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dislocation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oearlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 22:51:02 by oearlene          #+#    #+#             */
/*   Updated: 2020/01/25 23:35:56 by oearlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		dislocate_x(t_piece *piece, int n)
{
	int		i;

	i = 0;
	while (i <= 3)
	{
		piece->x[i] += n;
		i++;
	}
}

void		dislocate_y(t_piece *piece, int n)
{
	int		i;

	i = 0;
	while (i <= 3)
	{
		piece->y[i] += n;
		i++;
	}
}

t_piece		*in_order(t_piece *piece)
{
	int		i;

	i = 0;
	while (i <= 3)
	{
		if (piece->x[0] != 0)
			dislocate_x(piece, -1);
		if (piece->y[0] != 0)
			dislocate_y(piece, -1);
		i++;
	}
	return (piece);
}
