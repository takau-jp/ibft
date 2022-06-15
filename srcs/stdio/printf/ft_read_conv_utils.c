/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_conv_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 01:31:38 by stanaka           #+#    #+#             */
/*   Updated: 2022/06/15 16:50:53 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_atoi_width(const char *str)
{
	long	num;
	int		sign;
	size_t	i;

	num = 0;
	sign = 1;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] == 0)
		i++;
	while (ft_isdigit(str[i]))
	{
		if (num <= (long)(INT_MIN + 1) || (long)INT_MAX <= num)
			return (INT_MAX);
		num *= 10;
		num += str[i] - '0';
		i++;
	}
	return (num * sign);
}

bool	ft_is_longer(t_conv *conv, char *itr)
{
	if (!conv->length[0])
		return (true);
	if (!ft_strcmp(conv->length, "hh"))
		return (true);
	if (!ft_strcmp(conv->length, "h") && *itr != 'h')
		return (true);
	if (!ft_strcmp(conv->length, "l") && ft_strchr("lzj", *itr))
		return (true);
	if (!ft_strcmp(conv->length, "ll") && ft_strchr("zj", *itr))
		return (true);
	if (!ft_strcmp(conv->length, "z") && *itr == 'j')
		return (true);
	return (false);
}
