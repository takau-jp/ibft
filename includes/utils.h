/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka < stanaka@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 22:41:14 by stanaka           #+#    #+#             */
/*   Updated: 2021/12/04 22:45:43 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stddef.h>

unsigned int	ft_abs(int i);
unsigned long	ft_labs(long i);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strndup(char const *s1, size_t n);
size_t			ft_strnlen(char *s, size_t n);

#endif