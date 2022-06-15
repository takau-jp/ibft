/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_buf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 14:05:01 by stanaka           #+#    #+#             */
/*   Updated: 2022/06/15 16:36:32 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	ft_print_buf(t_print *print, t_conv *conv, int len)
{
	size_t	buf_len;
	int		put_len;

	buf_len = ft_strlen(print->buf);
	if (len >= conv->width)
		put_len = len;
	else
		put_len = conv->width;
	if (print->res + buf_len + put_len >= INT_MAX)
	{
		print->res = -1;
		return (false);
	}
	print->res += write(1, print->buf, buf_len);
	return (true);
}
