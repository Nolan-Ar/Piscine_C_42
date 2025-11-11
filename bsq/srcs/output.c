#include "bsq.h"

void print_map(const t_map *m)
{
    int cols;
    int rows;
    int r;

    cols = m->cols;
    rows = m->rows;
    r = 0;
    while (r < rows)
    {
        write(1, m->grid + (r*cols), cols);
        write(1, "\n", 1);
        r++;
    }
}
