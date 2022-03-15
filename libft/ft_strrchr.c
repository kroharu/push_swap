/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladrian <ladrian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 13:44:54 by ladrian           #+#    #+#             */
/*   Updated: 2022/03/04 23:58:13 by ladrian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlen(char *s);

char	*ft_strrchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	str += ft_strlen(str) + 1;
	while (str-- != s)
		if ((unsigned char)*str == (unsigned char) c)
			return (str);
	return (NULL);
}
