/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 08:01:38 by stanaka           #+#    #+#             */
/*   Updated: 2022/06/15 16:33:14 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_p(t_conv *conv, uintptr_t address, int len, int padding);
int	ft_put_address(uintptr_t num, int padding);

int	ft_conv_p(t_print *print, t_conv *conv, va_list *ap)
{
	unsigned long	address;
	int				len;
	int				padding;

	address = va_arg(*ap, unsigned long);
	len = ft_get_digits_uintptr(address, 16);
	if (address == 0 && conv->has_prec && conv->prec == 0)
		len = 0;
	padding = 0;
	if (len < conv->prec)
		padding = conv->prec - len;
	len += padding;
	if (!ft_print_buf(print, conv, len))
		return (-1);
	return (ft_put_p(conv, address, len + 2, padding));
}

int	ft_put_p(t_conv *conv, uintptr_t address, int len, int padding)
{
	int	res;

	res = 0;
	if (conv->space_flags != '-')
		res += ft_put_width_space(conv, len);
	if (address == 0 && conv->has_prec && conv->prec == 0)
		res += ft_putstr("0x");
	else
		res += ft_putstr("0x") + ft_put_address(address, padding);
	if (conv->space_flags == '-')
		res += ft_put_width_space(conv, len);
	return (res);
}

int	ft_put_address(uintptr_t num, int padding)
{
	int	res;

	res = 0;
	while (padding)
	{
		padding--;
		res += ft_putchar('0');
	}
	if (num >= 16)
		res += ft_put_address(num / 16, padding);
	res += ft_putchar("0123456789abcdef"[num % 16]);
	return (res);
}
