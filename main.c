/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oearlene <oearlene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 13:57:04 by oearlene          #+#    #+#             */
/*   Updated: 2020/01/19 23:23:13 by oearlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	t_piece	*piecelist;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit target_file\n");
		return (1);
	}
	if ((piecelist = parser(argv[1])) == NULL)
	{
		ft_putstr("error\n");
		return (1);
	}
	return (0);
}
