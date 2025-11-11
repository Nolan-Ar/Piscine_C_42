/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yourusername <yourusername@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 10:00:00 by yourusername     #+#    #+#              */
/*   Updated: 2024/05/27 10:00:00 by yourusername    ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	nbr_split(char *str, char *charset)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 1;
	while (str[i])
	{
		j = 0;
		while (charset[j] && charset[j] == str[i])
		{
			i++;
			j++;
		}
		if (charset[j] == '\0')
			count++;
		i++;
	}
	return (count);
}

int	s_spl(int index, char *str, char *charset)
{
	int	i;
	int	j;
	int	size;

	i = index;
	while (str[i])
	{
		j = 0;
		size = 0;
		while (charset[j] && charset[j] == str[i])
		{
			size = i;
			i++;
			j++;
		}
		if (charset[j] == '\0')
			i = ft_strlen(charset) - 1;
		i++;
	}
	if (size == 0)
		return (i - index + 1);
	return (size - (ft_strlen(charset) + index) + 1);
}

int	strscpy(int index, char *dest, char *str, char *charset)
{
	int	i;
	int	j;
	int	end;

	i = index;
	j = 0;
	end = s_spl(index, dest, str) + index;
	if (end > ft_strlen(str))
		end = ft_strlen(str) + 1;
	while (i < end)
	{
		dest[j] = str[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	if (str[i] == '\0')
		return (i);
	return (i + ft_strlen(charset));
}

char	**ft_split(char *str, char *charset)
{
	char	**split;
	int		i;
	int		j;

	i = 0;
	split = (char **)malloc(sizeof(char *) * nbr_split(str, charset) + 1);
	if (split == NULL)
		return (NULL);
	while (j < nbr_split(str, charset))
	{
		split[j] = (char *)malloc(sizeof(char) * (s_spl(i, str, charset) + 1));
		if (split[j] == NULL)
			return (NULL);
		i = strscpy(i, split[j], str, charset);
		j++;
	}
	split[j] = NULL;
	return (split);
}
