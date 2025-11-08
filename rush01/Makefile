NAME = rush-01
CC = cc
CCFLAGS = -Wall -Wextra -Werror -I includes


SCRS = srcs/creat_base_tab.c srcs/ft_rev_int_tab.c srcs/safe_col_start.c srcs/seed_tab.c \
       srcs/true_char.c srcs/chang_board.c srcs/creat_board.c srcs/main.c srcs/safe_row_end.c \
       srcs/size_tab_argv.c srcs/ft_putchar.c srcs/print_board_resolv.c srcs/safe_row_start.c \
       srcs/tab_cpy.c srcs/cpy_board_data.c srcs/safe_col_end.c srcs/safe_up.c \
       srcs/tab_facto.c srcs/ft_recursive_factorial.c srcs/safe_cols_partial.c

OBJS = ${SCRS:.c=.o}

.c.o:
	${CC} ${CCFLAGS} -c $< -o $@

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${CCFLAGS}  -o ${NAME} ${OBJS}


clean:
	rm -f ${OBJS}


fclean: clean
	rm -f ${NAME}


re: fclean all

.PHONY: all clean fclean re

