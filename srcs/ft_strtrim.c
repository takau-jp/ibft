/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook_air <macbook_air@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 20:13:26 by macbook_air       #+#    #+#             */
/*   Updated: 2021/11/29 20:00:29 by macbook_air      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	end;
	char	ascii[256];

	if (!s1)
		return (NULL);
	if (!*s1 || !set || !*set)
		return (ft_strdup(s1));
	ft_bzero(ascii, 256);
	while (*set)
		ascii[(unsigned char)*set++] = 1;
	while (*s1 && ascii[(unsigned char)*s1] == 1)
		s1++;
	if (!*s1)
		return (ft_strdup(""));
	end = ft_strlen(s1) - 1;
	while (ascii[(unsigned char)s1[end]] == 1)
		end--;
	return (ft_substr(s1, 0, end + 1));
}
