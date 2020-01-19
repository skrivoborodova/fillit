/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oearlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 17:57:26 by oearlene          #+#    #+#             */
/*   Updated: 2019/09/23 01:12:01 by oearlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*subst;
	size_t	i;
	size_t	j;

	if (s == NULL)
		return (NULL);
	j = ft_strlen((char *)s);
	if (!(subst = ft_strnew(len)))
		return (NULL);
	if (start > j)
		return (NULL);
	i = 0;
	while (s[start] && i < len)
	{
		subst[i] = s[start];
		start++;
		i++;
	}
	return (subst);
}
