NAME = ft_display_file
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): ft_display_file.o
	$(CC) $(CFLAGS) -o $(NAME) ft_display_file.o

ft_display_file.o: ft_display_file.c
	$(CC) $(CFLAGS) -c ft_display_file.c

clean:
	rm -f ft_display_file.o

fclean: clean
	rm -f $(NAME)

re: fclean all
