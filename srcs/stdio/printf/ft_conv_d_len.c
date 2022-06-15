/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_d_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 15:48:24 by stanaka           #+#    #+#             */
/*   Updated: 2022/06/15 16:28:40 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	ft_issigned_len(t_conv *conv, intmax_t d);
int		ft_put_d_len(t_conv *conv, intmax_t d, int len, int padding);
int		ft_put_num_len(intmax_t d, int padding);

int	ft_conv_d_len(t_print *print, t_conv *conv, va_list *ap)
{
	intmax_t	num;
	int			len;
	int			padding;

	if (!ft_conv_len(conv, ap, &num))
		return (0);
	len = ft_get_digits_intmax(num, 10);
	if (num >= 0 && conv->sign_flags)
		len++;
	if (conv->has_prec && conv->prec == 0 && num == 0)
		len = 0;
	padding = 0;
	if (ft_issigned_len(conv, num) && len - 1 < conv->prec)
		padding = conv->prec - (len - 1);
	else if (len < conv->prec)
		padding = conv->prec - len;
	len += padding;
	if (!ft_print_buf(print, conv, len))
		return (-1);
	return (ft_put_d_len(conv, num, len, padding));
}

bool	ft_issigned_len(t_conv *conv, intmax_t d)
{
	if (d < 0)
		return (true);
	else if (d >= 0 && conv->sign_flags)
		return (true);
	return (false);
}

int	ft_put_d_len(t_conv *conv, intmax_t d, int len, int padding)
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
		res += ft_put_num_len(d, padding);
	if (conv->space_flags == '-')
		res += ft_put_width_space(conv, len);
	return (res);
}

int	ft_put_num_len(intmax_t d, int padding)
{
	int			res;
	uintmax_t	num;

	res = 0;
	num = ft_abs_intmax(d);
	while (padding)
	{
		padding--;
		res += ft_putchar('0');
	}
	if (num >= 10)
		res += ft_put_num_len(num / 10, padding);
	res += ft_putchar("0123456789"[num % 10]);
	return (res);
}
