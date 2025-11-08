#include <unistd.h>

void	print_first_row(int x)
{
	int	i;

	i = 0;
	while (i < x)
	{
		if (i == 0)
			write(1, "/", 1);
		else if ((i + 1) == x)
			write(1, "\\", 1);
		else
			write(1, "*", 1);
		i++;
	}
	write(1, "\n", 1);
}

void	print_last_row(int x)
{
	int	i;

	i = 0;
	while (i < x)
	{
		if (i == 0)
			write(1, "\\", 1);
		else if ((i + 1) == x)
			write(1, "/", 1);
		else
			write(1, "*", 1);
		i++;
	}
	write(1, "\n", 1);
}

void	print_row(int x)
{
	int	i;

	i = 0;
	while (i < x)
	{
		if (i == 0)
			write(1, "*", 1);
		else if ((i + 1) == x)
			write(1, "*", 1);
		else
			write(1, " ", 1);
		i++;
	}
	write(1, "\n", 1);
}

void	rush(int x, int y)
{
    int	i;

    if (x <= 0 || y <= 0)
        return ;
    i = 0;
    while (i < y)
    {
        if (i == 0)
            print_first_row(x);
		else if ((i + 1) == y)
			print_last_row(x);
		else
			print_row(x);
		i++;
	}
}
