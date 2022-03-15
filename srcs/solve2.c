/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladrian <ladrian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 17:08:52 by ladrian           #+#    #+#             */
/*   Updated: 2022/03/04 23:50:34 by ladrian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_opt(t_dlist **a, t_dlist **b, t_list	**res)
{
	if ((*b)->next != *b && (*a)->pos > (*b)->next->pos && (*b)->shift != 1
		&& ((*a)->prev->pos < (*b)->next->pos || (*a)->pos < (*a)->prev->pos))
	{
		st_rec_command(a, b, res, "pa\n");
		st_rec_command(a, b, res, "pa\n");
		if ((*a)->pos > (*a)->next->pos)
			st_rec_command(a, b, res, "sa\n");
	}
	else
		st_rec_command(a, b, res, "pa\n");
}

static void	ft_opt3(t_dlist **a, t_dlist **b, t_list **res)
{
	if ((*b)->next != (*b) && ((*b)->next->pos == (*a)->pos - 1
			|| (*b)->next->pos == (*a)->prev->pos + 1))
	{
		st_rec_command(a, b, res, "sb\n");
		st_rec_command(a, b, res, "pa\n");
		if ((*a)->shift == 1)
			(*b)->shift = 1;
	}
}

int	ft_moveback(t_dlist **a, t_dlist **b, t_list **res)
{
	while (*b)
	{
		ft_opt3(a, b, res);
		if ((*a)->pos > (*b)->pos)
		{
			if ((*a)->pos < (*a)->prev->pos || (*a)->prev->pos < (*b)->pos)
			{
				if (ft_abs((*b)->shift) > 20)
					return (ft_opt2(a, b, res));
				else
					ft_opt(a, b, res);
			}
			else
				st_rec_command(a, b, res, "rra\n");
		}
		else
			st_rec_command(a, b, res, "ra\n");
	}
	return (0);
}

void	ft_bottom_renum(t_dlist *roll)
{
	int	i;

	i = -1;
	while (roll->shift < 0 && roll->shift != -1)
	{
		roll->shift = i--;
		roll = roll->prev;
	}
}

int	ft_abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}
