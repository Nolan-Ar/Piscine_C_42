#include "bsq.h"

int ft_strlen(const char *s)
{
    int i = 0;
    if (!s) return 0;
    while (s[i]) i++;
    return i;
}

void ft_putstr(int fd, const char *s)
{
    if (!s) return;
    write(fd, s, ft_strlen(s));
}

void ft_putchar(int fd, char c)
{
    write(fd, &c, 1);
}

int ft_atoi_nonneg(const char *s, int len, int *out)
{
    long v = 0;
    int i = 0;
    if (len <= 0) return 1;
    while (i < len)
    {
        if (s[i] < '0' || s[i] > '9') return 1;
        v = v * 10 + (s[i] - '0');
        if (v > 2147483647) return 1;
        i++;
    }
    *out = (int)v;
    return 0;
}

void *ft_realloc(void *ptr, size_t old_sz, size_t new_sz)
{
    void *p = malloc(new_sz);
    if (!p) return NULL;
    if (ptr && old_sz)
    {
        size_t n = old_sz < new_sz ? old_sz : new_sz;
        char *d = (char *)p;
        char *s = (char *)ptr;
        for (size_t i = 0; i < n; i++) d[i] = s[i];
        free(ptr);
    }
    return p;
}

