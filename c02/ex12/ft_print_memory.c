#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_asci(unsigned char *addr, unsigned int start, unsigned int end)
{
	while (start < end)
	{
		if (addr[start] < 32 || addr[start] > 126)
			ft_putchar('.');
		else
			ft_putchar(addr[start]);
		start++;
	}
	while (start % 16 != 0)
	{
		ft_putchar(' ');
		start++;
	}
}

void	ft_print_hexa(unsigned char *addr, unsigned int start, unsigned int end)
{
	unsigned int i;

	i = start;
	while (i < end)
	{
		ft_putchar("0123456789abcdef"[addr[i] / 16]);
		ft_putchar("0123456789abcdef"[addr[i] % 16]);
		if ((i + 1) % 2 == 0)
			ft_putchar(' ');
		i++;
	}
	while (i % 16 != 0)
	{
		ft_putchar(' ');
		ft_putchar(' ');
		if ((i + 1) % 2 == 0)
			ft_putchar(' ');
		i++;
	}
}

void	ft_print_addr(unsigned long long addr)
{
	int i;

	i = (sizeof(void *) * 2) - 1;
	while (i >= 0)
	{
		ft_putchar("0123456789abcdef"[(addr >> (i * 4)) & 0xF]);
		i--;
	}
	ft_putchar(':');
	ft_putchar(' ');
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned int	line_end;

	i = 0;
	while (i < size)
	{
		if (i + 16 > size)
			line_end = size;
		else
			line_end = i + 16;

		ft_print_addr((unsigned long long)addr + i);
		ft_print_hexa((unsigned char *)addr, i, line_end);
		ft_print_asci((unsigned char *)addr, i, line_end);
		ft_putchar('\n');

		i += 16;
	}
	return (addr);
}
