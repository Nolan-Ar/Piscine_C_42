#include "bsq.h"

int solve_bsq(t_map *m)
{
    int cols;
    int rows;
    int *dp;
    int j;
    int max_sz;
    int max_r;
    int max_c;
    int r;
    int prev_diag;
    int c;
    int temp;
    int a;
    int b;
    int d;
    int min;
    int rr;
    int cc;

    cols = m->cols;
    rows = m->rows;
    dp = (int *)malloc(sizeof(int) * (cols + 1));
    if (!dp)
        return (1);
    j = 0;
    while (j <= cols)
    {
        dp[j] = 0;
        j++;
    }
    max_sz = 0;
    max_r = 0;
    max_c = 0;
    r = 0;
    while (r < rows)
    {
        prev_diag = 0;
        c = 1;
        while (c <= cols)
        {
            temp = dp[c];
            if (m->grid[r*cols + (c-1)] == m->obst)
                dp[c] = 0;
            else
            {
                a = dp[c];
                b = dp[c-1];
                d = prev_diag;
                min = a < b ? a : b;
                if (d < min)
                    min = d;
                dp[c] = min + 1;
                if (dp[c] > max_sz)
                {
                    max_sz = dp[c];
                    max_r = r;
                    max_c = c-1;
                }
            }
            prev_diag = temp;
            c++;
        }
        r++;
    }
    free(dp);
    if (max_sz > 0)
    {
        rr = max_r - max_sz + 1;
        while (rr <= max_r)
        {
            cc = max_c - max_sz + 1;
            while (cc <= max_c)
            {
                m->grid[rr*cols + cc] = m->full;
                cc++;
            }
            rr++;
        }
    }
    return (0);
}
