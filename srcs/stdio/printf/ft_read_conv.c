/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_conv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 21:42:06 by stanaka           #+#    #+#             */
/*   Updated: 2022/06/15 16:38:24 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_read_flag(t_conv *conv, char *itr);
char	*ft_read_width(t_conv *conv, va_list *ap, char *itr);
char	*ft_read_precision(t_conv *conv, va_list *ap, char *itr);
char	*ft_read_length(t_conv *conv, char *itr);

char	*ft_read_conversion(t_conv *conv, va_list *ap, char *itr)
{
	if (!itr)
		return (NULL);
	while (ft_isdigit(*itr) || *itr == '*' || *itr == '.' || \
		   ft_strchr(FLAGS, *itr) || ft_strchr(LENGTH, *itr))
	{
		itr = ft_read_flag(conv, itr);
		itr = ft_read_width(conv, ap, itr);
		if (!itr)
			return (NULL);
		if (*itr == '.')
		{
			conv->has_prec = true;
			itr = ft_read_precision(conv, ap, ++itr);
			if (!itr)
				return (NULL);
		}
		itr = ft_read_length(conv, itr);
	}
	if (ft_strchr(CONV, *itr))
		conv->c = *itr++;
	else
		return (NULL);
	return (itr);
}

char	*ft_read_flag(t_conv *conv, char *itr)
{
	while (ft_strchr(FLAGS, *itr))
	{
		if (*itr == '#')
			conv->hash_flag = *itr;
		else if (*itr == '+' || *itr == ' ')
		{
			if (conv->sign_flags != '+')
				conv->sign_flags = *itr;
		}
		else
		{
			if (conv->space_flags != '-')
				conv->space_flags = *itr;
		}
		itr++;
	}
	return (itr);
}

char	*ft_read_width(t_conv *conv, va_list *ap, char *itr)
{
	if (*itr == '*')
	{
		conv->width = va_arg(*ap, int);
		if (conv->width <= INT_MIN + 1 || conv->width == INT_MAX)
			return (NULL);
		if (conv->width < 0)
		{
			conv->width = ft_abs(conv->width);
			conv->space_flags = '-';
		}
		itr++;
	}
	else if (ft_isdigit(*itr))
	{
		conv->width = ft_atoi_width(itr);
		if (conv->width == INT_MAX)
			return (NULL);
		itr += ft_get_digits(conv->width, 10);
	}
	return (itr);
}

char	*ft_read_precision(t_conv *conv, va_list *ap, char *itr)
{
	if (*itr == '*')
	{
		conv->prec_arg = '*';
		conv->prec = va_arg(*ap, int);
		if (conv->prec < 0)
		{
			conv->has_prec = false;
			conv->prec = 0;
		}
		itr++;
	}
	else if (ft_isdigit(*itr))
	{
		conv->prec = ft_atoi(itr);
		while (*itr == '0')
			itr++;
		if (ft_isdigit(*itr))
			itr += ft_get_digits(conv->prec, 10);
	}
	return (itr);
}

char	*ft_read_length(t_conv *conv, char *itr)
{
	if (ft_strchr(LENGTH, *itr) && ft_is_longer(conv, itr))
	{
		conv->length[0] = 0;
		conv->length[1] = 0;
		conv->length[0] = *itr++;
		if ((conv->length[0] == 'h' && *itr == 'h') || \
			(conv->length[0] == 'l' && *itr == 'l'))
			conv->length[1] = *itr++;
	}
	else if (ft_strchr(LENGTH, *itr))
	{
		itr++;
		if ((*(itr - 1) == 'h' && *itr == 'h') || \
			(*(itr - 1) == 'l' && *itr == 'l'))
			itr++;
	}
	return (itr);
}
