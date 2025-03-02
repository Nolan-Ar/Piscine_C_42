#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_hexa(int i, char *str, char *hexa)
{
	ft_putchar('\\');
	ft_putchar(hexa[str[i] / 16]);
	ft_putchar(hexa[str[i] % 16]);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 32 || str[i] > 126)
			ft_print_hexa(i, str, "0123456789abcdef");
		else
			ft_putchar(str[i]);
		i++;
	}
}