#include "bsq.h"

int read_all_fd(int fd, char **out_buf, int *out_len)
{
    int cap;
    int len;
    char *buf;
    char *nb;
    int n;

    cap = 4096;
    len = 0;
    buf = (char *)malloc(cap);
    if (!buf)
        return (1);
    while (1)
    {
        if (len == cap)
        {
            nb = ft_realloc(buf, cap, cap * 2);
            if (!nb)
            {
                free(buf);
                return (1);
            }
            buf = nb;
            cap *= 2;
        }
        n = read(fd, buf + len, cap - len);
        if (n < 0)
        {
            free(buf);
            return (1);
        }
        if (n == 0)
            break;
        len += n;
    }
    *out_buf = buf;
    *out_len = len;
    return (0);
}
