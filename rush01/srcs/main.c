#include "libft.h"

int	is_safe_data(int **board, int *data, int size, int row)
{
	if (row == 1 && safe_row_start(board, data, size) == 0)
		return (0);
	if (row == size - 2 && safe_row_end(board, data, size) == 0)
		return (0);
	if (safe_col_start(board, data, size, row) == 0)
		return (0);
	if (safe_col_end(board, data, size, row) == 0)
		return (0);
	if (row > 1 && safe_up(board, data, size, row) == 0)
		return (0);
	return (1);
}

int	safe_total_col_up(int **board, int size, int col)
{
	int	i;
	int	j;
	int	count;

	i = 1;
	j = 0;
	count = 0;
	while (i < size - 1)
	{
		if (board[i][col] > j)
		{
			j = board[i][col];
			count++;
		}
		i++;
	}
	if (board[0][col] == count)
		return (1);
	return (0);
}

int	safe_total_col_down(int **board, int size, int col)
{
	int	i;
	int	j;
	int	count;

	i = size - 2;
	j = 0;
	count = 0;
	while (i > 0)
	{
		if (board[i][col] > j)
		{
			j = board[i][col];
			count++;
		}
		i--;
	}
	if (board[size - 1][col] == count)
		return (1);
	return (0);
}

int	safe_end(int **board, int size)
{
	int	i;

	i = 0;
	while (++i < size - 1)
		if (safe_total_col_up(board, size, i) == 0)
			return (0);
	i = 0;
	while (++i < size - 1)
		if (safe_total_col_down(board, size, i) == 0)
			return  (0);
	return (1);
}
	

int	recursive_resolv_puzzle(int **board, int **data, int size, int row)
{
	int	i;
	int	j;

	i = 0;
	j = ft_recursive_factorial(size - 2);
	if (row > size - 2 && safe_end(board, size) == 1)
	{
		print_board_resolv(board, size);
		return (1);
	}
	while (i < j)
	{
		if (is_safe_data(board, data[i], size, row) == 1)
		{
			cpy_board_data(board, data[i], size, row);
			recursive_resolv_puzzle(board, data, size, row + 1);
		}
		i++;
	}
	return (0);
}

int main(int argc, char **argv)
{
	int	**board;
	int	**data;
	int	size;

	argc = 1;
	size = size_tab_argv(argv[argc]) + 2;
	data = tab_facto(size - 2);
	board = creat_board(argv[argc]);
	recursive_resolv_puzzle(board, data, size, argc);
	
	return (0);
}
