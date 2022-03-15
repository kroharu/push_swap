# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ladrian <ladrian@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/04 20:59:11 by ladrian           #+#    #+#              #
#    Updated: 2022/03/05 20:19:01 by ladrian          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
S_DIR	=	srcs
HEADER	=	$(S_DIR)/push_swap.h
SRCS_ML =	push_swap.c read_args.c stack.c stack2.c lists.c solve.c solve2.c solve3.c

NAME_B	=	checker
HEADER_B=	$(S_DIR)/push_swap.h
SRCS_BL =	checker.c read_args.c stack.c stack2.c

LIB		=	libft.a
LIB_DIR	=	libft
DLIB	=	$(LIB_DIR)/$(LIB)

SRCS	=	$(patsubst %, $(S_DIR)/%, $(SRCS_ML))
SRCS_B	=	$(patsubst %, $(S_DIR)/%, $(SRCS_BL))
OBJS	=	${SRCS:.c=.o}
OBJS_B	=	${SRCS_B:.c=.o}

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
AR		= ar rcs
RM		= rm -f

.PHONY:		all clean fclean re bonus

all:		${NAME}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} $^ -o $@ -lft -L${LIB_DIR}

%.o:		%.c ${HEADER} ${DLIB} Makefile
			${CC} ${CFLAGS} -c $< -o $@

${DLIB}:	$(LIB_DIR)/*.h $(LIB_DIR)/*.c $(LIB_DIR)/Makefile
			make -C $(LIB_DIR)

clean:
			make $@ -C $(LIB_DIR)
			${RM} ${OBJS} ${OBJS_B}

fclean:		clean
			make $@ -C $(LIB_DIR)
			${RM} ${NAME} ${NAME_B}

re:			fclean all

bonus:		${NAME_B}

${NAME_B}:	${OBJS_B}
			${CC} ${CFLAGS} $^ -o $@ -lft -L${LIB_DIR}
