/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladrian <ladrian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 14:57:55 by ladrian           #+#    #+#             */
/*   Updated: 2022/03/05 00:00:50 by ladrian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_bottom_renum2(t_dlist *roll)
{
	while (roll->shift < 0)
	{
		roll->shift = 1;
		roll = roll->prev;
	}
	while (roll->shift > 0)
	{
		roll->shift = -2;
		roll = roll->prev;
	}
	ft_bottom_renum(roll);
}

static void	ft_opt2_part3(t_dlist **a, t_dlist **b, t_list **res, int *hb)
{
	st_rec_command(a, b, res, "ra\n");
	(*hb)++;
}

static int	ft_opt2_part1(t_dlist **a, t_dlist **b, t_list **res, int *hb)
{
	int	shift;
	int	i;
	int	apos;
	int	half;

	half = 0;
	shift = ft_abs((*b)->shift);
	apos = (*a)->pos;
	i = 1;
	while (i)
	{
		if (ft_abs((*b)->shift) == 1)
			i = 0;
		if ((*b)->pos >= apos - shift / 2)
		{
			st_rec_command(a, b, res, "pa\n");
			half++;
			if ((*a)->pos < apos - shift / 4)
				ft_opt2_part3(a, b, res, hb);
		}
		else if (i || (*b)->prev->shift > 0)
			st_rec_command(a, b, res, "rb\n");
	}
	return (half);
}

static void	ft_opt2_part2(t_dlist **a, t_dlist **b, t_list **res, int *hb)
{
	int	i;

	i = 1;
	while ((*b)->prev->shift > 0)
	{
		(*b)->prev->shift = i++;
		st_rec_command(a, b, res, "rrb\n");
	}
	if ((*b)->shift < 0)
		ft_bottom_renum2((*b)->prev);
	while (*hb)
	{
		st_rec_command(a, b, res, "rra\n");
		(*hb)--;
	}
}

int	ft_opt2(t_dlist **a, t_dlist **b, t_list **res)
{
	int	half;
	int	halfbottom;

	halfbottom = 0;
	half = ft_opt2_part1(a, b, res, &halfbottom);
	ft_opt2_part2(a, b, res, &halfbottom);
	return (half);
}
