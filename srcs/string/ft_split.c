/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 19:07:37 by macbook_air       #+#    #+#             */
/*   Updated: 2021/12/05 01:05:57 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_split(char const *s, char c);
static char		**str_split(char const *s, char c, char **split, size_t count);

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
	split[count] = NULL;
	return (str_split(s, c, split, count));
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

static char	**str_split(char const *s, char c, char **split, size_t count)
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
			while (n--)
				free(split[n]);
			free(split);
			return (NULL);
		}
		n++;
	}
	return (split);
}
