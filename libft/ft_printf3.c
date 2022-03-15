/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladrian <ladrian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 10:47:05 by ladrian           #+#    #+#             */
/*   Updated: 2022/03/04 23:55:42 by ladrian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_join_free(char *s1, char *s2)
{
	char	*res;

	res = ft_strjoin(s1, s2);
	if (!res)
		return (NULL);
	free(s1);
	free(s2);
	return (res);
}

char	*ft_strset(char symbol, int count)
{
	char	*res;

	if (count < 0)
		count = 0;
	res = malloc(count + 1);
	if (!res)
		return (NULL);
	ft_memset(res, symbol, count);
	res[count] = '\0';
	return (res);
}

void	ft_upstr(char *str)
{
	while (*str)
	{
		*str = ft_toupper(*str);
		str++;
	}
}
