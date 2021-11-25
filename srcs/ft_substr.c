/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook_air <macbook_air@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 20:13:31 by macbook_air       #+#    #+#             */
/*   Updated: 2021/11/24 18:57:20 by macbook_air      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	my_strcpy(char *dst, char const *s, size_t len);
size_t	ft_strnlen(char *s, size_t n);

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
		s ++;
	my_strcpy(dst, s, len);
	return (dst);
}

size_t	ft_strnlen(char *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s[i])
		i ++;
	return (i);
}

void	my_strcpy(char *dst, char const *s, size_t len)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && i < len)
	{
		dst[i] = s[i];
		i ++;
	}
	dst[i] = '\0';
}
