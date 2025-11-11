#include "bsq.h"

int ft_strlen(const char *s)
{
    int i;

    i = 0;
    if (!s)
        return (0);
    while (s[i])
        i++;
    return (i);
}

void ft_putstr(int fd, const char *s)
{
    if (!s)
        return;
    write(fd, s, ft_strlen(s));
}

void ft_putchar(int fd, char c)
{
    write(fd, &c, 1);
}

int ft_atoi_nonneg(const char *s, int len, int *out)
{
    long v;
    int i;

    v = 0;
    i = 0;
    if (len <= 0)
        return (1);
    while (i < len)
    {
        if (s[i] < '0' || s[i] > '9')
            return (1);
        v = v * 10 + (s[i] - '0');
        if (v > 2147483647)
            return (1);
        i++;
    }
    *out = (int)v;
    return (0);
}

void *ft_realloc(void *ptr, size_t old_sz, size_t new_sz)
{
    void *p;
    size_t n;
    char *d;
    char *s;
    size_t i;

    p = malloc(new_sz);
    if (!p)
        return (NULL);
    if (ptr && old_sz)
    {
        n = old_sz < new_sz ? old_sz : new_sz;
        d = (char *)p;
        s = (char *)ptr;
        i = 0;
        while (i < n)
        {
            d[i] = s[i];
            i++;
        }
        free(ptr);
    }
    return (p);
}
