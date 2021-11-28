/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook_air <macbook_air@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 09:54:28 by macbook_air       #+#    #+#             */
/*   Updated: 2021/11/28 00:05:28 by macbook_air      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	length;
	size_t	i;
	size_t	j;

	if (!dstsize)
		return (ft_strlen(src));
	i = ft_strlen(dst);
	if (i < dstsize)
		length = i + ft_strlen(src);
	else
		length = dstsize + ft_strlen(src);
	j = 0;
	while (dstsize > i + 1 && src[j])
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (length);
}
