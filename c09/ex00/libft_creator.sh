gcc -Wall -Wextra -Werror -c ft_putchar.c ft_putstr.c ft_strlen.c ft_strcmp.c ft_swap.c

ar rcs libft.a ft_putchar.o ft_swap.o ft_strlen.o ft_putstr.o ft_strcmp.o

rm *.o
