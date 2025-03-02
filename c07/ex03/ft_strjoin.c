#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i])
		i++;
	j = 0;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

int	calculate_total_length(int size, char **strs, char *sep)
{
	int	total_length;
	int	i;

	if (size == 0)
		return (1);
	total_length = 0;
	i = 0;
	while (i < size)
	{
		total_length += ft_strlen(strs[i]);
		i++;
	}
	total_length += ft_strlen(sep) * (size - 1);
	return (total_length + 1);
}

char	*assemble_strings(int size, char **strs, char *sep, char *dest)
{
	int	i;

	dest[0] = '\0';
	i = 0;
	while (i < size)
	{
		ft_strcat(dest, strs[i]);
		if (i < size - 1)
			ft_strcat(dest, sep);
		i++;
	}
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*dest;
	int		total_length;

	total_length = calculate_total_length(size, strs, sep);
	dest = malloc(sizeof(char) * total_length);
	if (!dest)
		return (NULL);
	if (size == 0)
	{
		dest[0] = '\0';
		return (dest);
	}
	return (assemble_strings(size, strs, sep, dest));
}
