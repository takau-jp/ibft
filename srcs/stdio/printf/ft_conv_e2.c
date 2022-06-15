/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_e2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 21:44:08 by stanaka           #+#    #+#             */
/*   Updated: 2022/06/15 16:29:24 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_mydouble_e2(t_conv *conv, t_mydb *mydouble, int res);
int	print_mydouble_e3(t_conv *conv, int exponent, int res);

int	ft_get_digits_double_e(t_conv *conv, t_mydb mydouble)
{
	int	len;
	int	fraclen;
	int	intlen;

	len = 1;
	if (conv->prec == 0 && !conv->hash_flag)
		len = 0;
	if (mydouble.sign == 1)
		len++;
	intlen = 1;
	fraclen = conv->prec;
	if (conv->prec == 0 && conv->hash_flag)
		fraclen = 6;
	len += intlen + fraclen;
	return (len);
}

int	print_mydouble_e(t_conv *conv, t_mydb *mydouble, int exponent)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (i < DB_INT && mydouble->decimal_int[i] == 0)
		i++;
	if (i < DB_INT)
	{
		res += ft_putchar(mydouble->decimal_int[i++] + '0');
		if (conv->prec > 0 || conv->hash_flag)
			res += ft_putchar('.');
	}
	while (i < DB_INT && conv->prec > 0)
	{
		res += ft_putchar(mydouble->decimal_int[i++] + '0');
		conv->prec--;
	}
	res = print_mydouble_e2(conv, mydouble, res);
	res = print_mydouble_e3(conv, exponent, res);
	return (res);
}

int	print_mydouble_e2(t_conv *conv, t_mydb *mydouble, int res)
{
	int	i;

	i = 0;
	if (res == 0)
	{
		while (i < DB_FRAC - 1 && mydouble->decimal_frac[i] == 0)
			i++;
		if (i < DB_FRAC - 1)
			res += ft_putchar(mydouble->decimal_frac[i++] + '0');
		else
			res += ft_putchar('0');
		if (conv->prec > 0 || conv->hash_flag)
			res += ft_putchar('.');
	}
	while (i < DB_FRAC - 1 && conv->prec > 0)
	{
		res += ft_putchar(mydouble->decimal_frac[i++] + '0');
		conv->prec--;
	}
	while (conv->prec > 0)
	{
		res += ft_putchar('0');
		conv->prec--;
	}
	return (res);
}

int	print_mydouble_e3(t_conv *conv, int exponent, int res)
{
	if (conv->c == 'e')
		res += ft_putchar('e');
	else if (conv->c == 'E')
		res += ft_putchar('E');
	if (exponent < 0)
	{
		res += ft_putchar('-');
		if (exponent > -10)
			res += ft_putchar('0') + ft_putchar('0' - exponent);
		else
			res += ft_putnbr(-exponent);
	}
	else
	{
		res += ft_putchar('+');
		if (exponent < 10)
			res += ft_putchar('0') + ft_putchar('0' + exponent);
		else
			res += ft_putnbr(exponent);
	}
	return (res);
}
