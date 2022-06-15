/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_ge2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:05:23 by stanaka           #+#    #+#             */
/*   Updated: 2022/06/15 16:31:05 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_get_digits_db_ge(t_conv *conv, t_mydb mydouble);
int	ft_get_digits_db_ge2(t_conv *conv, t_mydb mydb, int intlen, int len);

int	ft_get_len_ge(t_conv *conv, t_mydb *mydouble, int exponent)
{
	int	len;

	len = 0;
	len = ft_get_digits_db_ge(conv, *mydouble);
	len += ft_get_digits(ft_abs(exponent), 10) + 2;
	if (-10 < exponent && exponent < 10)
		len += 1;
	if (mydouble->sign == 0 && conv->sign_flags)
		len += 1;
	return (len);
}

int	ft_get_digits_db_ge(t_conv *conv, t_mydb mydouble)
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
		fraclen = 5;
	len += intlen + fraclen;
	return (len);
}

int	ft_get_digits_db_ge2(t_conv *conv, t_mydb mydb, int intlen, int len)
{
	int	fraclen;

	fraclen = 0;
	if (intlen == DB_INT)
	{
		while (fraclen < DB_FRAC && mydb.decimal_frac[fraclen] == 0)
			fraclen++;
	}
	while (fraclen < conv->prec)
	{
		fraclen++;
		len++;
	}
	while (fraclen > 0 && mydb.decimal_frac[fraclen - 1] == 0)
	{
		fraclen--;
		len--;
	}
	return (len);
}
