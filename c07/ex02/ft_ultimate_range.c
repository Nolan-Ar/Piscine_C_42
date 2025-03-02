#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	range_size;
	int	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	range_size = max - min;
	*range = malloc(sizeof(int) * range_size);
	if (*range == NULL)
		return (-1);
	i = 0;
	while (i < range_size)
	{
		(*range)[i] = min + i;
		i++;
	}
	return (range_size);
}
