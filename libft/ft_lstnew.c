/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oearlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 05:48:34 by oearlene          #+#    #+#             */
/*   Updated: 2019/10/04 04:19:02 by oearlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*nelem;

	if (!(nelem = (t_list *)malloc(sizeof(*nelem))))
		return (NULL);
	if (content == NULL)
	{
		nelem->content = NULL;
		nelem->content_size = 0;
	}
	else
	{
		if ((nelem->content = malloc(content_size)) == NULL)
		{
			free(nelem);
			return (NULL);
		}
		ft_memcpy(nelem->content, content, content_size);
		nelem->content_size = content_size;
	}
	nelem->next = NULL;
	return (nelem);
}
