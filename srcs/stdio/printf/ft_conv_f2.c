/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_f2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 03:27:31 by stanaka           #+#    #+#             */
/*   Updated: 2022/06/15 16:30:32 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_get_digits_double(t_conv *conv, t_mydb mydouble)
{
	int	len;
	int	intlen;
	int	fraclen;

	len = 1;
	if (conv->has_prec == true && conv->prec == 0 && !conv->hash_flag)
		len = 0;
	if (mydouble.sign == 1)
		len++;
	fraclen = conv->prec;
	len += fraclen;
	intlen = 0;
	while (intlen < DB_INT && mydouble.decimal_int[intlen] == 0)
		intlen++;
	if (intlen == DB_INT)
		intlen -= 1;
	len += (DB_INT - intlen);
	return (len);
}

int	print_mydouble(t_conv *conv, t_mydb *mydouble)
{
	int		res;
	int		i;

	res = 0;
	i = 0;
	while (mydouble->decimal_int[i] == 0 && i < DB_INT - 1)
		i++;
	while (i < DB_INT)
		res += ft_putchar(mydouble->decimal_int[i++] + '0');
	if (conv->prec != 0)
	{
		res += ft_putchar('.');
		i = 0;
		while (i < DB_FRAC - 1 && i < conv->prec)
			res += ft_putchar(mydouble->decimal_frac[i++] + '0');
		while (i++ < conv->prec)
			res += ft_putchar('0');
	}
	if (conv->prec == 0 && conv->hash_flag)
		res += ft_putchar('.');
	return (res);
}
