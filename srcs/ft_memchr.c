/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook_air <macbook_air@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 09:54:10 by macbook_air       #+#    #+#             */
/*   Updated: 2021/11/26 05:34:45 by macbook_air      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*p;

	p = (char *)s;
	c = (char)c;
	while (n-- > 0)
	{
		if (*p == c)
		{
			s = p;
			return ((void *)s);
		}
		p++;
	}
	return (NULL);
}
