# Variables
NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS_DIR = srcs
INCLUDES_DIR = includes
OBJS_DIR = $(SRCS_DIR)

SRCS = ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
OBJS = $(SRCS:.c=.o)

SRCS_WITH_PATH = $(addprefix $(SRCS_DIR)/, $(SRCS))
OBJS_WITH_PATH = $(addprefix $(OBJS_DIR)/, $(OBJS))

# Default target
all: $(NAME)

# Build the library
$(NAME): $(OBJS_WITH_PATH)
	@echo "Creating library $(NAME)..."
	ar rc $(NAME) $(OBJS_WITH_PATH)
	ranlib $(NAME)

# Compile source files into object files
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(INCLUDES_DIR)/ft.h
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) -c $< -o $@

# Remove object files
clean:
	@echo "Cleaning object files..."
	rm -f $(OBJS_WITH_PATH)

# Remove object files and the library
fclean: clean
	@echo "Cleaning library $(NAME)..."
	rm -f $(NAME)

# Rebuild everything
re: fclean all

# Phony targets to prevent conflicts with file names
.PHONY: all clean fclean re
