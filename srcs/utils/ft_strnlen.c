/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 22:40:54 by stanaka           #+#    #+#             */
/*   Updated: 2021/12/04 22:40:55 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strnlen(char *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s[i])
		i++;
	return (i);
}
