/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_ge.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 19:06:12 by stanaka           #+#    #+#             */
/*   Updated: 2022/06/15 16:30:55 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_prec_ge(t_conv *conv, t_mydb *mydouble);
void	ft_prec_ge2(t_conv *conv, t_mydb *mydouble);

int	ft_conv_ge(t_print *print, t_conv *conv, double num)
{
	t_mydb	mydouble;
	int		len;
	int		exponent;
	int		temp_prec;

	get_binary_double(&mydouble, num);
	exponent = ft_get_exp(&mydouble);
	temp_prec = conv->prec;
	ft_prec_minus_g(conv, 1);
	if (convert_double_e(conv, &mydouble, exponent))
		exponent++;
	if (!(exponent < -4 || temp_prec <= exponent))
	{
		conv->prec = temp_prec;
		return (ft_conv_gf(print, conv, num));
	}
	if (exponent <= conv->prec)
		ft_prec_ge(conv, &mydouble);
	else
		ft_prec_ge2(conv, &mydouble);
	len = ft_get_len_ge(conv, &mydouble, exponent);
	if (!ft_print_buf(print, conv, len))
		return (-1);
	return (ft_put_ge(conv, &mydouble, len, exponent));
}

void	ft_prec_ge(t_conv *conv, t_mydb *mydouble)
{
	int	i;
	int	j;
	int	precision;

	i = 0;
	while (i < DB_FRAC && mydouble->decimal_frac[i] == 0)
		i++;
	precision = 0;
	j = i;
	if (!conv->hash_flag || conv->prec_arg)
	{
		while (j < DB_FRAC && j - i <= conv->prec)
		{
			if (mydouble->decimal_frac[j] != 0)
				precision = j - i;
			j++;
		}
	}
	conv->prec = precision;
}

void	ft_prec_ge2(t_conv *conv, t_mydb *mydouble)
{
	int	i;
	int	j;

	i = 0;
	while (i < DB_INT && mydouble->decimal_int[i] == 0)
		i++;
	j = i + conv->prec;
	while (j > i && mydouble->decimal_int[j] == 0)
		j--;
	if (j - i < conv->prec)
		conv->prec = j - i;
}
