#include "libft.h"

void	chang_tab(int *tab, int n)
{
	int	i;

	i = tab[n];
	tab[n] = tab[n + 1];
	tab[n + 1] = i;
}

void	chang_base_tab(int *tab, int index)
{
	int	i;

	i = tab[0];
	tab[0] = tab[index];
	tab[index] = i;
}

void	write_tab_facto(int **tab, int n)
{
	int	i;
	int	j;
	int	k;
	int	l;

	i = 1;
	k = 2;
	l = 1;
	j = ft_recursive_factorial(n) / n;
	creat_base_tab(tab[0], n);
	while (i < ft_recursive_factorial(n))
	{
		if (k == n - 1)
			k = 1;
		tab_cpy(tab[i], tab[i - 1], n);
		chang_tab(tab[i], k);
		if (i == j)
		{
			chang_base_tab(tab[i], l);
			j += ft_recursive_factorial(n) / n;
			l++;
		}
		k++;
		i++;
	}
}

int	**tab_facto(int n)
{
	int	**tab;
	int	i;

	i = 0;
	tab = (int **)malloc(ft_recursive_factorial(n) * sizeof(int *));
	if (!tab)
		return (NULL);
	while (i < ft_recursive_factorial(n))
	{
		tab[i] = (int *)malloc(n * sizeof(int));
		if (!tab[i])
		{
			while(i--)
				free(tab[i]);
			free(tab);
			return (NULL);
		}
		i++;
	}
	write_tab_facto(tab, n);
	return (tab);
}
