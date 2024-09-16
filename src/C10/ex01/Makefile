NAME = ft_cat
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): ft_cat.o
	$(CC) $(CFLAGS) -o $(NAME) ft_cat.o

ft_cat.o: ft_cat.c
	$(CC) $(CFLAGS) -c ft_cat.c

clean:
	rm -f ft_cat.o

fclean: clean
	rm -f $(NAME)

re: fclean all
