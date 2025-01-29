NAME = libft.a

SRC_DIR = srcs
INC_DIR = includes

SRC = ft_putchar.c ft_putstr.c ft_strlen.c ft_swap.c ft_strcmp.c
SRC := $(addprefix $(SRC_DIR)/, $(SRC))

INC = ft.h
INC := $(addprefix $(INC_DIR)/, $(INC))

OBJ = $(SRC:.c=.o)

CC = gcc
CFLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)


$(OBJ): %.o: %.c $(INC)
	$(CC) $(CFLAG) -c $< -o $@


clean:
	rm -f $(OBJ)


fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
