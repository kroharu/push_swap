/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladrian <ladrian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 17:08:52 by ladrian           #+#    #+#             */
/*   Updated: 2022/03/04 23:50:33 by ladrian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_make_roll(t_dlist **a, t_dlist **b, t_list **res, int rotpos)
{
	char	*cmd;

	cmd = "rra\n";
	if (rotpos > 0)
		cmd = "ra\n";
	while (rotpos)
	{
		st_rec_command(a, b, res, cmd);
		if (rotpos > 0)
			rotpos--;
		else
			rotpos++;
	}
}

static int	ft_roll(t_dlist **a, t_dlist **b, t_list **res, int half)
{
	t_dlist	*rollpos;
	t_dlist	*rollneg;
	int		rotpos;
	int		rotneg;

	rollpos = (*a);
	rotpos = 0;
	while (rollpos->pos >= half)
	{
		rotpos++;
		rollpos = rollpos->next;
		if (rollpos == *a)
			return (0);
	}
	rollneg = (*a)->prev;
	rotneg = 0;
	while (++rotneg && rollpos != rollneg)
		rollneg = rollneg->prev;
	if (rotneg < rotpos)
		rotpos = -rotneg;
	ft_make_roll(a, b, res, rotpos);
	return (1);
}

static int	ft_middle(t_dlist *a, int count)
{
	int	i;
	int	sum;
	int	mid;

	i = 0;
	sum = 0;
	while (i < count)
	{
		sum += a->pos;
		a = a->next;
		i++;
	}
	mid = sum / count;
	if (sum % count)
		mid++;
	return (mid);
}

static void	ft_push_half(t_dlist **a, t_dlist **b, t_list	**res, int *count)
{
	static int	first = 1;
	int			mid;
	int			div;
	int			i;

	div = *count / 2;
	mid = ft_middle(*a, *count);
	while (*count > 2)
	{
		i = 1;
		while (ft_roll(a, b, res, mid))
		{
			if (first && (*a)->pos < div / 2)
				(*a)->shift = -2;
			else
				(*a)->shift = i++;
			st_rec_command(a, b, res, "pb\n");
			*count -= 1;
			if ((*b)->shift < 0 && (*b)->next->shift >= 0)
				st_rec_command(a, b, res, "rb\n");
		}
		mid += *count / 2;
		if (first--)
			ft_bottom_renum((*b)->prev);
	}
}

void	ft_solve(t_dlist **a, t_dlist **b, t_list **res, int count)
{
	int		m;

	m = count;
	while (m)
	{
		if (count > 3)
		{
			ft_push_half(a, b, res, &m);
			while ((*a)->prev->pos != count - 1)
				st_rec_command(a, b, res, "rra\n");
		}
		if (count == 3 && (*a)->pos != 1)
			st_rec_command(a, b, res, "ra\n");
		if ((*a)->pos > (*a)->next->pos)
			st_rec_command(a, b, res, "sa\n");
		m = ft_moveback(a, b, res);
	}
	ft_roll(a, b, res, 1);
	if (*res && !ft_strcmp((*res)->content, "-v"))
		st_check_stacks(*a, *b);
	else
		ft_printlist(res);
}
