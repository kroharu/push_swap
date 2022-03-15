/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladrian <ladrian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:35:30 by ladrian           #+#    #+#             */
/*   Updated: 2022/03/04 23:58:26 by ladrian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(char const *s);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;

	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		(start = ft_strlen(s));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	res = malloc(len + 1);
	if (res == NULL)
		return (NULL);
	i = 0;
	s += start;
	while (i < len && s[i])
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
