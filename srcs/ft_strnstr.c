/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook_air <macbook_air@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 09:54:39 by macbook_air       #+#    #+#             */
/*   Updated: 2021/11/19 18:55:10 by macbook_air      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	match;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && len > i)
	{
		match = 0;
		while (haystack[i + match] && needle[match] && i + match < len)
		{
			if (haystack[i + match] == needle[match])
				match ++;
			else
				break ;
			if (needle[match] == '\0')
				return ((char *)&haystack[i]);
		}
		i ++;
	}
	return (NULL);
}
