int     ft_factorial_power(int nb, int power)
{
    if (power < 0)
        return (0);
    if (power == 0)
        return (1);
    return (nb * ft_factorial_power(nb, power - 1));
}
