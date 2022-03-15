/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladrian <ladrian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 12:07:48 by ladrian           #+#    #+#             */
/*   Updated: 2022/03/04 23:56:32 by ladrian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char			*dest;
	unsigned int	i;
	unsigned int	j;

	if (!src)
		return (NULL);
	i = 0;
	while (src[i])
		i++;
	dest = malloc(++i);
	if (dest == NULL)
		return (NULL);
	j = 0;
	while (j < i)
	{
		dest[j] = src[j];
		j++;
	}
	return (dest);
}
