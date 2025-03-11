#include "libft.h"

void	tab_cpy(int *tab_d, int *tab_s, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		tab_d[i] = tab_s[i];
		i++;
	}
}
