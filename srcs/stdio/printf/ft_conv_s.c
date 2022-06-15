/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 11:59:16 by stanaka           #+#    #+#             */
/*   Updated: 2022/06/15 16:33:38 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_s(t_conv *conv, char *s, size_t len);

int	ft_conv_s(t_print *print, t_conv *conv, va_list *ap)
{
	size_t	len;
	char	*s;

	s = va_arg(*ap, char *);
	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	if (conv->has_prec && len > (size_t)conv->prec)
		len = conv->prec;
	if (!ft_print_buf(print, conv, len))
		return (-1);
	return (ft_put_s(conv, s, len));
}

int	ft_put_s(t_conv *conv, char *s, size_t len)
{
	int	res;

	res = 0;
	if (!conv->space_flags)
		res += ft_put_width_space(conv, len);
	if (conv->space_flags == '0')
		res += ft_put_width_zero(conv, len);
	res += ft_putstrl(s, len);
	if (conv->space_flags == '-')
		res += ft_put_width_space(conv, len);
	return (res);
}
