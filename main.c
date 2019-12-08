/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oearlene <oearlene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 13:57:04 by oearlene          #+#    #+#             */
/*   Updated: 2019/12/08 14:30:18 by oearlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **ag)
{
	int fd;
	int i;

	fd = 0;
	i = 0;
	if (ac == 2)
	{
		fd = open(ag[1], O_RDONLY);
		i = is_valid(fd);
		printf("%d\n", i);
	}
	else
		printf("usage: .\\fillit target_file");
	return (0);
}
