int	ft_iterative_factorial(int nb)
{
	int	i;
	int	j;

	if (nb < 0)
		return (0);
	i = 1;
	j = 1;
	while (i <= nb)
	{
		j *= i;
		i++;
	}
	return (j);
}
