/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_n.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 22:13:43 by stanaka           #+#    #+#             */
/*   Updated: 2022/06/15 16:32:34 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conv_n(t_print *print, va_list *ap)
{
	int	*arg;

	arg = va_arg(*ap, int *);
	*arg = print->res;
	return (0);
}
