#include "bsq.h"

int solve_bsq(t_map *m)
{
    int cols = m->cols;
    int rows = m->rows;
    int *dp = (int *)malloc(sizeof(int) * (cols + 1));
    if (!dp) return 1;
    for (int j = 0; j <= cols; j++) dp[j] = 0;
    int max_sz = 0, max_r = 0, max_c = 0;
    for (int r = 0; r < rows; r++)
    {
        int prev_diag = 0; /* dp from previous row, previous column */
        for (int c = 1; c <= cols; c++)
        {
            int temp = dp[c]; /* save previous row dp(c) */
            if (m->grid[r*cols + (c-1)] == m->obst)
                dp[c] = 0;
            else
            {
                int a = dp[c];      /* top */
                int b = dp[c-1];    /* left */
                int d = prev_diag;  /* top-left */
                int min = a < b ? a : b;
                if (d < min) min = d;
                dp[c] = min + 1;
                if (dp[c] > max_sz)
                {
                    max_sz = dp[c];
                    max_r = r;
                    max_c = c-1;
                }
            }
            prev_diag = temp;
        }
    }
    free(dp);
    if (max_sz > 0)
    {
        for (int rr = max_r - max_sz + 1; rr <= max_r; rr++)
            for (int cc = max_c - max_sz + 1; cc <= max_c; cc++)
                m->grid[rr*cols + cc] = m->full;
    }
    return 0;
}
