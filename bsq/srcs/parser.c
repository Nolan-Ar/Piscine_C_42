#include "bsq.h"

static int parse_header(const char *buf, int len, int *consumed, t_map *m)
{
    int i = 0;
    int nl = -1;
    while (i < len)
    {
        if (buf[i] == '\n') { nl = i; break; }
        i++;
    }
    if (nl < 4) return 1; /* need at least 1 digit + 3 chars */
    m->empty = buf[nl - 3];
    m->obst  = buf[nl - 2];
    m->full  = buf[nl - 1];
    if (m->empty == m->obst || m->empty == m->full || m->obst == m->full)
        return 1;
    if (ft_atoi_nonneg(buf, nl - 3, &m->rows) != 0) return 1;
    if (m->rows <= 0) return 1;
    *consumed = nl + 1;
    return 0;
}

static int parse_lines(const char *buf, int len, int off, t_map *m)
{
    int r = 0;
    int cplen = 0;
    int i = off;
    int cols = -1;
    /* First pass: validate and find cols */
    while (r < m->rows)
    {
        int start = i;
        while (i < len && buf[i] != '\n') i++;
        if (i >= len) return 1; /* missing newline */
        cplen = i - start;
        if (cplen <= 0) return 1;
        if (cols == -1) cols = cplen;
        else if (cplen != cols) return 1;
        for (int k = start; k < i; k++)
        {
            char ch = buf[k];
            if (ch != m->empty && ch != m->obst) return 1;
        }
        i++; r++;
    }
    m->cols = cols;
    m->grid = (char *)malloc(m->rows * m->cols);
    if (!m->grid) return 1;
    /* Second pass: copy */
    r = 0; i = off;
    while (r < m->rows)
    {
        for (int j = 0; j < m->cols; j++)
        {
            char ch = buf[i++];
            m->grid[r * m->cols + j] = ch;
        }
        if (buf[i] != '\n') { free(m->grid); m->grid = NULL; return 1; }
        i++; r++;
    }
    return 0;
}

int parse_buffer_to_map(const char *buf, int len, t_map *out)
{
    int off = 0;
    out->rows = out->cols = 0;
    out->empty = out->obst = out->full = 0;
    out->grid = NULL;
    if (parse_header(buf, len, &off, out) != 0) return 1;
    if (parse_lines(buf, len, off, out) != 0) { free_map(out); return 1; }
    return 0;
}

void free_map(t_map *m)
{
    if (!m) return;
    if (m->grid) free(m->grid);
    m->grid = NULL;
}

