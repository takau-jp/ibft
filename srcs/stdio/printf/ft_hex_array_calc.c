/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_array_calc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 12:53:34 by stanaka           #+#    #+#             */
/*   Updated: 2022/06/15 16:35:35 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	array_add_hex(int8_t *a, int8_t *b, int size)
{
	int	i;

	i = size - 1;
	while (i >= 0)
	{
		a[i] += b[i];
		if (a[i] >= 16 && i != 0)
		{
			a[i] -= 16;
			a[i - 1] += 1;
		}
		if (a[i] >= 16 && i == 0)
			a[i] -= 16;
		i--;
	}
}

void	array_half_hex(int8_t *n, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		n[i + 1] += (n[i] % 2) * 16;
		n[i] /= 2;
		i++;
	}
}

void	array_double_hex(int8_t *n, int size)
{
	int	i;

	i = size - 1;
	while (i >= 0)
	{
		n[i] *= 2;
		if (i < size - 1 && n[i + 1] >= 16)
		{
			n[i] += 1;
			n[i + 1] -= 16;
		}
		i--;
	}
}
