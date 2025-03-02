#include <unistd.h>

void	print_board(int board[10][10])
{
	char	out[10];
	int		row;
	int		col;

	col = 0;
	while (col < 10)
	{
		row = 0;
		while (row < 10 && board[row][col] == 0)
			row++;
		out[col] = row + '0';
		col++;
	}
	write(1, out, 10);
	write(1, "\n", 1);
}

int	is_safe(int board[10][10], int row, int col)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 10)
		if (board[row][i] == 1)
			return (0);
	i = row;
	j = col;
	while (--i >= 0 && j-- >= 0)
		if (board[i][j] == 1)
			return (0);
	i = row;
	j = col;
	while (++i < 10 && j-- >= 0)
		if (board[i][j] == 1)
			return (0);
	return (1);
}

int	resolve_queens(int board[10][10], int col)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (col >= 10)
	{
		print_board(board);
		return (1);
	}
	while (i < 10)
	{
		if (is_safe(board, i, col) == 1)
		{
			board[i][col] = 1;
			count += resolve_queens(board, col + 1);
			board[i][col] = 0;
		}
		i++;
	}
	return (count);
}

int	ft_ten_queens_puzzle(void)
{
	int	board[10][10];
	int	count;
	int	i;
	int	j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			board[i][j] = 0;
			j++;
		}
		i++;
	}
	count = resolve_queens(board, 0);
	return (count);
}
