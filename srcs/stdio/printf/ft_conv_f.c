/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:38:51 by stanaka           #+#    #+#             */
/*   Updated: 2022/06/15 16:30:17 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_f(t_conv *conv, t_mydb *mydouble, int len);

int	ft_conv_f(t_print *print, t_conv *conv, va_list *ap)
{
	int		res;
	double	num;
	int		len;
	t_mydb	mydouble;

	if (conv->has_prec == false)
		conv->prec = 6;
	num = va_arg(*ap, double);
	res = ft_double_sp_case(print, conv, num);
	if (res)
		return (res);
	get_binary_double(&mydouble, num);
	convert_double(conv, &mydouble);
	len = ft_get_digits_double(conv, mydouble);
	if (mydouble.sign == 0 && conv->sign_flags)
		len++;
	if (!ft_print_buf(print, conv, len))
		return (-1);
	return (ft_put_f(conv, &mydouble, len));
}

int	ft_put_f(t_conv *conv, t_mydb *mydouble, int len)
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
	res += print_mydouble(conv, mydouble);
	if (conv->space_flags == '-')
		res += ft_put_width_space(conv, len);
	return (res);
}
