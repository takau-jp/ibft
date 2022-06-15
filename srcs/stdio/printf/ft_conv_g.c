/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_g.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:38:51 by stanaka           #+#    #+#             */
/*   Updated: 2022/06/15 16:30:44 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_get_exp_g(double num);
void	ft_prec_minus_g(t_conv *conv, int num);

int	ft_conv_g(t_print *print, t_conv *conv, va_list *ap)
{
	int		res;
	double	num;
	t_mydb	mydouble;
	int		exponent;

	if (conv->has_prec == false)
		conv->prec = 6;
	if (conv->has_prec == true && conv->prec == 0)
		conv->prec = 1;
	num = va_arg(*ap, double);
	res = ft_double_sp_case(print, conv, num);
	if (res)
		return (res);
	get_binary_double(&mydouble, num);
	exponent = ft_get_exp(&mydouble);
	if (exponent < -4 || conv->prec <= exponent)
		return (ft_conv_ge(print, conv, num));
	return (ft_conv_gf(print, conv, num));
}

void	ft_prec_minus_g(t_conv *conv, int num)
{
	if (conv->prec >= num)
		conv->prec -= num;
	else
		conv->prec = 0;
}
