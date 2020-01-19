/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oearlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 01:27:11 by oearlene          #+#    #+#             */
/*   Updated: 2019/09/19 01:27:11 by oearlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *sfind, size_t n)
{
	size_t	len;

	if (*sfind == '\0')
		return ((char *)s);
	len = ft_strlen(sfind);
	while (*s != '\0' && n-- >= len)
	{
		if (*s == *sfind && ft_memcmp(s, sfind, len) == 0)
			return ((char *)s);
		s++;
	}
	return (NULL);
}
