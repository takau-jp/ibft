/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_digits_long.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 19:59:35 by stanaka           #+#    #+#             */
/*   Updated: 2022/06/15 16:35:21 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_get_digits_uintptr(uintptr_t n, int base)
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

int	ft_get_digits_intmax(intmax_t n, int base)
{
	int			digit;
	uintmax_t	num;

	digit = 0;
	num = ft_abs_intmax(n);
	if (n <= 0)
		digit++;
	while (num > 0)
	{
		num /= base;
		digit++;
	}
	return (digit);
}

int	ft_get_digits_uintmax(uintmax_t n, int base)
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
