NAME = rush-02
CC = gcc
CCFLAGS = -Wall -Wextra -Werror -I includes -g3


SCRS = srcs/main.c srcs/ft_utils.c srcs/parse_dictionary.c srcs/verification_dictionary.c srcs/ft_utils_convert.c \
       srcs/ft_keys_ring.c srcs/ft_struct_dict.c srcs/ft_print_list.c srcs/ft_parse_input.c srcs/ft_utils_input.c \
       srcs/ft_utils_parse.c srcs/ft_start_prog.c
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

