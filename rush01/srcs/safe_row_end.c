#include "libft.h"

int	safe_row_end(int **board, int *data, int size)
{
	int	i;

	i = 0;
	while (++i < size - 1)
		if (board[size - 1][i] == 1 && data[i - 1] == size - 2)
			return (1);
	return (0);
}
