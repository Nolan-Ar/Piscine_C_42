int	ft_iterative_factorial(int nb)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (i <= nb)
	{
		j *= i;
		i++;
	}
	return (j);
}
