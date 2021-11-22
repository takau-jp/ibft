/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook_air <macbook_air@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 19:07:37 by macbook_air       #+#    #+#             */
/*   Updated: 2021/11/20 20:08:49 by macbook_air      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**mem_alloc(char const *s, char c);
size_t	count_split(char const *s, char c);
int		split_malloc(char const *s, char c, char **split, size_t count);
void	split_cpy(char const *s, char c, char **split);

char	**ft_split(char const *s, char c)
{
	char	**split;

	if (!s)
		return (NULL);
	split = mem_alloc(s, c);
	if (!split)
		return (NULL);
	if (*s == '\0')
	{
		split[0] = 0;
		return (split);
	}
	split_cpy(s, c, split);
	return (split);
}

char	**mem_alloc(char const *s, char c)
{
	char	**split;
	size_t	count;

	count = count_split(s, c);
	split = (char **)malloc(sizeof(char *) * (count + 1));
	if (!split)
	{
		free(split);
		return (NULL);
	}
	if (!split_malloc(s, c, split, count))
		return (NULL);
	split[count] = 0;
	return (split);
}

size_t	count_split(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (i == 0 && s[i] != c)
			count ++;
		else if (s[i] == c && i == 0)
			;
		else if (s[i - 1] == c && s[i] != c)
			count ++;
		i ++;
	}
	return (count);
}

int	split_malloc(char const *s, char c, char **split, size_t count)
{
	size_t	n;
	size_t	len;

	n = 0;
	while (n < count)
	{
		len = 0;
		if (*s ++ != c)
			len ++;
		while (len > 0 && *s != '\0')
		{
			if (*s ++ != c)
				len ++;
		}
		split[n] = (char *)malloc(sizeof(char) * (len + 1));
		if (!split[n])
		{
			while (n -- > 0)
				free(split[n]);
			free(split);
			return (0);
		}
		n ++;
	}
	return (1);
}

void	split_cpy(char const *s, char c, char **split)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (*s != c)
		split[i][j ++] = *s;
	s ++;
	while (*s)
	{
		if (*s != c)
			split[i][j ++] = *s;
		else if (s[-1] != c && *s == c)
		{
			split[i][j] = '\0';
			j = 0;
			i ++;
		}
		s ++;
	}
}
