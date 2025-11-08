/* Robust permutation generator for 1..n */
#include <stdlib.h>
#include "libft.h"

static void fill_base(int *arr, int n)
{
    int i = 0;
    while (i < n)
    {
        arr[i] = i + 1;
        i++;
    }
}

static void copy_row(int *dst, int *src, int n)
{
    int i = 0;
    while (i < n)
    {
        dst[i] = src[i];
        i++;
    }
}

static int next_permutation(int *a, int n)
{
    int i = n - 2;
    int j, t, l, r;
    while (i >= 0 && a[i] >= a[i + 1])
        i--;
    if (i < 0)
        return 0;
    j = n - 1;
    while (a[j] <= a[i])
        j--;
    t = a[i]; a[i] = a[j]; a[j] = t;
    l = i + 1; r = n - 1;
    while (l < r)
    {
        t = a[l]; a[l] = a[r]; a[r] = t;
        l++; r--;
    }
    return 1;
}

int	**tab_facto(int n)
{
    int **tab;
    int total;
    int i;
    int *curr;

    total = ft_recursive_factorial(n);
    tab = (int **)malloc(sizeof(int *) * total);
    if (!tab)
        return (NULL);
    curr = (int *)malloc(sizeof(int) * n);
    if (!curr)
    {
        free(tab);
        return (NULL);
    }
    fill_base(curr, n);
    i = 0;
    while (i < total)
    {
        tab[i] = (int *)malloc(sizeof(int) * n);
        if (!tab[i])
        {
            while (i-- > 0)
                free(tab[i]);
            free(tab);
            free(curr);
            return (NULL);
        }
        copy_row(tab[i], curr, n);
        if (i < total - 1 && !next_permutation(curr, n))
            break;
        i++;
    }
    free(curr);
    return tab;
}
