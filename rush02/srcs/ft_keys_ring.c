#include <stdlib.h>
#include "ft_utils_convert.h"
#include "ft_utils.h"


char	*high_numbers_keys_ring(int n)
{
	char	*dest;
	int		i;
	int		fac;

	i = 0;
	fac = (n * 3) + 1;
	dest = malloc(sizeof(char) * (fac + 1));
	if (!dest)
		return (NULL);
	while (i < fac)
	{
		if (i == 0)
			dest[i] = '1';
		else
			dest[i] = '0';
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*low_numbers_keys_ring(int n)
{
	char	*dest;

	if (n > 20)
	{
		n = (((n - 20) * 10) + 20);
	}
	dest = ft_itoi(n);
	return (dest);
}

char	**create_keys_ring(int size)
{
	char	**keys;
	int		i;

	i = 0;
	keys = malloc(sizeof(char *) * (size + 1));
	if (!keys)
		return (NULL);
	while (i < size)
	{
		keys[i] = NULL;
		if (i < 29)
			keys[i] = low_numbers_keys_ring(i);
		else
			keys[i] = high_numbers_keys_ring(i - 28);
		if (!keys[i])
		{
			free_tab(keys, size);
			return (NULL);
		}
		i++;
	}
	keys[i] = NULL;
	return (keys);
}
