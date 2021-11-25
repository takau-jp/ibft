/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook_air <macbook_air@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:47:18 by macbook_air       #+#    #+#             */
/*   Updated: 2021/11/26 05:53:56 by macbook_air      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	len;

	if (s == NULL)
		return ;
	len = ft_strlen(s);
	while (len >= INT_MAX)
	{
		write(fd, s, INT_MAX);
		len -= INT_MAX;
		s += INT_MAX;
	}
	if (len > 0)
		write(fd, s, len);
}
