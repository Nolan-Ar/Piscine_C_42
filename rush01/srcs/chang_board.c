#include "libft.h"

void	chang_board(int **board, int *tab, int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size )
			board[i][j] = 0;
	}
	j = 0;
	i = 0;
	while (++i < size - 1)
		board[0][i] = tab[j++];
	i = 0;
	while (++i < size - 1)
		board[size - 1][i] = tab[j++];
	i = 0;
	while (++i < size - 1)
		board[i][0] = tab[j++];
	i = 0;
	while (++i < size - 1)
		board[i][size - 1] = tab[j++];
}
