/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 20:13:26 by macbook_air       #+#    #+#             */
/*   Updated: 2021/12/04 20:15:43 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strndup(char const *s, size_t len);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	end;
	bool	ascii[256];

	if (!s1)
		return (NULL);
	if (!*s1 || !set || !*set)
		return (ft_strdup(s1));
	ft_bzero(ascii, 256);
	while (*set)
		ascii[(unsigned char)*set++] = true;
	while (*s1 && ascii[(unsigned char)*s1] == true)
		s1++;
	if (!*s1)
		return (ft_strdup(""));
	end = ft_strlen(s1) - 1;
	while (ascii[(unsigned char)s1[end]] == true)
		end--;
	return (ft_strndup(s1, end + 1));
}

static char	*ft_strndup(char const *s, size_t len)
{
	char	*dst;

	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, s, len + 1);
	return (dst);
}
