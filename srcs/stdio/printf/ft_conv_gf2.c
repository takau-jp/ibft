/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_gf2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 19:12:54 by stanaka           #+#    #+#             */
/*   Updated: 2022/06/15 16:32:23 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_gf(t_conv *conv, t_mydb *mydouble, int len)
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
	res += print_mydouble_gf(conv, mydouble);
	if (conv->space_flags == '-')
		res += ft_put_width_space(conv, len);
	return (res);
}

int	print_mydouble_gf(t_conv *conv, t_mydb *mydouble)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (mydouble->decimal_int[i] == 0 && i < DB_INT - 1)
		i++;
	while (i < DB_INT)
		res += ft_putchar(mydouble->decimal_int[i++] + '0');
	if (conv->hash_flag || conv->prec > 0)
	{
		res += ft_putchar('.');
		i = 0;
		while (i < DB_FRAC - 1 && i < conv->prec)
			res += ft_putchar(mydouble->decimal_frac[i++] + '0');
	}
	if (conv->prec == 1 && conv->hash_flag)
		res += ft_putchar('.');
	return (res);
}
