/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_n_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 21:56:46 by stanaka           #+#    #+#             */
/*   Updated: 2022/06/15 16:32:46 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conv_n_len1(int res, t_conv *conv, va_list *ap);
void	ft_conv_n_len2(int res, t_conv *conv, va_list *ap);

int	ft_conv_n_len(t_print *print, t_conv *conv, va_list *ap)
{
	if (conv->length[0] == 'h')
		ft_conv_n_len1(print->res, conv, ap);
	else
		ft_conv_n_len2(print->res, conv, ap);
	return (0);
}

void	ft_conv_n_len1(int res, t_conv *conv, va_list *ap)
{
	signed char	*arg_char;
	short		*arg_short;

	if (!ft_strcmp(conv->length, "hh"))
	{
		arg_char = va_arg(*ap, signed char *);
		*arg_char = res;
	}
	else if (!ft_strcmp(conv->length, "h"))
	{
		arg_short = va_arg(*ap, short *);
		*arg_short = res;
	}
}

void	ft_conv_n_len2(int res, t_conv *conv, va_list *ap)
{
	long		*arg_long;
	long long	*arg_longlong;
	ssize_t		*arg_ssize;
	intmax_t	*arg_intmax;

	if (!ft_strcmp(conv->length, "l"))
	{
		arg_long = va_arg(*ap, long *);
		*arg_long = res;
	}
	else if (!ft_strcmp(conv->length, "ll"))
	{
		arg_longlong = va_arg(*ap, long long *);
		*arg_longlong = res;
	}
	else if (!ft_strcmp(conv->length, "z"))
	{
		arg_ssize = va_arg(*ap, ssize_t *);
		*arg_ssize = res;
	}
	else if (!ft_strcmp(conv->length, "j"))
	{
		arg_intmax = va_arg(*ap, intmax_t *);
		*arg_intmax = res;
	}
}
