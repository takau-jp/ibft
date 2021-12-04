/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 23:10:38 by macbook_air       #+#    #+#             */
/*   Updated: 2021/12/04 18:37:29 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*get_ascii_num(char *ascii_num, int num);
static unsigned int	ft_abs(int i);

char	*ft_itoa(int n)
{
	unsigned int	num;
	char			*ascii_num;
	int				digit;

	digit = 0;
	num = ft_abs(n);
	if (n <= 0)
		digit = 1;
	while (num > 0)
	{
		num /= 10;
		digit++;
	}
	ascii_num = (char *)malloc(sizeof(char) * (digit + 1));
	if (!ascii_num)
		return (NULL);
	get_ascii_num(ascii_num, n);
	ascii_num[digit] = '\0';
	return (ascii_num);
}

static char	*get_ascii_num(char *ascii_num, int n)
{
	unsigned int	num;

	num = ft_abs(n);
	if (n < 0)
		*ascii_num++ = '-';
	if (num >= 10)
		ascii_num = get_ascii_num(ascii_num, num / 10);
	*ascii_num++ = '0' + (num % 10);
	return (ascii_num);
}

static unsigned int	ft_abs(int i)
{
	unsigned int	u;

	u = i;
	if (i < 0)
		u = ~i + 1;
	return (u);
}
