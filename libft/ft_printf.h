/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladrian <ladrian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 11:04:19 by ladrian           #+#    #+#             */
/*   Updated: 2022/03/04 23:55:11 by ladrian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_flag
{
	char	sharp;
	char	zero;
	char	minus;
	char	space;
	char	plus;
	char	dot;
	size_t	width;
	size_t	prec;
}	t_flag;

int		ft_printf(const char *args, ...);
int		ft_printf_n(char *str, char symbol, t_flag *flag);
int		ft_printf_s(char *str, char symbol, t_flag *flag);
int		ft_printf_c(char c, t_flag *flag);
char	*ft_join_free(char *s1, char *s2);
char	*ft_strset(char symbol, int count);
void	ft_upstr(char *str);

#endif
