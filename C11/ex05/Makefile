# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: onikolai <onikolai@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/18 16:07:11 by onikolai          #+#    #+#              #
#    Updated: 2024/09/18 16:07:16 by onikolai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			= signs.c do_op.c main.c ft_atoi.c ft_putchar.c ft_putnbr.c ft_putstr.c

SRCS		= ${addprefix ${PRE}, ${SRC}}

OBJS		= ${SRCS:.c=.o}

PRE			= ./srcs/

HEAD		= ./includes/

NAME		= do-op

RM			= rm -f

GCC			= cc

CFLAGS		= -Wall -Wextra -Werror

all:		${NAME}

.c.o:
			${GCC} ${CFLAGS} -c -I ${HEAD} $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			$(CC) $(OBJS) -o $(NAME)

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
