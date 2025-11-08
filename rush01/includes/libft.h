#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

void	chang_board(int **board, int *tab, int size);
void	creat_base_tab(int *tab, int n);
int	**creat_board(char *src);
void	ft_putchar(char c);
void	ft_rev_int_tab(int *tab, int size);
void	print_board_resolv(int **board, int size);
int	*seed_tab(char *src);
int	size_tab_argv(char *src);
void	tab_cpy(int *tab_d, int *tab_s, int n);
int	**tab_facto(int n);
int	true_char(char c);
void	cpy_board_data(int **board, int *data, int size, int row);
int	safe_row_start(int **board, int *data, int size);
int	safe_row_end(int **board, int *data, int size);
int	safe_col_start(int **board, int *data, int size, int row);
int	safe_col_end(int **board, int *data, int size, int row);
int	safe_up(int **board, int *data, int size, int row);
int	safe_cols_partial(int **board, int size, int row);
int	ft_recursive_factorial(int nb);

#endif
