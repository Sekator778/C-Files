DIRSRC		= ./srcs/

SRC		= main.c utils.c

SRCS		= ${addprefix ${DIRSRC}, ${SRC}}

HEAD		= ./includes/

OBJS		= ${SRCS:.c=.o}

NAME		= ft_hexdump

CC			= gcc
RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c -I ${HEAD} $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			gcc -o ${NAME} ${OBJS} ${CFLAGS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
