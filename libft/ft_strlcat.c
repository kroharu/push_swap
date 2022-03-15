/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladrian <ladrian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 12:09:01 by ladrian           #+#    #+#             */
/*   Updated: 2022/03/04 23:57:04 by ladrian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcpy(char *dst, char *src, size_t size);
size_t	ft_strlen(const char *s);

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	size_t	len;

	len = ft_strlen(dst);
	if (size > len)
		return (len + ft_strlcpy(dst + len, src, size - len));
	return (size + ft_strlen(src));
}
