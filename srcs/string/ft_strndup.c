/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 22:40:50 by stanaka           #+#    #+#             */
/*   Updated: 2021/12/04 23:19:10 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strndup(char const *s1, size_t n)
{
	char	*dst;

	dst = (char *)malloc(sizeof(char) * (n + 1));
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, s1, n + 1);
	return (dst);
}
