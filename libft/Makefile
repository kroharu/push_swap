# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ladrian <ladrian@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/16 10:57:09 by ladrian           #+#    #+#              #
#    Updated: 2022/03/05 00:00:05 by ladrian          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libft.a

INCLUDES = ${NAME:.a=.h} ft_printf.h

SRCS =	ft_atoi.c		ft_isdigit.c	ft_memmove.c	ft_split.c		ft_strlcpy.c	\
		ft_strtrim.c	ft_bzero.c		ft_isprint.c	ft_memset.c		ft_strchr.c		\
		ft_strlen.c		ft_substr.c		ft_calloc.c		ft_itoa.c		ft_putchar_fd.c	\
		ft_strdup.c		ft_strmapi.c	ft_tolower.c	ft_isalnum.c	ft_memchr.c		\
		ft_putendl_fd.c	ft_striteri.c	ft_strncmp.c	ft_toupper.c	ft_isalpha.c	\
		ft_memcmp.c		ft_putnbr_fd.c	ft_strjoin.c	ft_strnstr.c	ft_isascii.c	\
		ft_memcpy.c		ft_putstr_fd.c	ft_strlcat.c	ft_strrchr.c		\
		ft_lstadd_back_bonus.c   ft_lstdelone_bonus.c  ft_lstmap_bonus.c	\
		ft_lstadd_front_bonus.c  ft_lstiter_bonus.c    ft_lstnew_bonus.c	\
		ft_lstclear_bonus.c      ft_lstlast_bonus.c    ft_lstsize_bonus.c	\
		ft_printf.c		ft_printf2.c	ft_printf3.c

OBJS	=	${SRCS:.c=.o}

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
AR		= ar rcs
RM		= rm -f

${NAME}:	${OBJS}
			${AR} ${NAME} $?

%.o:		%.c ${INCLUDES} Makefile
			${CC} ${CFLAGS} -c $< -o $@

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
