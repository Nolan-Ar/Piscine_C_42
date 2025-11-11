int	is_alnum(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	new_word;

	i = 0;
	new_word = 1;
	while (str[i])
	{
		if (new_word && str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		else if (!new_word && str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		if (is_alnum(str[i]))
			new_word = 0;
		else
			new_word = 1;
		i++;
	}
	return (str);
}