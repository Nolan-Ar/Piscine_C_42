#include "libft.h"

int	safe_row_start(int **board, int *data, int size)
{
	int	i;

	i = 0;
	while (++i < size - 1)
		if (board[0][i] == 1 && data[i - 1] == size - 2)
			return (1);
	return (0);
}
