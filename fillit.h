/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oearlene <oearlene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 13:31:19 by oearlene          #+#    #+#             */
/*   Updated: 2020/01/20 00:08:35 by oearlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"

# include <stdio.h>

typedef struct	s_piece
{
	/*
	 * need to be done =(
	 */
	struct s_piece	*next;
}				t_piece;

typedef struct	s_map
{
	char		**array;
}				t_map;


/*
 * t_map			*new_map(int size);
 */

t_piece			*parser(char *filename);

t_piece			*makelist(char *buf, int size);


int				valid(char *buf, int size);
int				charcount(char *buf);
int				contacts_counter(char *buf);

/*
 * void			free_map(t_map *map, int map_size);
 */

#endif
