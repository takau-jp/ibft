/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook_air <macbook_air@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 20:13:29 by macbook_air       #+#    #+#             */
/*   Updated: 2021/11/20 20:36:21 by macbook_air      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, char const *src);

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tmp;

	if (!s1 || !s2)
		return (NULL);
	tmp = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!tmp)
		return (NULL);
	tmp[0] = '\0';
	ft_strcat(tmp, s1);
	ft_strcat(tmp, s2);
	return (tmp);
}

char	*ft_strcat(char *dest, char const *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i] != '\0')
		i ++;
	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i ++;
		j ++;
	}
	dest[i] = '\0';
	return (dest);
}
