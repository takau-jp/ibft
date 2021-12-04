/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 09:54:20 by macbook_air       #+#    #+#             */
/*   Updated: 2021/12/05 01:05:47 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *buf, int ch, size_t n)
{
	unsigned char	*tmp;

	tmp = (unsigned char *)buf;
	while (n--)
		*tmp++ = (unsigned char)ch;
	return (buf);
}
