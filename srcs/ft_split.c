/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook_air <macbook_air@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 19:07:37 by macbook_air       #+#    #+#             */
/*   Updated: 2021/11/26 06:38:08 by macbook_air      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_split(char const *s, char c);
static bool		str_split(char const *s, char c, char **split, size_t count);
static char		*split_strdup(char const *s, size_t len);

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	count;

	if (!s)
		return (NULL);
	count = count_split(s, c);
	split = (char **)malloc(sizeof(char *) * (count + 1));
	if (!split)
	{
		free(split);
		return (NULL);
	}
	if (!str_split(s, c, split, count))
		return (NULL);
	split[count] = 0;
	return (split);
}

static size_t	count_split(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (i == 0 && s[i] != c)
			count++;
		else if (s[i] == c && i == 0)
			;
		else if (s[i - 1] == c && s[i] != c)
			count++;
		i++;
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
		split[n] = split_strdup((s - len), len);
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

static char	*split_strdup(char const *s, size_t len)
{
	char	*dst;

	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, s, len + 1);
	return (dst);
}
