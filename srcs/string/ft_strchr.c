/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 09:54:22 by macbook_air       #+#    #+#             */
/*   Updated: 2021/12/05 01:06:56 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>

char	*ft_strchr(const char *s, int c)
{
	while (true)
	{
		if (*s == (char)c)
			return ((char *)s);
		if (*s == '\0')
			return (NULL);
		s++;
	}
}
