/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 21:42:31 by stanaka           #+#    #+#             */
/*   Updated: 2022/06/15 16:34:49 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	frac_move_up(t_conv *conv, t_mydb *mydouble);

bool	convert_double(t_conv *conv, t_mydb *mydouble)
{
	ft_memset(mydouble->decimal_frac, 0, sizeof(mydouble->decimal_frac));
	ft_memset(mydouble->decimal_int, 0, sizeof(mydouble->decimal_int));
	convert_int(mydouble);
	convert_frac(mydouble);
	return (frac_round(conv, mydouble));
}

void	convert_int(t_mydb *mydouble)
{
	int		i;
	int8_t	n[DB_INT];

	if (mydouble->exp < 1023 || mydouble->exp == 2047)
		return ;
	ft_memset(n, 0, sizeof(n));
	n[DB_INT - 1] = 1;
	i = 0;
	while (i < 53)
	{
		if (mydouble->int_bin & ((uint64_t)1 << i))
			array_add(mydouble->decimal_int, n, DB_INT);
		array_double(n, DB_INT);
		i++;
	}
	while (i++ <= mydouble->exp - 1023)
		array_double(mydouble->decimal_int, DB_INT);
}

void	convert_frac(t_mydb *mydouble)
{
	int		i;
	int8_t	n[DB_FRAC];

	if (mydouble->exp >= 52 + 1023 || \
	    (mydouble->exp == 0 && mydouble->frac == 0))
		return ;
	ft_memset(n, 0, sizeof(n));
	n[0] = 5;
	i = 0;
	while (i < (1022 - mydouble->exp))
	{
		array_half(n, DB_FRAC);
		i++;
	}
	i = 0;
	while (i < 53)
	{
		if (mydouble->frac_bin & ((uint64_t)1 << (63 - i)))
			array_add(mydouble->decimal_frac, n, DB_FRAC);
		array_half(n, DB_FRAC);
		i++;
	}
}

bool	frac_round(t_conv *conv, t_mydb *mydb)
{
	int	i;

	if (mydb->decimal_frac[conv->prec] >= 5)
	{
		if (mydb->decimal_frac[conv->prec] == 5)
		{
			if (conv->prec == 0 && !(mydb->int_bin & 1))
				return (false);
			i = conv->prec + 1;
			while (i < DB_FRAC)
			{
				if (mydb->decimal_frac[i] != 0)
					break ;
				i++;
			}
			if (i == DB_FRAC && \
				!(mydb->frac_bin & (1 << (63 - conv->prec))))
				return (false);
		}
		return (frac_move_up(conv, mydb));
	}
	return (false);
}

bool	frac_move_up(t_conv *conv, t_mydb *mydouble)
{
	int8_t	n[DB_FRAC];
	int8_t	m[DB_INT];
	int		i;
	int		original_digit;

	i = 0;
	while (i < DB_INT && mydouble->decimal_int[i] == 0)
		i++;
	original_digit = DB_INT - i;
	ft_memset(n, 0, sizeof(n));
	n[conv->prec - 1] = 1;
	array_add(mydouble->decimal_frac, n, DB_FRAC);
	i = 0;
	while (i < DB_FRAC - 1 && mydouble->decimal_frac[i] == 0)
		i++;
	if (!(i == DB_FRAC - 1 || i >= conv->prec))
		return (false);
	ft_memset(m, 0, sizeof(m));
	m[DB_INT - 1] = 1;
	array_add(mydouble->decimal_int, m, DB_INT);
	i = 0;
	while (i < DB_INT && mydouble->decimal_int[i] == 0)
		i++;
	return (original_digit != DB_INT - i);
}
