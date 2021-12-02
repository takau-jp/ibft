/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook_air <macbook_air@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 09:54:18 by macbook_air       #+#    #+#             */
/*   Updated: 2021/11/28 21:57:04 by macbook_air      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (dst == src)
		return (dst);
	i = 0;
	if (dst < src)
	{
		while (n > i)
		{
			*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
			i++;
		}
	}
	else
	{
		while (n > 0)
		{
			*(unsigned char *)(dst + n - 1) = *(unsigned char *)(src + n - 1);
			n--;
		}
	}
	return (dst);
}

// #include <string.h>

// int	main(void)
// {
// 	/* dst == NULL */
// 	// ft_memmove(NULL, "abc", 10);
// 	// memmove(NULL, "abc", 10);

// 	/* srcs == NULL */
// 	// ft_memmove("abc", NULL, 10);
// 	// memmove("abc", NULL, 10);

// 	/* dst == NULL && srcs == NULL */
// 	// ft_memmove(NULL, NULL, 10);
// 	// memmove(NULL, NULL, 10);
// }