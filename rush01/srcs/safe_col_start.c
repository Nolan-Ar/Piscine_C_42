#include "libft.h"

int	safe_col_start(int **board, int *data, int size, int row)
{
	int	i;
	int	j;
	int	count;

    i = 0;
    j = 0;
    count = 0;
    /* data has length (size - 2) */
    while (i < size - 2)
    {
        if (data[i] > j)
        {
            j = data[i];
            count++;
        }
        i++;
    }
	if (count == board[row][0])
		return (1);
	return (0);
}
