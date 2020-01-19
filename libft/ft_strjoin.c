/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oearlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 18:02:54 by oearlene          #+#    #+#             */
/*   Updated: 2019/09/22 19:34:39 by oearlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	size;
	size_t	lens1;
	size_t	lens2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	lens1 = (ft_strlen((char*)s1));
	lens2 = (ft_strlen((char*)s2));
	size = lens1 + lens2;
	if (!(res = ft_strnew(size)))
		return (NULL);
	if (s1)
		res = ft_strcpy(res, (char*)s1);
	else
		res = ft_strcpy(res, (char*)s2);
	if (s1 && s2)
		res = ft_strcat(res, (char*)s2);
	return (res);
}
