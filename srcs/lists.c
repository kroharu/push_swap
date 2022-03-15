/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladrian <ladrian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 17:08:52 by ladrian           #+#    #+#             */
/*   Updated: 2022/03/04 23:50:29 by ladrian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_putstr(void *content)
{
	ft_putstr_fd((char *) content, 1);
}

static int	ft_replace21(t_list **res, char *s1, char *s2, char *sr)
{
	t_list	**i;
	t_list	*next;
	int		ret;

	ret = 0;
	i = res;
	while (*i && (*i)->next)
	{
		next = (*i)->next;
		if ((!ft_strcmp((*i)->content, s1) && !ft_strcmp(next->content, s2))
			|| (!ft_strcmp((*i)->content, s2) && !ft_strcmp(next->content, s1)))
		{
			free((*i)->content);
			(*i)->content = ft_strdup(sr);
			(*i)->next = next->next;
			ft_lstdelone(next, &free);
			ret++;
		}
		else
			i = &((*i)->next);
	}
	return (ret);
}

static int	ft_delete2(t_list **res, char *s1, char *s2)
{
	t_list	**i;
	t_list	*next;
	int		ret;

	ret = 0;
	i = res;
	while (*i && (*i)->next)
	{
		next = (*i)->next;
		if ((!ft_strcmp((*i)->content, s1) && !ft_strcmp(next->content, s2))
			|| (!ft_strcmp((*i)->content, s2) && !ft_strcmp(next->content, s1)))
		{
			ft_lstdelone(*i, &free);
			*i = next->next;
			ft_lstdelone(next, &free);
			ret++;
		}
		else
			i = &((*i)->next);
	}
	return (ret);
}

static void	ft_clean_commands(t_list **res)
{
	int	i;

	i = 1;
	while (i)
	{
		i = ft_delete2(res, "pa\n", "pb\n");
		i += ft_delete2(res, "ra\n", "rra\n");
		i += ft_delete2(res, "rb\n", "rrb\n");
		i += ft_delete2(res, "sa\n", "sa\n");
		i += ft_delete2(res, "sb\n", "sb\n");
		i += ft_delete2(res, "ss\n", "ss\n");
		i += ft_delete2(res, "rr\n", "rr\n");
		i += ft_delete2(res, "rrr\n", "rrr\n");
		i += ft_replace21(res, "sa\n", "sb\n", "ss\n");
		i += ft_replace21(res, "ra\n", "rb\n", "rr\n");
		i += ft_replace21(res, "rra\n", "rrb\n", "rrr\n");
		i += ft_replace21(res, "ra\n", "rrr\n", "rrb\n");
		i += ft_replace21(res, "rb\n", "rrr\n", "rra\n");
		i += ft_replace21(res, "rra\n", "rr\n", "rb\n");
		i += ft_replace21(res, "rrb\n", "rr\n", "ra\n");
		i += ft_replace21(res, "sa\n", "ss\n", "sb\n");
		i += ft_replace21(res, "sb\n", "ss\n", "sa\n");
	}
}

void	ft_printlist(t_list **res)
{
	ft_clean_commands(res);
	ft_lstiter(*res, &ft_putstr);
}
