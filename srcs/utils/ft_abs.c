/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 22:40:38 by stanaka           #+#    #+#             */
/*   Updated: 2021/12/04 22:40:39 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_abs(int i)
{
	unsigned int	u;

	u = i;
	if (i < 0)
		u = ~i + 1;
	return (u);
}
