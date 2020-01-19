/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oearlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 01:21:01 by oearlene          #+#    #+#             */
/*   Updated: 2019/10/05 00:55:10 by oearlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int				flag;
	long long int	res;
	long long int	prev;

	flag = 1;
	res = 0;
	while (*str == '\n' || *str == '\t' || *str == '\v'
			|| *str == ' ' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			flag = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		prev = res;
		res = res * 10 + *str - '0';
		if (prev > res)
			return (flag > 0 ? -1 : 0);
		str++;
	}
	return (res * flag);
}
