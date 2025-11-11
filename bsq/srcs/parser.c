#include "bsq.h"

static int parse_header(const char *buf, int len, int *consumed, t_map *m)
{
    int i;
    int nl;

    i = 0;
    nl = -1;
    while (i < len)
    {
        if (buf[i] == '\n')
        {
            nl = i;
            break;
        }
        i++;
    }
    if (nl < 4)
        return (1);
    m->empty = buf[nl - 3];
    m->obst  = buf[nl - 2];
    m->full  = buf[nl - 1];
    if (m->empty == m->obst || m->empty == m->full || m->obst == m->full)
        return (1);
    if (ft_atoi_nonneg(buf, nl - 3, &m->rows) != 0)
        return (1);
    if (m->rows <= 0)
        return (1);
    *consumed = nl + 1;
    return (0);
}

static int parse_lines(const char *buf, int len, int off, t_map *m)
{
    int r;
    int cplen;
    int i;
    int cols;
    int start;
    char ch;
    int k;
    int j;

    r = 0;
    cplen = 0;
    i = off;
    cols = -1;
    while (r < m->rows)
    {
        start = i;
        while (i < len && buf[i] != '\n')
            i++;
        if (i >= len)
            return (1);
        cplen = i - start;
        if (cplen <= 0)
            return (1);
        if (cols == -1)
            cols = cplen;
        else if (cplen != cols)
            return (1);
        k = start;
        while (k < i)
        {
            ch = buf[k];
            if (ch != m->empty && ch != m->obst)
                return (1);
            k++;
        }
        i++;
        r++;
    }
    m->cols = cols;
    m->grid = (char *)malloc(m->rows * m->cols);
    if (!m->grid)
        return (1);
    r = 0;
    i = off;
    while (r < m->rows)
    {
        j = 0;
        while (j < m->cols)
        {
            ch = buf[i++];
            m->grid[r * m->cols + j] = ch;
            j++;
        }
        if (buf[i] != '\n')
        {
            free(m->grid);
            m->grid = NULL;
            return (1);
        }
        i++;
        r++;
    }
    return (0);
}

int parse_buffer_to_map(const char *buf, int len, t_map *out)
{
    int off;

    off = 0;
    out->rows = 0;
    out->cols = 0;
    out->empty = 0;
    out->obst = 0;
    out->full = 0;
    out->grid = NULL;
    if (parse_header(buf, len, &off, out) != 0)
        return (1);
    if (parse_lines(buf, len, off, out) != 0)
    {
        free_map(out);
        return (1);
    }
    return (0);
}

void free_map(t_map *m)
{
    if (!m)
        return;
    if (m->grid)
        free(m->grid);
    m->grid = NULL;
}
