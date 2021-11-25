/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook_air <macbook_air@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 20:13:26 by macbook_air       #+#    #+#             */
/*   Updated: 2021/11/26 06:20:54 by macbook_air      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	is_set(char c, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start])
	{
		if (!is_set(s1[start], set))
			break ;
		start++;
	}
	while (start < end)
	{
		if (!is_set(s1[end], set))
			break ;
		end--;
	}
	return (ft_substr(s1, start, (end - start + 1)));
}

static bool	is_set(char c, char const *set)
{
	while (*set != '\0')
	{
		if (c == *set)
			return (true);
		set++;
	}
	return (false);
}
