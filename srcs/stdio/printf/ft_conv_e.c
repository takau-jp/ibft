/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_e.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:38:51 by stanaka           #+#    #+#             */
/*   Updated: 2022/06/15 16:29:05 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_get_len_e(t_conv *conv, t_mydb *mydouble, int exponent);
int		ft_put_e(t_conv *conv, t_mydb *mydouble, int len, int exponent);
void	ft_prec_e(t_conv *conv, t_mydb *mydouble);

int	ft_conv_e(t_print *print, t_conv *conv, va_list *ap)
{
	int		res;
	double	num;
	int		len;
	t_mydb	mydouble;
	int		exponent;

	if (conv->has_prec == false)
		conv->prec = 6;
	num = va_arg(*ap, double);
	res = ft_double_sp_case(print, conv, num);
	if (res)
		return (res);
	get_binary_double(&mydouble, num);
	exponent = ft_get_exp(&mydouble);
	if (convert_double_e(conv, &mydouble, exponent))
		exponent++;
	len = ft_get_len_e(conv, &mydouble, exponent);
	if (!ft_print_buf(print, conv, len))
		return (-1);
	return (ft_put_e(conv, &mydouble, len, exponent));
}

void	ft_prec_e(t_conv *conv, t_mydb *mydouble)
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

int	ft_get_len_e(t_conv *conv, t_mydb *mydouble, int exponent)
{
	int	len;

	len = ft_get_digits_double_e(conv, *mydouble);
	len += ft_get_digits(ft_abs(exponent), 10) + 2;
	if (-10 < exponent && exponent < 10)
		len += 1;
	if (mydouble->sign == 0 && conv->sign_flags)
		len++;
	return (len);
}

int	ft_get_exp(t_mydb *mydouble)
{
	int	i;

	convert_double_simple(mydouble);
	i = 0;
	while (i < DB_INT && mydouble->decimal_int[i] == 0)
		i++;
	if (i < DB_INT)
		return (DB_INT - i - 1);
	i = 0;
	while (i < DB_FRAC - 1 && mydouble->decimal_frac[i] == 0)
		i++;
	if (i < DB_FRAC - 1)
		return (-i - 1);
	return (0);
}

int	ft_put_e(t_conv *conv, t_mydb *mydouble, int len, int exponent)
{
	int	res;

	res = 0;
	if (conv->space_flags != '-' && \
		!(conv->space_flags == '0' && conv->has_prec == false))
		res += ft_put_width_space(conv, len);
	if (mydouble->sign == 1)
		res += ft_putchar('-');
	else if (conv->sign_flags == '+')
		res += ft_putchar('+');
	else if (conv->sign_flags == ' ')
		res += ft_putchar(' ');
	if (conv->space_flags == '0' && conv->has_prec == false)
		res += ft_put_width_zero(conv, len);
	res += print_mydouble_e(conv, mydouble, exponent);
	if (conv->space_flags == '-')
		res += ft_put_width_space(conv, len);
	return (res);
}
