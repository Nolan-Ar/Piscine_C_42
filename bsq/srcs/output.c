#include "bsq.h"

void print_map(const t_map *m)
{
    int cols = m->cols;
    int rows = m->rows;
    for (int r = 0; r < rows; r++)
    {
        write(1, m->grid + (r*cols), cols);
        write(1, "\n", 1);
    }
}

