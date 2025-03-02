#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_verif_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(base) <= 1)
		return (0);
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '-' || base[i] == '+')
			return (0);
		while (base[j])
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	nbr_abs;
	int			base_len;

	base_len = ft_strlen(base);
	if (ft_verif_base(base) == 0)
		return ;
	nbr_abs = nbr;
	if (nbr_abs < 0)
	{
		ft_putchar('-');
		nbr_abs = -nbr_abs;
	}
	if (nbr_abs >= base_len)
		ft_putnbr_base(nbr_abs / base_len, base);
	ft_putchar(base[nbr_abs % base_len]);
}
