/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook_air <macbook_air@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 09:53:20 by macbook_air       #+#    #+#             */
/*   Updated: 2021/11/23 19:36:12 by macbook_air      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_space(char c)
{
	if (c == ' ' || ('\t' <= c && c <= '\r'))
		return (1);
	return (0);
}

int	check_long(long *num, int minus, char c)
{
	if (*num > 922337203685477580)
	{
		if (minus == 1)
			*num = -1;
		else
			*num = 0;
		return (0);
	}
	if (*num == 922337203685477580)
	{
		if (minus == 1 && c >= '7')
		{
			*num = -1;
			return (0);
		}
		else if (minus == -1 && c >= '8')
		{
			*num = 0;
			return (0);
		}
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	long	num;
	int		minus;
	int		i;

	num = 0;
	minus = 1;
	i = 0;
	while (is_space(str[i]))
		i ++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus *= -1;
		i ++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		if (!check_long(&num, minus, str[i]))
			return (num);
		num *= 10;
		num += str[i] - '0';
		i ++;
	}
	return (num * minus);
}
