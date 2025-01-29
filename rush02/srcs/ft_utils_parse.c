#include <stdlib.h>
#include "ft_utils_input.h"
#include "ft_utils_convert.h"

int     absolute_inp(int i, char *src)
{
        if (i % 3 == 0 && src[i] != '0')
                return (2);
        if (i % 3 == 1 && src[i] <= '1')
                        return (0);
	else if (i % 3 == 1 && src[i] > '1')
			return (1);
	if ((i % 3 == 2 && src[i] == '0') || src[i + 1] == '\0')
		return (1);
	else if (i % 3 == 2 && src[i + 1] != '\0')
		return (2);
        return (0);
}

int     size_absolute_input(char *src)
{
        char    *dest;
        int             count;
        int             i;

        i = 0;
        count = 0;
        dest = normalize_input(src);
        if (!dest)
                return (1);
        while (dest[i])
        {
		if (dest[i] != '0')
                	count += absolute_inp(i, dest);
                i++;
        }
        free(dest);
        return (count);
}

int     ft_atoi_char(char c1, char c2)
{
        return (((c1 - '0') * 10) + c2 - '0');
}

char    *write_higt_numbers(int size)
{
        char    *dest;
        int     i;

        i = 1;
        dest = malloc(sizeof(char) * (size + 1));
        if (!dest)
                return (NULL);
        dest[0] = '1';
        while (i < size)
        {
                dest[i] = '0';
                i++;
        }
        dest[i] = '\0';
        return (dest);
}
