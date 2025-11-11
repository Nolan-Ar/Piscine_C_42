#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_tab(int *tab, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar(tab[i] + '0');
		i++;
	}
}

void	ft_print_comb_recursive(int *tab, int n, int index, int start)
{
	int	i;

	i = start;
	if (index == n)
	{
		ft_print_tab(tab, n);
		if (tab[0] < 10 - n)
		{
			ft_putchar(',');
			ft_putchar(' ');
		}
		return ;
	}
	while (i <= 9)
	{
		tab[index] = i;
		ft_print_comb_recursive(tab, n, index + 1, i + 1);
		i++;
	}
}

void	ft_print_combn(int n)
{
	int	tab[10];
	int	index;
	int	start;

	index = 0;
	start = 0;
	if (n < 1 || n > 9)
		return ;
	ft_print_comb_recursive(tab, n, index, start);
}

