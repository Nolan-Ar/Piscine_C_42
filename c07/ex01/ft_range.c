#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*tab;
	int	range_size;
	int	i;

	if (min >= max)
		return (NULL);
	range_size = max - min;
	tab = malloc(sizeof(int) * range_size);
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (i < range_size)
	{
		tab[i] = min + i;
		i++;
	}
	return (tab);
}
