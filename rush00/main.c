void	rush(int x, int y);

int	ft_str_is_numeric(char *str)
{
    int	i;

    i = 0;
    while (str[i])
    {
        if (!(str[i] >= '0' && str[i] <= '9'))
            return (0);
        i++;
    }
    return (1);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
    while (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign *= -1;
        i++;
    }
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int	main(int argc, char **argv)
{
    if (argc == 1)
    {
        rush(5, 3);
    }
    else if (argc == 3)
    {
        if (!ft_str_is_numeric(argv[1]) || !ft_str_is_numeric(argv[2]))
            return (1);
        if (ft_atoi(argv[1]) < 0 || ft_atoi(argv[2]) < 0)
            return (1);
        rush(ft_atoi(argv[1]), ft_atoi(argv[2]));
    }
    return (0);
}
