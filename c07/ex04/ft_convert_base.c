#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_verif_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(base) <= 1)
		return (0);
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+' || base[i] <= 32 || base[i] > 126)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

long int	ft_str_nbr_base(char *nbr, char *base_from)
{
	long int	result;
	int			i;
	int			j;
	int			neg;

	i = 0;
	result = 0;
	neg = 1;
	while (nbr[i] == ' ' || (nbr[i] >= 9 && nbr[i] <= 13) ||
		(nbr[i] == '-' && (neg *= -1)) || nbr[i] == '+')
		i++;
	while (nbr[i])
	{
		j = 0;
		while (base_from[j] && base_from[j] != nbr[i])
			j++;
		if (base_from[j] == '\0')
			break ;
		result = result * ft_strlen(base_from) + j;
		i++;
	}
	return (result * neg);
}

void	ft_convert_recur(long int nbr, char *base_to, char *result, int *index)
{
	int	base_len;

	base_len = ft_strlen(base_to);
	if (nbr >= base_len)
		ft_convert_recur(nbr / base_len, base_to, result, index);
	result[(*index)++] = base_to[nbr % base_len];
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long int	l_nbr;
	char		*result;
	int			index;

	if (!ft_verif_base(base_from) || !ft_verif_base(base_to))
		return (NULL);
	l_nbr = ft_str_nbr_base(nbr, base_from);
	result = malloc(sizeof(char) * 34);
	if (!result)
		return (NULL);
	index = 0;
	if (l_nbr < 0)
	{
		result[index++] = '-';
		l_nbr *= -1;
	}
	ft_convert_recur(l_nbr, base_to, result, &index);
	result[index] = '\0';
	return (result);
}
