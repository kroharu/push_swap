/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladrian <ladrian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 10:44:18 by ladrian           #+#    #+#             */
/*   Updated: 2022/03/04 23:55:04 by ladrian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_to_hex(size_t p)
{
	int		i;
	char	c[17];

	c[16] = '\0';
	i = 16;
	while (i == 16 || p > 0)
	{
		c[--i] = p % 16 + '0';
		if (c[i] > '9')
			c[i] += 'a' - '0' - 10;
		p /= 16;
	}
	return (ft_strdup(&c[i]));
}

static int	ft_read_var(const char symbol, va_list *ap, t_flag *flag)
{
	int	res;

	if (flag->width > 0x7fffffff || flag->prec > 0x7fffffff)
		return (-1);
	if (symbol == 'd' || symbol == 'i')
		res = ft_printf_n(ft_itoa(va_arg(*ap, int)), symbol, flag);
	else if (symbol == 'u')
		res = ft_printf_n(ft_itoa(va_arg(*ap, unsigned int)), symbol, flag);
	else if (symbol == 's')
		res = ft_printf_s(ft_strdup(va_arg(*ap, char *)), symbol, flag);
	else if (symbol == 'c')
		res = ft_printf_c((char) va_arg(*ap, int), flag);
	else if (symbol == '%')
		res = write(1, &symbol, 1);
	else if (symbol == 'x' || symbol == 'X')
		res = ft_printf_n(ft_to_hex(va_arg(*ap, unsigned int)), symbol, flag);
	else if (symbol == 'p')
		res = ft_printf_s(ft_to_hex(va_arg(*ap, size_t)), symbol, flag);
	else if (symbol == '\0')
		res = -1;
	else
		res = -2;
	return (res);
}

static void	ft_read_flags(t_flag *flag, const char **format, size_t *len)
{
	flag->minus = 0;
	flag->plus = 0;
	flag->sharp = 0;
	flag->space = 0;
	flag->zero = 0;
	flag->dot = 0;
	while ((*format)[*len])
	{
		if ((*format)[*len] == '+')
			flag->plus = 1;
		else if ((*format)[*len] == '-')
			flag->minus = 1;
		else if ((*format)[*len] == '#')
			flag->sharp = 1;
		else if ((*format)[*len] == ' ')
			flag->space = 1;
		else if ((*format)[*len] == '0')
			flag->zero = 1;
		else
			break ;
		(*len)++;
	}
	return ;
}

static int	ft_read_format(const char **format, va_list *ap)
{
	t_flag	flag;
	size_t	len;
	int		res;

	len = 1;
	ft_read_flags(&flag, format, &len);
	flag.width = ft_atoi(*format + len);
	while ((*format)[len] && ft_isdigit((*format)[len]))
		len++;
	if ((*format)[len] == '.')
		flag.dot = (*format)[len++];
	flag.prec = ft_atoi(*format + len);
	while ((*format)[len] && ft_isdigit((*format)[len]))
		len++;
	res = ft_read_var((*format)[len], ap, &flag);
	if (res == -2)
		res = write(1, *format, len);
	else if (res != -1)
		*format += 1;
	*format += len;
	return (res);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	size_t	len;
	int		res;

	i = 0;
	va_start(ap, format);
	while (*format)
	{
		len = 0;
		while (format[len] && format[len] != '%')
			len++;
		i += write(1, format, len);
		format += len;
		if (*format == '%')
		{
			res = ft_read_format(&format, &ap);
			if (res < 0)
				return (res);
			i += res;
		}
	}
	va_end(ap);
	return (i);
}
