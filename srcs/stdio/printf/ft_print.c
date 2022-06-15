/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 16:35:40 by stanaka           #+#    #+#             */
/*   Updated: 2022/06/15 16:36:02 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	buf_init(t_print *print);
char	*read_format(char *itr, t_print *print, t_conv *conv, va_list *ap);
char	*buf_free_error(t_print *print);
void	ft_init_conversion(t_conv *conv);

int	ft_print(char *itr, t_print *print, t_conv *conv, va_list *ap)
{
	while (*itr)
	{
		buf_init(print);
		if (!print->buf)
			return (-1);
		itr = read_format(itr, print, conv, ap);
		if (!itr)
			return (-1);
	}
	return (print->res);
}

void	buf_init(t_print *print)
{
	print->buf = malloc(sizeof(char) * 1);
	if (!print->buf)
		return ;
	print->buf[0] = '\0';
}

char	*read_format(char *itr, t_print *print, t_conv *conv, va_list *ap)
{
	int	check_res;

	ft_init_conversion(conv);
	while (*itr && *itr != '%')
	{
		print->buf = ft_join_char(print->buf, *itr++);
		if (!print->buf)
			return (NULL);
	}
	if (*itr == '%')
	{
		itr = ft_read_conversion(conv, ap, ++itr);
		if (!itr)
			return (buf_free_error(print));
		check_res = ft_put_conversion(print, conv, ap);
		if (check_res == -1)
			return (buf_free_error(print));
		print->res += check_res;
	}
	else if (!ft_print_buf(print, conv, 0))
		return (buf_free_error(print));
	free(print->buf);
	return (itr);
}

char	*buf_free_error(t_print *print)
{
	free(print->buf);
	return (NULL);
}

void	ft_init_conversion(t_conv *conv)
{
	conv->hash_flag = 0;
	conv->space_flags = 0;
	conv->sign_flags = 0;
	conv->width = 0;
	conv->has_prec = false;
	conv->prec = 0;
	conv->prec_arg = 0;
	conv->length[0] = 0;
	conv->length[1] = 0;
	conv->length[2] = '\0';
	conv->c = 0;
}
