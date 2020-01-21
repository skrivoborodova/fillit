/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oearlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 13:57:04 by oearlene          #+#    #+#             */
/*   Updated: 2020/01/21 21:44:46 by oearlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	t_piece	*piece;

	if (argc != 2)
	{
		ft_putstr(USAGE);
		return (1);
	}
	if ((piece = read_and_stock(argv[1])) == NULL)
	{
		ft_putstr(ERR);
		return (1);
	}
	return (0);
}
