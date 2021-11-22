/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook_air <macbook_air@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 09:54:28 by macbook_air       #+#    #+#             */
/*   Updated: 2021/11/19 17:47:06 by macbook_air      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	length;
	size_t	i;
	size_t	j;

	if (ft_strlen(dst) < dstsize)
		length = ft_strlen(dst) + ft_strlen(src);
	else
		length = dstsize + ft_strlen(src);
	i = ft_strlen(dst);
	j = 0;
	while (src[j] != '\0' && dstsize > i + 1)
	{
		dst[i] = src[j];
		i ++;
		j ++;
	}
	dst[i] = '\0';
	return (length);
}
