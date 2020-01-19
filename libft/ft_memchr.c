/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oearlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 23:20:49 by oearlene          #+#    #+#             */
/*   Updated: 2019/09/18 01:10:05 by oearlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	unsigned char	*s;
	unsigned char	c1;
	int				i;

	s = (unsigned char *)arr;
	c1 = (unsigned char)c;
	i = 0;
	while (n--)
	{
		if (s[i] == c1)
			return (s + i);
		i++;
	}
	return (NULL);
}
