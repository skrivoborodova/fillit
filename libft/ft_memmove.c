/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oearlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 00:22:52 by oearlene          #+#    #+#             */
/*   Updated: 2019/09/23 00:57:06 by oearlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	i = 0;
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (s == d || n <= 0)
		return (dst);
	if (s < d)
	{
		while (++i <= n)
			d[n - i] = s[n - i];
	}
	else
	{
		while (n-- > 0)
			*d++ = *s++;
	}
	return (dst);
}
