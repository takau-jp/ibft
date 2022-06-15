/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_e3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 23:40:14 by stanaka           #+#    #+#             */
/*   Updated: 2022/06/15 16:29:39 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	convert_int_e(t_conv *conv, t_mydb *mydouble, int exp);

bool	convert_double_e(t_conv *conv, t_mydb *mydouble, int exp)
{
	ft_memset(mydouble->decimal_frac, 0, sizeof(mydouble->decimal_frac));
	ft_memset(mydouble->decimal_int, 0, sizeof(mydouble->decimal_int));
	convert_int(mydouble);
	if (convert_int_e(conv, mydouble, exp))
		return (true);
	if (exp <= conv->prec)
	{
		conv->prec -= exp;
		convert_frac(mydouble);
		if (frac_round_e(conv, mydouble))
		{
			conv->prec += exp;
			return (true);
		}
		conv->prec += exp;
	}
	return (false);
}

bool	convert_int_e(t_conv *conv, t_mydb *mydouble, int exp)
{
	int8_t	m[DB_INT];
	int		i;

	if (DB_INT > exp - conv->prec && exp >= conv->prec)
	{
		if (mydouble->decimal_int[DB_INT - (exp - (conv->prec))] >= 5)
		{
			ft_memset(m, 0, sizeof(m));
			m[DB_INT - (exp - (conv->prec)) - 1] = 1;
			array_add(mydouble->decimal_int, m, DB_INT);
			i = 0;
			while (i < DB_INT && mydouble->decimal_int[i] == 0)
				i++;
			if (i == DB_INT || i < DB_INT - 1 - exp)
			{
				return (true);
			}
		}
	}
	return (false);
}
