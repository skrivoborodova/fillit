/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oearlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 13:31:19 by oearlene          #+#    #+#             */
/*   Updated: 2020/01/21 21:48:45 by oearlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"

# include <stdio.h>

# define FILE_SIZE_MAX 544
# define FILE_SIZE_MIN 19

# define USAGE "usage: ./fillit target_file\n"
# define ERR "error\n"


/*
** Struct to stock pieces
** Coordinate map:
**
**		 |x[0]  |x[1]	|x[2]	|x[3]	|
**	y[0] |.		|.		|.		|.		|
**	y[1] |.		|.		|.		|.		|
**	y[2] |.		|.		|.		|.		|
**	y[3] |.		|.		|.		|.		|
**
*/

typedef struct		s_piece
{
	char			letter;
	int				x[4];
	int				y[4];
	struct s_piece	*next;
}					t_piece;

typedef struct		s_map
{
	char			**array;
}					t_map;


/*
 * t_map			*new_map(int size);
 */

t_piece				*read_and_stock(char *file);
t_piece				*stock_piece(char *buf, char piece_letter);
t_piece				*new_list(char *buf, int size);


int					valid(char *buf, int size);
int					charcount(char *buf);
int					contacts_counter(char *buf);

/*
 * void			free_map(t_map *map, int map_size);
 */

#endif
