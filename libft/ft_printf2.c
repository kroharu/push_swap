/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladrian <ladrian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:50:30 by ladrian           #+#    #+#             */
/*   Updated: 2022/03/04 23:55:36 by ladrian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_write_and_free(char *str)
{
	int	res;

	res = write(1, str, ft_strlen(str));
	free (str);
	return (res);
}

int	ft_printf_s(char *str, char symbol, t_flag *flag)
{
	if (symbol == 's')
	{
		if (str == NULL)
			str = ft_strdup("(null)");
		if (flag->dot && ft_strlen(str) > flag->prec)
			str[flag->prec] = '\0';
	}
	if (symbol == 'p')
		str = ft_join_free(ft_strdup("0x"), str);
	if (symbol == 'X')
		ft_upstr(str);
	if (flag->minus)
		str = ft_join_free(str, ft_strset(' ', flag->width - ft_strlen(str)));
	else
		str = ft_join_free(ft_strset(' ', flag->width - ft_strlen(str)), str);
	return (ft_write_and_free(str));
}

static char	*ft_insert_nulls(char *s, int n)
{
	char	*res;
	size_t	i;
	size_t	j;
	size_t	len;

	len = ft_strlen(s);
	n -= len;
	if (n <= 0)
		return (s);
	res = malloc(len + n + 1);
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	if (s[i] == '-' || s[i] == '+' || s[i] == ' ')
		res[j++] = s[i++];
	while (n-- > 0)
		res[j++] = '0';
	while (s[i])
		res[j++] = s[i++];
	free(s);
	res[j] = '\0';
	return (res);
}

int	ft_printf_n(char *str, char symbol, t_flag *flag)
{
	char	ifx0;

	ifx0 = 0;
	if (flag->sharp && (symbol == 'X' || symbol == 'x') && *str != '0')
		ifx0 = 1;
	if (flag->dot && flag->prec == 0 && *str == '0')
		*str = '\0';
	if (flag->dot)
		str = ft_insert_nulls(str, flag->prec + (*str == '-'));
	if (symbol == 'd' || symbol == 'i')
	{
		if (flag->plus && *str != '-')
			str = ft_join_free(ft_strdup("+"), str);
		else if (flag->space && *str != '-')
			str = ft_join_free(ft_strdup(" "), str);
	}
	if (flag->zero && !flag->minus && !flag->dot)
		str = ft_insert_nulls(str, flag->width - ifx0 * 2);
	if (ifx0)
		str = ft_join_free(ft_strdup("0x"), str);
	return (ft_printf_s(str, symbol, flag));
}

int	ft_printf_c(char c, t_flag *flag)
{
	int		res;

	if (flag->minus)
		write(1, &c, 1);
	res = ft_write_and_free(ft_strset(' ', flag->width - 1));
	if (!flag->minus)
		write(1, &c, 1);
	return (res + 1);
}
