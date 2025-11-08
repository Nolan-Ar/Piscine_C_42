#include "libft.h"

int	*seed_tab(char *src)
{
	int	i;
	int	j;
	int	count;
	int	*t_seed;

	count = size_tab_argv(src) * 4;
	t_seed = malloc(count * sizeof(int));
	if (t_seed == NULL)
		return (NULL);
	i = 0;
	j = 0;
    while (i < count)
    {
        if (src[j] >= '0' && src[j] <= '9')
        {
            t_seed[i] = src[j] - '0';
            i++;
        }
        j++;
    }
	return (t_seed);
}
