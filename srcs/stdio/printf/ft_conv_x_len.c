/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_x_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:53:25 by stanaka           #+#    #+#             */
/*   Updated: 2022/06/15 16:34:23 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_put_x_len(t_conv *conv, uintmax_t num, int len, int padding);
int		ft_put_X_len(t_conv *conv, uintmax_t num, int len, int padding);

int	ft_conv_x_len(t_print *print, t_conv *conv, va_list *ap)
{
	uintmax_t		num;
	int				len;
	int				padding;

	if (!ft_conv_ulen(conv, ap, &num))
		return (0);
	len = ft_get_digits_uintmax(num, 16);
	if (conv->has_prec && conv->prec == 0 && num == 0)
		len = 0;
	padding = 0;
	if (len < conv->prec)
		padding = conv->prec - len;
	len += padding;
	if (!ft_print_buf(print, conv, len))
		return (-1);
	return (ft_put_x_len(conv, num, len, padding));
}

int	ft_put_x_len(t_conv *conv, uintmax_t num, int len, int padding)
{
	int	res;

	res = 0;
	if (conv->has_prec && conv->prec == 0 && num == 0)
		return (ft_put_width_space(conv, len));
	if (conv->hash_flag && num != 0)
		len += 2;
	if (conv->space_flags != '-' && \
		!(conv->space_flags == '0' && conv->has_prec == false))
		res += ft_put_width_space(conv, len);
	if (conv->hash_flag && num != 0 && conv->c == 'x')
		res += ft_putstr("0x");
	if (conv->hash_flag && num != 0 && conv->c == 'X')
		res += ft_putstr("0X");
	if (conv->space_flags == '0' && conv->has_prec == false)
		res += ft_put_width_zero(conv, len);
	if (conv->c == 'x')
		res += ft_put_lower_hexa_len(num, padding);
	else
		res += ft_put_upper_hexa_len(num, padding);
	if (conv->space_flags == '-')
		res += ft_put_width_space(conv, len);
	return (res);
}

int	ft_put_lower_hexa_len(uintmax_t num, int padding)
{
	int	res;

	res = 0;
	while (padding)
	{
		padding--;
		res += ft_putchar('0');
	}
	if (num >= 16)
		res += ft_put_lower_hexa_len(num / 16, padding);
	res += ft_putchar("0123456789abcdef"[num % 16]);
	return (res);
}

int	ft_put_upper_hexa_len(uintmax_t num, int padding)
{
	int				res;

	res = 0;
	while (padding)
	{
		padding--;
		res += ft_putchar('0');
	}
	if (num >= 16)
		res += ft_put_upper_hexa_len(num / 16, padding);
	res += ft_putchar("0123456789ABCDEF"[num % 16]);
	return (res);
}
