NAME = bsq

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I includes

SRCS = srcs/main.c srcs/utils.c srcs/reader.c srcs/parser.c srcs/solve.c srcs/output.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

