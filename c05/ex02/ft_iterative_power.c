int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	j;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	i = 1;
	j = 1;
	while (i <= power)
	{
		j *= nb;
		i++;
	}
	return (j);
}
