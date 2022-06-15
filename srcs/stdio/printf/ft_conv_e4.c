/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_e4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:50:50 by stanaka           #+#    #+#             */
/*   Updated: 2022/06/15 16:29:54 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	frac_move_up_e(t_conv *conv, t_mydb *mydouble);
bool	frac_move_up_e2(t_conv *conv, t_mydb *mydouble, int original_digit);
bool	frac_move_up_e3(t_conv *conv, t_mydb *mydouble, int original_digit);

bool	frac_round_e(t_conv *conv, t_mydb *mydb)
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
		return (frac_move_up_e(conv, mydb));
	}
	return (false);
}

bool	frac_move_up_e(t_conv *conv, t_mydb *mydouble)
{
	int		i;

	i = 0;
	while (i < DB_INT && mydouble->decimal_int[i] == 0)
		i++;
	if (i == DB_INT)
	{
		i = 0;
		while (i < DB_FRAC - 1 && mydouble->decimal_frac[i] == 0)
			i++;
		return (frac_move_up_e2(conv, mydouble, i));
	}
	else
		return (frac_move_up_e3(conv, mydouble, DB_INT - i));
	return (false);
}

bool	frac_move_up_e2(t_conv *conv, t_mydb *mydouble, int original_digit)
{
	int8_t	n[DB_FRAC];
	int8_t	m[DB_INT];
	int		i;

	ft_memset(n, 0, sizeof(n));
	n[conv->prec - 1] = 1;
	array_add(mydouble->decimal_frac, n, DB_FRAC);
	i = 0;
	while (i < DB_FRAC - 1 && mydouble->decimal_frac[i] == 0)
		i++;
	if (i == DB_FRAC - 1 || i >= conv->prec)
	{
		ft_memset(m, 0, sizeof(m));
		m[DB_INT - 1] = 1;
		array_add(mydouble->decimal_int, m, DB_INT);
	}
	if (original_digit != i)
		return (true);
	return (false);
}

bool	frac_move_up_e3(t_conv *conv, t_mydb *mydouble, int original_digit)
{
	int8_t	n[DB_FRAC];
	int8_t	m[DB_INT];
	int		i;

	ft_memset(n, 0, sizeof(n));
	n[conv->prec - 1] = 1;
	array_add(mydouble->decimal_frac, n, DB_FRAC);
	i = 0;
	while (i < DB_FRAC - 1 && mydouble->decimal_frac[i] == 0)
		i++;
	if (i == DB_FRAC - 1 || i >= conv->prec)
	{
		ft_memset(m, 0, sizeof(m));
		m[DB_INT - 1] = 1;
		array_add(mydouble->decimal_int, m, DB_INT);
		i = 0;
		while (i < DB_INT && mydouble->decimal_int[i] == 0)
			i++;
		if (original_digit != DB_INT - i)
			return (true);
	}
	return (false);
}
