/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook_air <macbook_air@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 20:13:31 by macbook_air       #+#    #+#             */
/*   Updated: 2021/11/26 06:11:29 by macbook_air      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strnlen(char *s, size_t n);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;

	if (!s)
		return (NULL);
	len = ft_strnlen((char *)s, len);
	if (start >= ft_strlen(s) || len == 0)
	{
		dst = (char *)malloc(sizeof(char) * 1);
		if (!dst)
			return (NULL);
		*dst = '\0';
		return (dst);
	}
	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	while (start-- > 0)
		s++;
	ft_strlcpy(dst, s, len + 1);
	return (dst);
}

static size_t	ft_strnlen(char *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s[i])
		i++;
	return (i);
}
