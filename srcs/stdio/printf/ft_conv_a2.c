/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_a2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:34:56 by stanaka           #+#    #+#             */
/*   Updated: 2022/06/15 16:25:54 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convert_int_hex(t_mydb *mydouble);
void	convert_frac_hex(t_conv *conv, t_mydb *mydouble);
void	frac_round_hex(t_conv *conv, t_mydb *mydouble);
void	frac_move_up_hex(t_conv *conv, t_mydb *mydouble);

void	convert_double_hex(t_conv *conv, t_mydb *mydouble)
{
	ft_memset(mydouble->decimal_frac, 0, sizeof(mydouble->decimal_frac));
	ft_memset(mydouble->decimal_int, 0, sizeof(mydouble->decimal_int));
	convert_int_hex(mydouble);
	convert_frac_hex(conv, mydouble);
}

void	convert_int_hex(t_mydb *mydouble)
{
	if (mydouble->int_bin == 1)
		mydouble->decimal_int[DB_INT - 1] = 1;
}

void	convert_frac_hex(t_conv *conv, t_mydb *mydouble)
{
	int		i;
	int8_t	n[DB_FRAC_HEX];

	ft_memset(n, 0, sizeof(n));
	n[0] = 8;
	i = 0;
	while (i < (1022 - mydouble->exp))
	{
		array_half_hex(n, DB_FRAC_HEX);
		i++;
	}
	i = 0;
	while (i < 53)
	{
		if (mydouble->frac_bin & ((uint64_t)1 << (63 - i)))
			array_add_hex(mydouble->decimal_frac, n, DB_FRAC_HEX);
		array_half_hex(n, DB_FRAC_HEX);
		i++;
	}
	conv->sign_flags = 0;
	frac_round_hex(conv, mydouble);
}

void	frac_round_hex(t_conv *conv, t_mydb *mydouble)
{
	int	i;

	if (mydouble->decimal_frac[conv->prec] >= 8)
	{
		if (mydouble->decimal_frac[conv->prec] == 8)
		{
			if (conv->prec == 0 && !(mydouble->int_bin & 1))
				return ;
			i = conv->prec + 1;
			while (i < DB_FRAC_HEX)
			{
				if (mydouble->decimal_frac[i] != 0)
					break ;
				i++;
			}
			if (i == DB_FRAC_HEX)
			{
				if (!(mydouble->frac_bin & (1 << (63 - conv->prec))))
					return ;
			}
		}
		frac_move_up_hex(conv, mydouble);
	}
}

void	frac_move_up_hex(t_conv *conv, t_mydb *mydouble)
{
	int8_t	n[DB_FRAC_HEX];
	int		i;

	ft_memset(n, 0, sizeof(n));
	n[conv->prec - 1] = 1;
	array_add_hex(mydouble->decimal_frac, n, DB_FRAC_HEX);
	i = 0;
	while (i < DB_FRAC_HEX - 1 && mydouble->decimal_frac[i] == 0)
		i++;
	if (i == DB_FRAC_HEX - 1 || i >= conv->prec)
		mydouble->decimal_int[DB_INT - 1] += 1;
}
