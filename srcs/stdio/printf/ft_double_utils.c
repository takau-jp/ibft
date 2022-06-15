/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 21:34:37 by stanaka           #+#    #+#             */
/*   Updated: 2022/06/15 16:34:39 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_get_int_bin(t_mydb *mydb);
void	ft_get_frac_bin(t_mydb *mydb);

void	get_binary_double(t_mydb *mydouble, double num)
{
	uint64_t	mem;

	ft_memcpy(&mem, &num, sizeof(uint64_t));
	mydouble->sign = mem >> 63;
	mydouble->exp = mem >> 52 & ~(1 << 11);
	mydouble->frac = mem << 12;
	ft_get_int_bin(mydouble);
	ft_get_frac_bin(mydouble);
}

void	ft_get_int_bin(t_mydb *mydb)
{
	int	offset;

	if (mydb->exp < 1023 || mydb->exp == 2047)
		return ;
	else if (mydb->exp < 1023 + 52)
		offset = mydb->exp - 1023;
	else
		offset = 52;
	if (offset == 0)
		mydb->int_bin = 1;
	else
		mydb->int_bin = (mydb->frac >> (64 - offset)) | (uint64_t)1 << offset;
}

void	ft_get_frac_bin(t_mydb *mydb)
{
	if (mydb->exp >= 52 + 1023 || \
	    (mydb->exp == 0 && mydb->frac == 0))
		return ;
	else if (mydb->exp >= 1023)
		mydb->frac_bin = mydb->frac << (mydb->exp - 1023);
	else if (mydb->exp == 0)
		mydb->frac_bin = mydb->frac;
	else
		mydb->frac_bin = mydb->frac >> (uint64_t)1 | ((uint64_t)1 << 63);
}
