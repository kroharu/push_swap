/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladrian <ladrian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 14:35:33 by ladrian           #+#    #+#             */
/*   Updated: 2022/03/04 23:54:36 by ladrian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	int		cmp;

	i = 0;
	while (i < n)
	{		
		cmp = ((unsigned char *)s1)[i] - ((unsigned char *)s2)[i];
		if (cmp != 0)
			return (cmp);
		i++;
	}
	return (0);
}
