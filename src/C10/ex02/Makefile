NAME = ft_tail
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): ft_tail.o
	$(CC) $(CFLAGS) -o $(NAME) ft_tail.o

ft_tail.o: ft_tail.c
	$(CC) $(CFLAGS) -c ft_tail.c

clean:
	rm -f ft_tail.o

fclean: clean
	rm -f $(NAME)

re: fclean all
