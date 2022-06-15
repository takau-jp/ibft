/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 20:59:28 by stanaka           #+#    #+#             */
/*   Updated: 2022/06/15 16:38:02 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putstr(char *str)
{
	size_t	res;
	size_t	len;

	if (!str)
		return (0);
	res = 0;
	len = ft_strlen(str);
	while (len > INT_MAX)
	{
		res += write(1, str, INT_MAX);
		str += INT_MAX;
		len -= INT_MAX;
	}
	res += write(1, str, len);
	return (res);
}
