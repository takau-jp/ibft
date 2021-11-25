/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook_air <macbook_air@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 09:53:20 by macbook_air       #+#    #+#             */
/*   Updated: 2021/11/26 07:28:02 by macbook_air      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	check_long(long *num, int minus, char c);

int	ft_atoi(const char *str)
{
	long	num;
	int		minus;
	int		i;

	num = 0;
	minus = 1;
	i = 0;
	while (str[i] == ' ' || ('\t' <= str[i] && str[i] <= '\r'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus = -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		if (!check_long(&num, minus, str[i]))
			return (num);
		num *= 10;
		num += str[i] - '0';
		i++;
	}
	return (num * minus);
}

static bool	check_long(long *num, int minus, char c)
{
	if (*num > LONG_MAX / 10)
	{
		if (minus == 1)
			*num = LONG_MAX;
		else
			*num = LONG_MIN;
		return (false);
	}
	if (*num == LONG_MAX / 10)
	{
		if (minus == 1 && c >= '7')
		{
			*num = LONG_MAX;
			return (false);
		}
		else if (minus == -1 && c >= '8')
		{
			*num = LONG_MIN;
			return (false);
		}
	}
	return (true);
}
