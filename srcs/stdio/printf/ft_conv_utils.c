/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 16:57:27 by stanaka           #+#    #+#             */
/*   Updated: 2022/06/15 16:33:59 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	ft_conv_len(t_conv *conv, va_list *ap, intmax_t *num)
{
	char		char_num;
	short		short_num;

	if (!ft_strcmp(conv->length, "hh"))
	{
		char_num = va_arg(*ap, int);
		*num = char_num;
	}
	else if (!ft_strcmp(conv->length, "h"))
	{
		short_num = va_arg(*ap, int);
		*num = short_num;
	}
	else if (!ft_strcmp(conv->length, "l"))
		*num = va_arg(*ap, long);
	else if (!ft_strcmp(conv->length, "ll"))
		*num = va_arg(*ap, long long);
	else if (!ft_strcmp(conv->length, "z"))
		*num = va_arg(*ap, ssize_t);
	else if (!ft_strcmp(conv->length, "j"))
		*num = va_arg(*ap, intmax_t);
	else
		return (false);
	return (true);
}

bool	ft_conv_ulen(t_conv *conv, va_list *ap, uintmax_t *num)
{
	unsigned char	uchar_num;
	unsigned short	ushort_num;

	if (!ft_strcmp(conv->length, "hh"))
	{
		uchar_num = va_arg(*ap, unsigned int);
		*num = uchar_num;
	}
	else if (!ft_strcmp(conv->length, "h"))
	{
		ushort_num = va_arg(*ap, unsigned int);
		*num = ushort_num;
	}
	else if (!ft_strcmp(conv->length, "l"))
		*num = va_arg(*ap, unsigned long);
	else if (!ft_strcmp(conv->length, "ll"))
		*num = va_arg(*ap, unsigned long long);
	else if (!ft_strcmp(conv->length, "z"))
		*num = va_arg(*ap, size_t);
	else if (!ft_strcmp(conv->length, "j"))
		*num = va_arg(*ap, uintmax_t);
	else
		return (false);
	return (true);
}
