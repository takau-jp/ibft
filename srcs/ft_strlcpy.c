/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook_air <macbook_air@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 09:54:31 by macbook_air       #+#    #+#             */
/*   Updated: 2021/10/21 09:54:32 by macbook_air      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize != 0)
	{
		while (i + 1 < dstsize && src[i] != '\0')
		{
			dst[i] = src[i];
			i ++;
		}
		dst[i] = '\0';
	}
	while (src[i] != '\0')
		i ++;
	return (i);
}
