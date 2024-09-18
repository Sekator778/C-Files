DIR	= ./srcs/

SRC	= signs.c do_op.c main.c ft_atoi.c ft_putchar.c ft_putnbr.c ft_putstr.c

SRCS	= ${addprefix ${DIR}, ${SRC}}

HEAD	= ./includes/

OBJS	= ${SRCS:.c=.o}

CC	= gcc

FLAGS	= -Werror -Wextra -Wall

NAME	= do-op

RM	= rm -f

# Rule to compile .c files to .o files
%.o: %.c
	${CC} ${FLAGS} -I ${HEAD} -c $< -o $@

# Rule to link object files into the final executable
${NAME}: ${OBJS}
	$(CC) $(OBJS) -o $(NAME)

all:	${NAME}

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re:	fclean all

.PHONY: all clean fclean re