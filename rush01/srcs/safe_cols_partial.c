#include "libft.h"

/*
 * After copying a row into the board, check partial column constraints from top:
 * - The visible count so far must not exceed the required top value.
 * - The maximum possible visible count with remaining rows must be enough
 *   to reach the required top value.
 * - If this was the last row, the visible count must equal the required value.
 */
int	safe_cols_partial(int **board, int size, int row)
{
    int col;

    col = 1;
    while (col < size - 1)
    {
        int i = 1;
        int maxv = 0;
        int visible = 0;
        while (i <= row)
        {
            if (board[i][col] > maxv)
            {
                maxv = board[i][col];
                visible++;
            }
            i++;
        }
        if (visible > board[0][col])
            return (0);
        if (visible + (size - 2 - row) < board[0][col])
            return (0);
        if (row == size - 2 && visible != board[0][col])
            return (0);
        col++;
    }
    return (1);
}

