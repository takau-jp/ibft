/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_digits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 10:36:03 by stanaka           #+#    #+#             */
/*   Updated: 2022/06/15 16:35:10 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_get_digits(int n, int base)
{
	int				digit;
	unsigned int	num;

	digit = 0;
	num = ft_abs(n);
	if (n <= 0)
		digit++;
	while (num > 0)
	{
		num /= base;
		digit++;
	}
	return (digit);
}

int	ft_get_digits_uint(unsigned int n, int base)
{
	int	digit;

	digit = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= base;
		digit++;
	}
	return (digit);
}
