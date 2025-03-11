#include "libft.h"

void	creat_base_tab(int *tab, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		tab[i] = i + 1;
		i++;
	}
}
