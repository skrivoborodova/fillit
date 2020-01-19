/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oearlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 01:04:55 by oearlene          #+#    #+#             */
/*   Updated: 2019/09/19 01:12:49 by oearlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	char	*s;

	s = (char *)str + ft_strlen(str);
	while (*s != ch)
	{
		if (s == str)
			return (NULL);
		s--;
	}
	return (s);
}
