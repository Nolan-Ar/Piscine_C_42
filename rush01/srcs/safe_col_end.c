#include "libft.h"

int	safe_col_end(int **board, int *data, int size, int row)
{
	int	i;
	int	j;
	int	count;

	i = size - 2;
	j = 0;
	count = 0;
	while (i >= 0)
	{
		if (data[i] > j)
		{
			j = data[i];
			count++;
		}
		i--;
	}
	if (count == board[row][size - 1])
		return (1);
	return (0);
}
