/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oearlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 18:05:02 by oearlene          #+#    #+#             */
/*   Updated: 2019/09/23 02:45:15 by oearlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t begin;
	size_t end;
	size_t res;

	if (s == NULL)
		return (NULL);
	end = ft_strlen((char *)s);
	begin = 0;
	while (s[begin] &&
			(s[begin] == ' ' || s[begin] == '\n' || s[begin] == '\t'))
		begin++;
	while (begin < end &&
			(s[end - 1] == ' ' || s[end - 1] == '\n' || s[end - 1] == '\t'))
		end--;
	if (begin == end)
		return (ft_strnew(0));
	res = end - begin;
	return (ft_strsub(s, begin, res));
}
