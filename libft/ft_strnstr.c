/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladrian <ladrian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:07:23 by ladrian           #+#    #+#             */
/*   Updated: 2022/03/04 23:58:08 by ladrian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	if (little[0] == 0)
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		k = i;
		j = 0;
		while (big[k] == little[j])
		{
			k++;
			j++;
			if (little[j] == '\0')
				return ((char *)big + i);
			if (big[k] == '\0' || (k == len))
				return (NULL);
		}
		i++;
	}
	return (NULL);
}
