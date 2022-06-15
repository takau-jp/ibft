/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_o_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 21:03:16 by stanaka           #+#    #+#             */
/*   Updated: 2022/06/15 16:50:01 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_o_len(t_conv *conv, uintmax_t num, int len, int padding);
int	ft_put_octal_len(uintmax_t num, int padding);

int	ft_conv_o_len(t_print *print, t_conv *conv, va_list *ap)
{
	uintmax_t		num;
	int				len;
	int				padding;

	if (!ft_conv_ulen(conv, ap, &num))
		return (0);
	len = ft_get_digits_uintmax(num, 8);
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
	return (ft_put_o_len(conv, num, len, padding));
}

int	ft_put_o_len(t_conv *conv, uintmax_t num, int len, int padding)
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
		res += ft_put_octal_len(num, padding);
	if (conv->space_flags == '-')
		res += ft_put_width_space(conv, len);
	return (res);
}

int	ft_put_octal_len(uintmax_t num, int padding)
{
	int				res;

	res = 0;
	while (padding)
	{
		padding--;
		res += ft_putchar('0');
	}
	if (num >= 8)
		res += ft_put_octal_len(num / 8, padding);
	res += ft_putchar("01234567"[num % 8]);
	return (res);
}
