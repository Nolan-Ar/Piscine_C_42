#include <unistd.h>
#include <stdlib.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_puterr(char *str)
{
	while (*str)
		write(2, str++, 1);
}

char	*ft_strcat(char *dest, const char *src)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dest[j])
		j++;
	while (src[i])
	{
		dest[j + i] = src[i];
		i++;
	}
	dest[j + i] = '\0';
	return dest;
}

void	free_tab(char **tab, int size)
{
	int	i;

	i = 0;
	if (tab == NULL)
		return ;
	while (i <= size)
	{
		if (tab[i])
			free(tab[i]);
		i++;
	}
	free(tab);
}

char	*substring_copy(char *str, int start, int end)
{
	char	*dest;
	int		i;
	int		len;

	i = 0;
	len = end - start;
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	while (i < len)
	{
		dest[i] = str[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
