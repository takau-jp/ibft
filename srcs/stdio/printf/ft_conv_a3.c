/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_a3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:43:38 by stanaka           #+#    #+#             */
/*   Updated: 2022/06/15 16:26:27 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_mydouble_a2(t_conv *conv, int exponent);
int	ft_put_hex(t_conv *conv, int num);

int	print_mydouble_a(t_conv *conv, t_mydb *mydouble, int exponent)
{
	int		res;
	int		i;

	res = 0;
	if (conv->c == 'a')
		res += ft_putstr("0x");
	else if (conv->c == 'A')
		res += ft_putstr("0X");
	res += ft_putchar(mydouble->decimal_int[DB_INT - 1] + '0');
	if (conv->prec != 0)
	{
		res += ft_putchar('.');
		i = 0;
		while (i < DB_FRAC - 1 && i < conv->prec)
			res += ft_put_hex(conv, mydouble->decimal_frac[i++]);
		while (i++ < conv->prec)
			res += ft_putchar('0');
	}
	return (res + print_mydouble_a2(conv, exponent));
}

int	print_mydouble_a2(t_conv *conv, int exponent)
{
	int		res;

	res = 0;
	if (conv->c == 'a')
		res += ft_putchar('p');
	else if (conv->c == 'A')
		res += ft_putchar('P');
	if (exponent < 0)
		res += ft_putnbr(exponent);
	else
	{
		res += ft_putchar('+');
		res += ft_putnbr(exponent);
	}
	return (res);
}

int	ft_put_hex(t_conv *conv, int num)
{
	if (0 <= num && num <= 9)
		return (ft_putchar(num + '0'));
	else if (conv->c == 'a' && 10 <= num && num < 16)
		return (ft_putchar(num - 10 + 'a'));
	else if (conv->c == 'A' && 10 <= num && num < 16)
		return (ft_putchar(num - 10 + 'A'));
	return (0);
}
