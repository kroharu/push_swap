/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladrian <ladrian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 17:08:52 by ladrian           #+#    #+#             */
/*   Updated: 2022/03/11 14:23:52 by ladrian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_solve_pos(t_dlist *a)
{
	int		i;
	t_dlist	*min;
	t_dlist	*start;

	i = -1;
	start = a;
	while (a)
	{
		if (i == -1)
			a->pos = -1;
		else if (a->pos == -1 && (min == NULL || a->num < min->num))
			min = a;
		a = a->next;
		if (a == start)
		{
			if (i == -1)
				i++;
			else if (min == NULL)
				a = NULL;
			else
				min->pos = i++;
			min = NULL;
		}
	}
}

int	main(int argc, char **argv)
{
	t_dlist	*array;
	t_dlist	*a;
	t_dlist	*b;
	t_list	*res;

	res = NULL;
	if (argc >= 2 && !ft_strcmp(argv[1], "-v"))
	{
		argc--;
		argv = &argv[1];
		ft_lstadd_back(&res, ft_lstnew(ft_strdup("-v")));
	}
	array = NULL;
	if (argc > 1)
		array = ft_read_args(argc - 1, &argv[1]);
	if (array)
	{
		a = &array[0];
		b = NULL;
		ft_solve_pos(a);
		ft_solve(&a, &b, &res, argc - 1);
		free(array);
	}
	ft_lstclear(&res, &free);
	return (array == NULL);
}
