#include "libft.h"

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = size - 1;
	while (i < (size / 2))
	{
		k = tab[j];
		tab[j] = tab[i];
		tab[i] = k;
		i++;
		j--;
	}
}
