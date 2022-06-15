/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:38:51 by stanaka           #+#    #+#             */
/*   Updated: 2022/06/15 16:25:15 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		adjust_num_a(double	*num);
void	ft_prec_a(t_conv *conv, t_mydb *mydouble);
int		ft_get_len_a(t_conv *conv, t_mydb *mydouble, int exponent);
int		ft_put_a(t_conv *conv, t_mydb *mydouble, int len, int exponent);

int	ft_conv_a(t_print *print, t_conv *conv, va_list *ap)
{
	int		res;
	double	num;
	int		len;
	t_mydb	mydouble;
	int		exponent;

	if (conv->has_prec == false)
		conv->prec = 8;
	num = va_arg(*ap, double);
	res = ft_double_sp_case(print, conv, num);
	if (res)
		return (res);
	exponent = adjust_num_a(&num);
	get_binary_double(&mydouble, num);
	convert_double_hex(conv, &mydouble);
	ft_prec_a(conv, &mydouble);
	len = ft_get_len_a(conv, &mydouble, exponent);
	if (!ft_print_buf(print, conv, len))
		return (-1);
	return (ft_put_a(conv, &mydouble, len, exponent));
}

int	ft_get_len_a(t_conv *conv, t_mydb *mydouble, int exponent)
{
	int	len;

	len = ft_get_digits_double(conv, *mydouble);
	len += ft_get_digits_uint(ft_abs(exponent), 10) + 4;
	if (mydouble->sign == 0 && conv->sign_flags)
		len++;
	return (len);
}

void	ft_prec_a(t_conv *conv, t_mydb *mydouble)
{
	int	i;
	int	precision;

	i = 0;
	precision = 0;
	if (mydouble->decimal_int[DB_INT - 1] != 2)
	{
		if (!conv->hash_flag || conv->prec_arg)
		{
			while (i < DB_FRAC_HEX - 1 && i < conv->prec)
			{
				if (mydouble->decimal_frac[i++] != 0)
					precision = i;
			}
			conv->prec = precision;
		}
	}
}

int	adjust_num_a(double	*num)
{
	int	exponent;

	exponent = 0;
	while (true)
	{
		if ((-2 < *num && *num <= -1) || (1 <= *num && *num < 2) || *num == 0)
			return (exponent);
		if (-1 < *num && *num < 1)
		{
			*num *= 2;
			exponent -= 1;
		}
		if (2 <= *num)
		{
			*num /= 2;
			exponent += 1;
		}
		if (*num <= -2)
		{
			*num /= 2;
			exponent += 1;
		}
	}
}

int	ft_put_a(t_conv *conv, t_mydb *mydouble, int len, int exponent)
{
	int	res;

	res = 0;
	if (!conv->space_flags)
		res += ft_put_width_space(conv, len);
	if (mydouble->sign == 1)
		res += ft_putchar('-');
	else if (conv->sign_flags == '+')
		res += ft_putchar('+');
	else if (conv->sign_flags == ' ')
		res += ft_putchar(' ');
	if (conv->space_flags == '0')
		res += ft_put_width_zero(conv, len);
	res += print_mydouble_a(conv, mydouble, exponent);
	if (conv->space_flags == '-')
		res += ft_put_width_space(conv, len);
	return (res);
}
