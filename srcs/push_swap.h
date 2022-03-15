/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladrian <ladrian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 17:08:52 by ladrian           #+#    #+#             */
/*   Updated: 2022/03/04 23:50:31 by ladrian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../libft/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_dlist
{
	int				num;
	int				pos;
	int				shift;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}	t_dlist;

t_dlist	*ft_read_args(int argc, char **argv);
void	st_swap(t_dlist **stack);
void	st_swap_both(t_dlist **stack1, t_dlist **stack2);
void	st_push(t_dlist **stack1, t_dlist **stack2);
void	st_rotate(t_dlist **stack, int direction);
void	st_rotate_both(t_dlist **stack1, t_dlist **stack2, int direction);
int		st_do_command(t_dlist **a, t_dlist **b, char	*str);
void	st_rec_command(t_dlist **a, t_dlist **b, t_list **res, char *cmd);
void	st_print_stacks(t_dlist *a, t_dlist *b, char *msg, int var);
int		st_check_stacks(t_dlist *a, t_dlist *b);
void	ft_solve(t_dlist **a, t_dlist **b, t_list **res, int count);
int		ft_moveback(t_dlist **a, t_dlist **b, t_list **res);
void	ft_printlist(t_list **res);
int		ft_opt2(t_dlist **a, t_dlist **b, t_list **res);
void	ft_bottom_renum(t_dlist *roll);
int		ft_abs(int num);

#endif
