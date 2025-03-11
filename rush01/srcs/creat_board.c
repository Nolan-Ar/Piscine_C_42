#include "libft.h"

int	**creat_board(char *src)
{
	int	*t_seed;
	int	**board;
	int	i;
	int	size;

	size = size_tab_argv(src) + 2;
	t_seed = seed_tab(src);
	board = (int **)malloc(size * sizeof(int *));
	if (board == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		board[i] = (int *)malloc(size * sizeof(int));
		if (board[i] == NULL)
		{
			while(i-- > 0)
				free (board[i]);
			free (board);
			return (NULL);
		}
		i++;
	}
	chang_board(board, t_seed, size);
	free (t_seed);
	return (board);
}
