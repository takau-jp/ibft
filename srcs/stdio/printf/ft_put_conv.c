/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 22:22:44 by stanaka           #+#    #+#             */
/*   Updated: 2022/06/15 16:36:53 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_etc_conv(t_print *print, t_conv *conv, va_list *ap);
int	ft_put_decimal_conv(t_print *print, t_conv *conv, va_list *ap);
int	ft_put_float_conv(t_print *print, t_conv *conv, va_list *ap);

int	ft_put_conversion(t_print *print, t_conv *conv, va_list *ap)
{
	if (ft_strchr("cs\%n", conv->c))
		return (ft_put_etc_conv(print, conv, ap));
	if (ft_strchr("pdiuxXo", conv->c))
		return (ft_put_decimal_conv(print, conv, ap));
	if (ft_strchr("fFeEgGaA", conv->c))
		return (ft_put_float_conv(print, conv, ap));
	return (0);
}

int	ft_put_etc_conv(t_print *print, t_conv *conv, va_list *ap)
{
	if (conv->length[0])
	{
		if (conv->c == 'n')
			return (ft_conv_n_len(print, conv, ap));
	}
	if (conv->c == 'c')
		return (ft_conv_c(print, conv, ap));
	if (conv->c == 's')
		return (ft_conv_s(print, conv, ap));
	if (conv->c == '%')
		return (ft_conv_percent(print, conv));
	if (conv->c == 'n')
		return (ft_conv_n(print, ap));
	return (0);
}

int	ft_put_decimal_conv(t_print *print, t_conv *conv, va_list *ap)
{
	if (conv->length[0])
	{
		if (conv->c == 'd' || conv->c == 'i')
			return (ft_conv_d_len(print, conv, ap));
		if (conv->c == 'u')
			return (ft_conv_u_len(print, conv, ap));
		if (conv->c == 'x' || conv->c == 'X')
			return (ft_conv_x_len(print, conv, ap));
		if (conv->c == 'o')
			return (ft_conv_o_len(print, conv, ap));
	}
	if (conv->c == 'p')
		return (ft_conv_p(print, conv, ap));
	if (conv->c == 'd' || conv->c == 'i')
		return (ft_conv_d(print, conv, ap));
	if (conv->c == 'u')
		return (ft_conv_u(print, conv, ap));
	if (conv->c == 'x' || conv->c == 'X')
		return (ft_conv_x(print, conv, ap));
	if (conv->c == 'o')
		return (ft_conv_o(print, conv, ap));
	return (0);
}

int	ft_put_float_conv(t_print *print, t_conv *conv, va_list *ap)
{
	if (conv->c == 'f' || conv->c == 'F')
		return (ft_conv_f(print, conv, ap));
	if (conv->c == 'e' || conv->c == 'E')
		return (ft_conv_e(print, conv, ap));
	if (conv->c == 'g' || conv->c == 'G')
		return (ft_conv_g(print, conv, ap));
	if (conv->c == 'a' || conv->c == 'A')
		return (ft_conv_a(print, conv, ap));
	return (0);
}
