/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_gf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 19:07:39 by stanaka           #+#    #+#             */
/*   Updated: 2022/06/15 16:32:11 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_prec_gf(t_conv *conv, t_mydb *mydouble);
void	ft_prec_gf2(t_conv *conv, t_mydb *mydouble);
int		ft_get_digits_double_gf(t_conv *conv, t_mydb mydouble);
int		ft_get_digits_double_gf2(t_conv *conv, t_mydb mydouble, int len);

int	ft_conv_gf(t_print *print, t_conv *conv, double num)
{
	int		len;
	t_mydb	mydouble;

	get_binary_double(&mydouble, num);
	convert_double(conv, &mydouble);
	ft_prec_gf(conv, &mydouble);
	if (convert_double(conv, &mydouble) && conv->prec == 0)
		return (ft_conv_ge(print, conv, num));
	ft_prec_gf2(conv, &mydouble);
	len = ft_get_digits_double_gf(conv, mydouble);
	if (mydouble.sign == 0 && conv->sign_flags)
		len++;
	if (!ft_print_buf(print, conv, len))
		return (-1);
	return (ft_put_gf(conv, &mydouble, len));
}

void	ft_prec_gf(t_conv *conv, t_mydb *mydouble)
{
	int	i;

	i = 0;
	while (i < DB_INT && mydouble->decimal_int[i] == 0)
		i++;
	ft_prec_minus_g(conv, DB_INT - i);
	if (DB_INT == i)
	{
		i = 0;
		while (i < DB_FRAC - 1 && mydouble->decimal_frac[i] == 0)
			i++;
		if (i != DB_FRAC - 1)
			conv->prec += i;
		else
			ft_prec_minus_g(conv, 1);
	}
}

void	ft_prec_gf2(t_conv *conv, t_mydb *mydouble)
{
	int			i;
	int			precision;

	i = 0;
	precision = 0;
	if (!conv->hash_flag || conv->prec_arg)
	{
		while (i < DB_FRAC - 1 && i < conv->prec)
		{
			if (mydouble->decimal_frac[i++] != 0)
				precision = i;
		}
		conv->prec = precision;
	}
}

int	ft_get_digits_double_gf(t_conv *conv, t_mydb mydouble)
{
	int	len;
	int	intlen;

	len = 0;
	if (conv->prec != 0 || conv->hash_flag)
		len = 1;
	if (mydouble.sign == 1)
		len++;
	intlen = 0;
	while (intlen < DB_INT && mydouble.decimal_int[intlen] == 0)
		intlen++;
	len += (DB_INT - intlen);
	if (intlen == DB_INT)
		len++;
	len = ft_get_digits_double_gf2(conv, mydouble, len);
	return (len);
}

int	ft_get_digits_double_gf2(t_conv *conv, t_mydb mydouble, int len)
{
	int	fraclen;

	if (conv->prec != 0 || conv->hash_flag)
	{
		len += conv->prec;
		fraclen = conv->prec;
		if (!conv->hash_flag)
		{
			while (fraclen > 0 && mydouble.decimal_frac[fraclen - 1] == 0)
				fraclen--;
			len -= (conv->prec - fraclen);
		}
	}
	return (len);
}
