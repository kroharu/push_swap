/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladrian <ladrian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 14:05:02 by ladrian           #+#    #+#             */
/*   Updated: 2022/03/04 23:58:00 by ladrian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlen(const char *s);
int		ft_memcmp(const void *s1, const void *s2, size_t n);

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n > ft_strlen(s2) && ft_strlen(s2) != 0)
		n = ft_strlen(s2) + 1;
	return (ft_memcmp(s1, s2, n));
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{		
		s1++;
		s2++;
	}
	return ((unsigned char) *s1 - (unsigned char) *s2);
}
