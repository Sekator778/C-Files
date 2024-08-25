CC = gcc
CFLAGS = -Wall -Wextra -Werror -I../lib
LIB_DIR = ../lib
SRC_DIR = .

SRCS = $(SRC_DIR)/main.c $(LIB_DIR)/ft_putchar.c
OBJS = $(SRCS:.c=.o)
TARGET = main

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
