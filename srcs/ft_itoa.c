/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook_air <macbook_air@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 23:10:38 by macbook_air       #+#    #+#             */
/*   Updated: 2021/11/17 19:04:01 by macbook_air      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*malloc_ascii_num(char *ascii_num, int n);
char	*get_ascii_num(char *ascii_num, int num);

char	*ft_itoa(int n)
{
	char	*ascii_num;

	ascii_num = NULL;
	if (n == -2147483648)
	{
		ascii_num = (char *)malloc(sizeof(char) * 12);
		if (!ascii_num)
			return (NULL);
		ft_strlcpy(ascii_num, "-2147483648", 12);
		return (ascii_num);
	}
	ascii_num = malloc_ascii_num(ascii_num, n);
	if (!ascii_num)
		return (NULL);
	return (ascii_num);
}

char	*malloc_ascii_num(char *ascii_num, int n)
{
	int		digit;
	int		num;

	digit = 0;
	num = n;
	if (n <= 0)
	{
		digit = 1;
		num *= -1;
	}
	while (num >= 1)
	{
		num /= 10;
		digit ++;
	}
	ascii_num = (char *)malloc(sizeof(char) * (digit + 1));
	if (!ascii_num)
		return (NULL);
	ascii_num[0] = '0';
	get_ascii_num(ascii_num, n);
	ascii_num[digit] = '\0';
	return (ascii_num);
}

char	*get_ascii_num(char *ascii_num, int n)
{
	if (n < 0)
	{
		n *= -1;
		*ascii_num = '-';
		ascii_num ++;
	}
	if (n < 10)
	{
		*ascii_num = '0' + n;
		return (++ascii_num);
	}
	ascii_num = get_ascii_num(ascii_num, n / 10);
	*ascii_num = '0' + (n % 10);
	return (++ascii_num);
}
