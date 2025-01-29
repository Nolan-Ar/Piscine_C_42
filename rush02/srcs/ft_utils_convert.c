#include <stdlib.h>

void	ft_bzero(char *s, int n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n--)
		*ptr++ = '\0';
}

char *ft_strnew(int size)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(*str) * (size + 1))))
		return (NULL);
	ft_bzero(str, size + 1);
	return (str);
}

int	ft_atoi(char *str)
{
	int	i;
	int	result;
	int	next_result;

	i = 0;
	result = 0;
	next_result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		next_result = result = (result * 10) + (str[i] - '0');
		if (next_result < result)
			return (result);
		result = next_result;
		i++;
	}
	return (result);
}

int	count_size(int	n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n *= -1;;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoi(int num)
{
	char		*dest;
	int			count;
	int			i;
	long int	n;

	n = num;
	count = count_size(n);
	i = 0;
	if (n < 0 || count == 0)
		count++;
	if (!(dest = ft_strnew(count)))
		return (NULL);
	if (n < 0)
	{
		n *= -1;;
		dest[0] = '-';
		i++;
	}
	dest[count] = '\0';
	while (count > i)
	{
		count--;
		dest[count] = (n % 10) + '0';
		n /= 10;
	}
	return (dest);
}
