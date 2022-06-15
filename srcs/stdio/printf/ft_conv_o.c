/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 21:03:16 by stanaka           #+#    #+#             */
/*   Updated: 2022/06/15 16:33:03 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_o(t_conv *conv, unsigned int num, int len, int padding);
int	ft_put_octal(unsigned int num, int padding);

int	ft_conv_o(t_print *print, t_conv *conv, va_list *ap)
{
	unsigned int	num;
	int				len;
	int				padding;

	num = va_arg(*ap, unsigned int);
	len = ft_get_digits_uint(num, 8);
	if (conv->has_prec && conv->prec == 0 && num == 0 && !conv->hash_flag)
		len = 0;
	padding = 0;
	if (len < conv->prec)
		padding = conv->prec - len;
	if (conv->hash_flag && num != 0 && padding == 0)
		len += 1;
	len += padding;
	if (!ft_print_buf(print, conv, len))
		return (-1);
	return (ft_put_o(conv, num, len, padding));
}

int	ft_put_o(t_conv *conv, unsigned int num, int len, int padding)
{
	int	res;

	res = 0;
	if (conv->space_flags != '-' && \
		!(conv->space_flags == '0' && conv->has_prec == false))
		res += ft_put_width_space(conv, len);
	if (conv->hash_flag && num != 0 && padding == 0)
		res += ft_putchar('0');
	if (conv->space_flags == '0' && conv->has_prec == false)
		res += ft_put_width_zero(conv, len);
	if (!(num == 0 && conv->has_prec && !conv->prec && !conv->hash_flag))
		res += ft_put_octal(num, padding);
	if (conv->space_flags == '-')
		res += ft_put_width_space(conv, len);
	return (res);
}

int	ft_put_octal(unsigned int num, int padding)
{
	int				res;

	res = 0;
	while (padding)
	{
		padding--;
		res += ft_putchar('0');
	}
	if (num >= 8)
		res += ft_put_octal(num / 8, padding);
	res += ft_putchar("01234567"[num % 8]);
	return (res);
}
