/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladrian <ladrian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 17:08:52 by ladrian           #+#    #+#             */
/*   Updated: 2022/03/11 14:23:19 by ladrian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_get_next_line(char *str)
{
	int	i;

	i = 0;
	while (i < 4 && read(0, &str[i], 1))
		if (str[i++] == '\n')
			break ;
	str[i] = '\0';
	return (i);
}

static int	ft_make_commands(t_dlist **a, t_dlist **b)
{
	char	*str;

	str = malloc(5);
	while (ft_get_next_line(str))
	{
		if (st_do_command(a, b, str))
		{
			ft_putendl_fd("Error", 2);
			free(str);
			return (2);
		}
	}
	free(str);
	return (0);
}

int	main(int argc, char **argv)
{
	t_dlist	*array;
	t_dlist	*a;
	t_dlist	*b;
	int		res;

	if (argc == 1)
		return (3);
	array = ft_read_args(argc - 1, &argv[1]);
	if (!array)
		return (2);
	a = &array[0];
	b = NULL;
	res = ft_make_commands(&a, &b);
	if (res == 0)
		res = st_check_stacks(a, b);
	free(array);
	return (res);
}
