/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook_air <macbook_air@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 19:07:37 by macbook_air       #+#    #+#             */
/*   Updated: 2021/12/01 21:36:54 by macbook_air      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_split(char const *s, char c);
static bool		str_split(char const *s, char c, char **split, size_t count);
static char		*ft_strndup(char const *s, size_t len);

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	count;

	if (!s)
		return (NULL);
	count = count_split(s, c);
	split = (char **)malloc(sizeof(char *) * (count + 1));
	if (!split)
		return (NULL);
	if (!str_split(s, c, split, count))
		return (NULL);
	split[count] = 0;
	return (split);
}

static size_t	count_split(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s != '\0')
	{
		while (*s == c && *s != '\0')
			s++;
		if (*s != '\0')
			count++;
		while (*s != c && *s != '\0')
			s++;
	}
	return (count);
}

static bool	str_split(char const *s, char c, char **split, size_t count)
{
	size_t	len;
	size_t	n;

	n = 0;
	while (n < count)
	{
		len = 0;
		while (*s == c && *s != '\0')
			s++;
		while (*s != c && *s != '\0')
		{
			len++;
			s++;
		}
		split[n] = ft_strndup((s - len), len);
		if (!split[n])
		{
			while (n-- > 0)
				free(split[n]);
			free(split);
			return (false);
		}
		n++;
	}
	return (true);
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
