/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:16:22 by stanaka           #+#    #+#             */
/*   Updated: 2022/06/15 16:28:46 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	ft_issigned(t_conv *conv, int d);
int		ft_put_num(int d, int padding);
int		ft_put_d(t_conv *conv, int d, int len, int padding);

int	ft_conv_d(t_print *print, t_conv *conv, va_list *ap)
{
	int	d;
	int	len;
	int	padding;

	d = va_arg(*ap, int);
	len = ft_get_digits(d, 10);
	if (d >= 0 && conv->sign_flags)
		len++;
	if (conv->has_prec && conv->prec == 0 && d == 0)
		len = 0;
	padding = 0;
	if (ft_issigned(conv, d) && len - 1 < conv->prec)
		padding = conv->prec - (len - 1);
	else if (len < conv->prec)
		padding = conv->prec - len;
	len += padding;
	if (!ft_print_buf(print, conv, len))
		return (-1);
	return (ft_put_d(conv, d, len, padding));
}

bool	ft_issigned(t_conv *conv, int d)
{
	if (d < 0)
		return (true);
	else if (d >= 0 && conv->sign_flags)
		return (true);
	return (false);
}

int	ft_put_d(t_conv *conv, int d, int len, int padding)
{
	int	res;

	res = 0;
	if (conv->space_flags != '-' && \
		!(conv->space_flags == '0' && conv->has_prec == false))
		res += ft_put_width_space(conv, len);
	if (d < 0)
		res += ft_putchar('-');
	else if (d >= 0 && conv->sign_flags == '+')
		res += ft_putchar('+');
	else if (d >= 0 && conv->sign_flags == ' ')
		res += ft_putchar(' ');
	if (conv->space_flags == '0' && conv->has_prec == false)
		res += ft_put_width_zero(conv, len);
	if (!(conv->has_prec && conv->prec == 0 && d == 0))
		res += ft_put_num(d, padding);
	if (conv->space_flags == '-')
		res += ft_put_width_space(conv, len);
	return (res);
}

int	ft_put_num(int d, int padding)
{
	int				res;
	unsigned int	num;

	res = 0;
	num = ft_abs(d);
	while (padding)
	{
		padding--;
		res += ft_putchar('0');
	}
	if (num >= 10)
		res += ft_put_num(num / 10, padding);
	res += ft_putchar("0123456789"[num % 10]);
	return (res);
}
