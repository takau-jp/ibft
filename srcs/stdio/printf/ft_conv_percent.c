/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 09:33:15 by stanaka           #+#    #+#             */
/*   Updated: 2022/06/15 16:33:27 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conv_percent(t_print *print, t_conv *conv)
{
	int	res;

	res = 0;
	if (!ft_print_buf(print, conv, 1))
		return (-1);
	if (!conv->space_flags)
		res += ft_put_width_space(conv, 1);
	if (conv->space_flags == '0')
		res += ft_put_width_zero(conv, 1);
	res += ft_putchar('%');
	if (conv->space_flags == '-')
		res += ft_put_width_space(conv, 1);
	return (res);
}
