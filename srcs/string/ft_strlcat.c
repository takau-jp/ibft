/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 09:54:28 by macbook_air       #+#    #+#             */
/*   Updated: 2021/12/04 23:21:13 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;

	dstlen = ft_strnlen(dst, dstsize);
	srclen = ft_strlen(src);
	if (dstlen == dstsize)
		return (dstlen + srclen);
	if (srclen < dstsize - dstlen)
		ft_strlcpy(dst + dstlen, src, srclen + 1);
	else
		ft_strlcpy(dst + dstlen, src, dstsize - dstlen);
	return (dstlen + srclen);
}
