/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook_air <macbook_air@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 09:54:22 by macbook_air       #+#    #+#             */
/*   Updated: 2021/11/17 19:12:48 by macbook_air      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const char	*p;

	p = NULL;
	c = (char)c;
	while (1)
	{
		if (*s == c)
		{
			p = s;
			return ((char *)p);
		}
		if (*s == '\0')
			return ((char *)p);
		s++;
	}
}
