/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladrian <ladrian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 17:08:52 by ladrian           #+#    #+#             */
/*   Updated: 2022/03/05 18:40:56 by ladrian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	st_do_command(t_dlist **a, t_dlist **b, char *str)
{
	if (!ft_strcmp(str, "sa\n"))
		st_swap(a);
	else if (!ft_strcmp(str, "sb\n"))
		st_swap(b);
	else if (!ft_strcmp(str, "ss\n"))
		st_swap_both(a, b);
	else if (!ft_strcmp(str, "pa\n"))
		st_push(b, a);
	else if (!ft_strcmp(str, "pb\n"))
		st_push(a, b);
	else if (!ft_strcmp(str, "ra\n"))
		st_rotate(a, 1);
	else if (!ft_strcmp(str, "rb\n"))
		st_rotate(b, 1);
	else if (!ft_strcmp(str, "rr\n"))
		st_rotate_both(a, b, 1);
	else if (!ft_strcmp(str, "rra\n"))
		st_rotate(a, -1);
	else if (!ft_strcmp(str, "rrb\n"))
		st_rotate(b, -1);
	else if (!ft_strcmp(str, "rrr\n"))
		st_rotate_both(a, b, -1);
	else
		return (2);
	return (0);
}

void	st_rec_command(t_dlist **a, t_dlist **b, t_list **res, char *cmd)
{
	ft_lstadd_back(res, ft_lstnew(ft_strdup(cmd)));
	(void) st_do_command(a, b, cmd);
}

int	st_check_stacks(t_dlist *a, t_dlist *b)
{
	t_dlist	*start;
	int		error;

	start = a;
	error = 0;
	if (a == NULL || b != NULL)
		error = 1;
	while (!error && a->next != start)
	{
		if (a->num > (a->next)->num)
			error = 1;
		a = a->next;
	}
	if (error)
		ft_putendl_fd("KO", 1);
	else
		ft_putendl_fd("OK", 1);
	return (error);
}
