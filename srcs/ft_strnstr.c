/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 09:54:39 by macbook_air       #+#    #+#             */
/*   Updated: 2021/12/04 20:12:47 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	n_len;

	if (!*needle)
		return ((char *)haystack);
	if (!len)
		return (NULL);
	i = 0;
	n_len = ft_strlen(needle);
	while (haystack[i] && i + n_len <= len)
	{
		if (!ft_strncmp(haystack + i, needle, n_len))
			return ((char *)haystack + i);
		i ++;
	}
	return (NULL);
}
