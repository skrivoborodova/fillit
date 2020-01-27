/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dislocation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oearlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 22:51:02 by oearlene          #+#    #+#             */
/*   Updated: 2020/01/27 21:36:48 by vrhaena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		dislocate_x(t_piece *piece, int n)
{
	int		i;

	i = 0;
	while (i <= 3)
	{
		piece->x[i] -= n;
		i++;
	}
}

void		dislocate_y(t_piece *piece, int n)
{
	int		i;

	i = 0;
	while (i <= 3)
	{
		piece->y[i] -= n;
		i++;
	}
}

t_piece		*in_order(t_piece *piece)
{
	int		i;
	int		x_min;
	int 	y_min;

	i = 0;
	x_min = 3;
	y_min = 3;
	while (i <= 3)
	{
		if (piece->x[i] < x_min)
			x_min = piece->x[i];
		if (piece->y[i] < y_min)
			y_min = piece->y[i];
		i++;
	}
	if (piece->x[0] != 0)
		dislocate_x(piece, x_min);
	if (piece->y[0] != 0)
		dislocate_y(piece, y_min);
	return (piece);
}
