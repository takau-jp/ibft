/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook_air <macbook_air@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 09:54:16 by macbook_air       #+#    #+#             */
/*   Updated: 2021/11/28 21:55:09 by macbook_air      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (dst == src)
		return (dst);
	i = 0;
	while (n > i)
	{
		*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
		i++;
	}
	return (dst);
}

// #include <string.h>

// int	main(void)
// {
// 	/* dst == NULL */
// 	// ft_memcpy(NULL, "abc", 10);
// 	// memcpy(NULL, "abc", 10);

// 	/* srcs == NULL */
// 	// ft_memcpy("abc", NULL, 10);
// 	// memcpy("abc", NULL, 10);

// 	/* dst == NULL && srcs == NULL */
// 	// ft_memcpy(NULL, NULL, 10);
// 	// memcpy(NULL, NULL, 10);
// }