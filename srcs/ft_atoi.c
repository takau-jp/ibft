/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook_air <macbook_air@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 09:53:20 by macbook_air       #+#    #+#             */
/*   Updated: 2021/12/02 22:02:58 by macbook_air      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool				is_overflow_long(long *num, int sign, char c);
static unsigned long	ft_absl(long i);

int	ft_atoi(const char *str)
{
	long	num;
	int		sign;
	size_t	i;

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
		if (is_overflow_long(&num, sign, str[i]))
			return (num);
		num *= 10;
		num += str[i] - '0';
		i++;
	}
	return (num * sign);
}

static bool	is_overflow_long(long *num, int sign, char c)
{
	long	limit;

	limit = (long []){LONG_MIN, LONG_MAX}[sign == 1];
	if (*num > LONG_MAX / 10 || \
		(*num == LONG_MAX / 10 && c - '0' >= (int)(ft_absl(limit) % 10)))
	{
		*num = limit;
		return (true);
	}
	return (false);
}

static unsigned long	ft_absl(long i)
{
	unsigned long	u;

	u = i;
	if (u > LONG_MAX)
		u = ~i + 1;
	return (u);
}

/*#include <stdio.h>

int main(void)
{
	printf("LONG_MAX / 10: %ld\n", LONG_MAX / 10);
	printf("INT_MAX\n");
	printf("ft: %d\n", ft_atoi("2147483647"));
	printf("mm: %d\n", atoi("2147483647"));
	printf("INT_MIN\n");
	printf("ft: %d\n", ft_atoi("-2147483648"));
	printf("mm: %d\n", atoi("-2147483648"));
	printf("OVER_INT_MAX\n");
	printf("ft: %d\n", ft_atoi("214748364766"));
	printf("mm: %d\n", atoi("214748364766"));
	printf("UNDER_INT_MIN\n");
	printf("ft: %d\n", ft_atoi("-214748364877"));
	printf("mm: %d\n", atoi("-214748364877"));
	printf("LONG_MAX\n");
	printf("ft: %d\n", ft_atoi("9223372036854775807"));
	printf("mm: %d\n", atoi("9223372036854775807"));
	printf("LONG_MIN\n");
	printf("ft: %d\n", ft_atoi("-9223372036854775808"));
	printf("mm: %d\n", atoi("-9223372036854775808"));
	printf("OVER_LONG_MAX\n");
	printf("ft: %d\n", ft_atoi("922337203685477580988"));
	printf("mm: %d\n", atoi("922337203685477580988"));
	printf("UNDER_LONG_MIN\n");
	printf("ft: %d\n", ft_atoi("-922337203685477580966"));
	printf("mm: %d\n", atoi("-922337203685477580966"));
}*/