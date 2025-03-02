#include <stdlib.h>

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return (i);
}

int is_separator(char c, char *charset)
{
    int i = 0;
    while (charset[i])
    {
        if (charset[i] == c)
            return (1);
        i++;
    }
    return (0);
}

char *ft_strndup(char *src, int n)
{
	int	i;

	i = 0;
    char *dest = malloc(n + 1);
    if (!dest)
        return (NULL);
    while (i < n)
	{
        dest[i] = src[i];
		i++;
	}
    dest[n] = '\0';
    return (dest);
}

int count_words(char *str, char *charset)
{
    int count = 0;
    int i = 0;

    while (str[i])
    {
        while (str[i] && is_separator(str[i], charset))
            i++;
        if (str[i])
        {
            count++;
            while (str[i] && !is_separator(str[i], charset))
                i++;
        }
    }
    return (count);
}

char **ft_split(char *str, char *charset)
{
    char **buffer;
    int start;
	int	end;
	int	i;

    if (!str || !charset)
        return (NULL);
    buffer = malloc(sizeof(char *) * (count_words(str, charset) + 1));
    if (!buffer)
        return (NULL);
    start = 0;
    end = 0;
    i = 0;
    while (str[end])
    {
        while (str[end] && is_separator(str[end], charset))
            end++;
        start = end;
        while (str[end] && !is_separator(str[end], charset))
            end++;
        if (end > start)
            buffer[i++] = ft_strndup(str + start, end - start);
    }
    buffer[i] = NULL;
    return (buffer);
}

