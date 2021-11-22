/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook_air <macbook_air@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 09:54:18 by macbook_air       #+#    #+#             */
/*   Updated: 2021/11/22 14:04:07 by macbook_air      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	size_t	i;

	if (!s1 && !s2)
		return (NULL);
	i = 0;
	if (s1 < s2)
	{
		while (n > i)
		{
			*(unsigned char *)(s1 + i) = *(unsigned char *)(s2 + i);
			i ++;
		}
	}
	else
	{
		while (n -- > 0)
			*(unsigned char *)(s1 + n) = *(unsigned char *)(s2 + n);
	}
	return (s1);
}
