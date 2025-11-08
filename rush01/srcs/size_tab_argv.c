#include "libft.h"

int	ft_str_is_numeric_and_space(char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		if (!((src[i] >= '0' && src[i] <= '9') || src[i] == ' '))
			return (1);
		i++;
	}
	return (0);
}


int	ft_str_is_regular(char *src)
{
    int	i;

    i = 0;
    /* must start with a digit between '1' and '9' */
    if (!(src[i] >= '1' && src[i] <= '9'))
        return (1);
    i++;
    while (src[i])
    {
        if (i % 2 == 1 && src[i] != ' ')
            return (1);
        /* even indexes (0-based) must be digits 1..9 */
        if (i % 2 == 0 && (src[i] < '1' || src[i] > '9'))
            return (1);
        i++;
    }
    return (0);
}


int	size_tab_argv(char *src)
{
    int	i;
    int	n;
    int base;

    i = 0;
    n = 0;
    if (ft_str_is_numeric_and_space(src) == 1)
        return (0);
    if (ft_str_is_regular(src) == 1)
        return (0);
    while (src[i])
    {
        if (src[i] >= '0' && src[i] <= '9')
            n++;
        i++;
    }
    if (n % 4 != 0)
        return (0);
    base = n / 4;
    /* ensure all digits are within 1..base */
    i = 0;
    while (src[i])
    {
        if (src[i] >= '1' && src[i] <= '9')
        {
            if (src[i] - '0' > base)
                return (0);
        }
        i++;
    }
    return (base);
}
