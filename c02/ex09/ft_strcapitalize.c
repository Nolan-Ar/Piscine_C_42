int is_true(char *str, int n)
{
    if (n == 0 || !(str[n - 1] >= 'a' && str[n - 1] <= 'z') &&
        !(str[n - 1] >= 'A' && str[n - 1] <= 'Z') &&
        !(str[n - 1] >= '0' && str[n - 1] <= '9'))
    {
        if (str[n] >= 'a' && str[n] <= 'z')
            return (1);
    }
    return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (is_true(str, i) == 1)
			str[i] -= 32;
		i++;
	}
	return (str);
}