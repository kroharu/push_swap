/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladrian <ladrian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 17:08:52 by ladrian           #+#    #+#             */
/*   Updated: 2022/03/04 23:50:37 by ladrian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	st_rotate(t_dlist **stack, int direction)
{
	if (*stack == NULL)
		return ;
	if (direction == 1)
		*stack = (*stack)->next;
	else
		*stack = (*stack)->prev;
}

void	st_rotate_both(t_dlist **stack1, t_dlist **stack2, int direction)
{
	st_rotate(stack1, direction);
	st_rotate(stack2, direction);
}

void	st_swap_both(t_dlist **stack1, t_dlist **stack2)
{
	st_swap(stack1);
	st_swap(stack2);
}

void	st_swap(t_dlist **stack)
{
	t_dlist	*beforefirst;
	t_dlist	*first;
	t_dlist	*second;
	t_dlist	*aftersecond;

	if (*stack == NULL)
		return ;
	first = *stack;
	beforefirst = first->prev;
	second = first->next;
	aftersecond = second->next;
	if (first != aftersecond)
	{
		first->next = aftersecond;
		second->next = first;
		beforefirst->next = second;
		second->prev = beforefirst;
		first->prev = second;
		aftersecond->prev = first;
	}
	*stack = second;
}

void	st_push(t_dlist **stack1, t_dlist **stack2)
{
	t_dlist	*move;

	if (*stack1 == NULL)
		return ;
	move = *stack1;
	(move->prev)->next = move->next;
	(move->next)->prev = move->prev;
	if (move != move->next)
		*stack1 = move->next;
	else
		*stack1 = NULL;
	if (*stack2 != NULL)
	{
		move->next = *stack2;
		move->prev = (*stack2)->prev;
		(move->prev)->next = move;
		(move->next)->prev = move;
	}
	else
	{
		move->next = move;
		move->prev = move;
	}
	*stack2 = move;
}
