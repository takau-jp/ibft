/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook_air <macbook_air@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 09:53:20 by macbook_air       #+#    #+#             */
/*   Updated: 2021/11/28 19:48:06 by macbook_air      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool				check_long(long *num, int sign, char c);
static unsigned long	ft_absl(long i);

int	ft_atoi(const char *str)
{
	long	num;
	int		sign;
	int		i;

	num = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || ('\t' <= str[i] && str[i] <= '\r'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		if (!check_long(&num, sign, str[i]))
			return (num);
		num *= 10;
		num += str[i] - '0';
		i++;
	}
	return (num * sign);
}

static bool	check_long(long *num, int sign, char c)
{
	long	limit;

	limit = (long []){LONG_MIN, LONG_MAX}[sign == 1];
	if (*num > LONG_MAX / 10 || \
		(*num == LONG_MAX / 10 && c - '0' >= (int)(ft_absl(limit) % 10)))
	{
		*num = limit;
		return (false);
	}
	return (true);
}

static unsigned long	ft_absl(long i)
{
	unsigned long	u;

	u = i;
	if (u > LONG_MAX)
		u = ~i + 1;
	return (u);
}
