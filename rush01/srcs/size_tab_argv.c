#include "libft.h"

int	ft_str_is_numeric_and_space(char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		if (!((src[i] >= '0' && src[i] <= '9') || src[i] == ' '))
			return (1);
		i++;
	}
	return (0);
}


int	ft_str_is_regular(char *src)
{
	int	i;

	i = 0;
	if (!(src[i] >= '0' && src[i] <= '9'))
		return (1);
	i++;
	while (src[i])
	{
		if (i % 2 == 1 && src[i] != ' ')
			return (1);
		if (i % 2 == 0 && (src[i] < '0' || src[i] > '9'))
			return (1);
		i++;
	}
	return (0);
}


int	size_tab_argv(char *src)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	if (ft_str_is_numeric_and_space(src) == 1)
		return (0);
	if (ft_str_is_regular(src) == 1)
		return (0);
	while (src[i])
	{
		if (src[i] >= '0' && src[i] <= '9')
			n++;
		i++;
	}
	if (n % 4 != 0)
		return (0);
	return (n / 4);
}
