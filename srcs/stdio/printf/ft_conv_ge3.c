/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_ge3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 22:38:57 by stanaka           #+#    #+#             */
/*   Updated: 2022/06/15 16:31:56 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_mydouble_ge2(t_conv *conv, t_mydb *mydouble, int res);
int	print_mydouble_ge3(t_conv *conv, int exponent, int res);

int	ft_put_ge(t_conv *conv, t_mydb *mydouble, int len, int exp)
{
	int	res;

	res = 0;
	if (conv->space_flags != '-' && conv->space_flags != '0')
		res += ft_put_width_space(conv, len);
	if (mydouble->sign == 1)
		res += ft_putchar('-');
	else if (conv->sign_flags == '+')
		res += ft_putchar('+');
	else if (conv->sign_flags == ' ')
		res += ft_putchar(' ');
	if (conv->space_flags == '0')
		res += ft_put_width_zero(conv, len);
	res += print_mydouble_ge(conv, mydouble, exp);
	if (conv->space_flags == '-')
		res += ft_put_width_space(conv, len);
	return (res);
}

int	print_mydouble_ge(t_conv *conv, t_mydb *mydouble, int exponent)
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
		if (conv->hash_flag || conv->prec > 0)
			res += ft_putchar('.');
	}
	while (i < DB_INT && conv->prec > 0)
	{
		res += ft_putchar(mydouble->decimal_int[i++] + '0');
		conv->prec--;
	}
	res = print_mydouble_ge2(conv, mydouble, res);
	if (exponent != 0)
		res = print_mydouble_ge3(conv, exponent, res);
	return (res);
}

int	print_mydouble_ge2(t_conv *conv, t_mydb *mydouble, int res)
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

int	print_mydouble_ge3(t_conv *conv, int exponent, int res)
{
	if (conv->c == 'g')
		res += ft_putchar('e');
	else if (conv->c == 'G')
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
