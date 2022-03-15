/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladrian <ladrian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 17:08:52 by ladrian           #+#    #+#             */
/*   Updated: 2022/03/04 23:50:32 by ladrian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isspace(unsigned char c)
{
	if (('\t' <= c && c <= '\r') || c == ' ')
		return (1);
	return (0);
}

static int	ft_isnumber(char *str)
{
	int	n;

	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
		str++;
	n = 0;
	while (ft_isdigit(*str))
	{	
		n = 1;
		str++;
	}
	while (ft_isspace(*str))
		str++;
	if (*str == '\0' && n != 0)
		return (1);
	return (0);
}

static long	ft_atol(const char *str)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -1;
	while (ft_isdigit(*str))
		res = res * 10 + *str++ - '0';
	return (res * sign);
}

static int	ft_str_to_int(char	*str, t_dlist	*array, int i)
{
	long	temp;
	int		k;

	if (!ft_isnumber(str))
		return (1);
	temp = ft_atol(str);
	if (temp > (int) 0x7fffffff || temp < (int) 0x80000000)
		return (1);
	array[i].num = (int) temp;
	k = 0;
	while (k < i)
		if (array[k++].num == array[i].num)
			return (1);
	return (0);
}

t_dlist	*ft_read_args(int count, char **argv)
{
	int		i;
	t_dlist	*array;

	array = malloc(count * sizeof(*array));
	if (array == NULL)
		return (NULL);
	i = -1;
	while (++i < count)
	{
		if (ft_str_to_int(argv[i], array, i) != 0)
		{
			ft_putendl_fd("Error", 2);
			free(array);
			return (NULL);
		}
		if (i == count - 1)
			array[i].next = &array[0];
		else
			array[i].next = &array[i + 1];
		if (i == 0)
			array[i].prev = &array[count - 1];
		else
			array[i].prev = &array[i - 1];
	}
	return (array);
}
