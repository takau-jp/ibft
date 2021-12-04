/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 20:13:26 by macbook_air       #+#    #+#             */
/*   Updated: 2021/12/04 23:21:53 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
