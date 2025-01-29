CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_cat.c
OBJ = $(SRC:.c=.o)
NAME = ft_cat

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
