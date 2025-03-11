#include "libft.h"

int	safe_up(int **board, int *data, int size, int row)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 1;
	while (i < size - 2)
	{
		k = row - 1;
		while (k > 0)
		{
			if (data[i] == board[k][j])
				return (0);
			k--;
		}
		i++;
		j++;
	}
	return (1);
}
