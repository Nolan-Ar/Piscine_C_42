#include <stdlib.h>

char    *ft_strdump(char *src, int size)
{
        char    *dest;
        int             i;

        i = 0;
        if (!src)
                return (NULL);
        dest = malloc(sizeof(char) * (size + 1));
        if (!dest)
                return (NULL);
        while (i < size && src[i])
        {
                dest[i] = src[i];
                i++;
        }
        dest[i] = '\0';
        return (dest);
}

int     ft_str_is_numeric(char *src)
{
        int     i;

        i = 0;
        while (src[i])
        {
                if (!(src[i] >= '0' && src[i] <= '9'))
                        return (1);
                i++;
        }
        return (0);
}

int     ft_strlen(char *src)
{
        int     i;

        i = 0;
        while (src[i])
                i++;
        return (i);
}

int     size_input_norm(char *src)
{
        int     i;

        i = 0;
        while (src[i])
                i++;
        while (i % 3 != 0)
                i++;
        return (i);
}

char    *normalize_input(char *src)
{
        char    *dest;
        int             i;
        int             j;
        int             len;

        i = 0;
        j = 0;
        len = size_input_norm(src);
        dest = malloc(sizeof(char) * (len + 1));
        if (!dest)
                return (NULL);
        while (i < len - ft_strlen(src))
        {
                dest[i] = '0';
                i++;
        }
        while (src[j])
        {
                dest[i + j] = src[j];
                j++;
        }
        dest[i + j] = '\0';
        return (dest);
}
