#include <stdlib.h>
#include "ft_utils_convert.h"
#include "ft_utils_input.h"
#include "ft_utils_parse.h"

void	process_hundreds(char **parse, char *dest, int *i, int *j)
{
	parse[(*j)++] = ft_itoi(dest[*i] - '0');
	parse[(*j)++] = ft_itoi(100);
}

void	process_tens(char **parse, char *dest, int *i, int *j, int len)
{
	if (dest[*i] == '1')
	{
		if (*i + 1 < len)
		{
			parse[(*j)++] = ft_itoi(ft_atoi_char(dest[*i], dest[*i + 1]));
			(*i)++;
		}
		if (*i + 1 && dest[*i + 1] != '\0')
			parse[(*j)++] = write_higt_numbers(len - (*i));
	}
	else
	{
		parse[(*j)++] = ft_itoi((dest[*i] - '0') * 10);
	}
}

void	process_units(char **parse, char *dest, int *i, int *j, int len)
{
	parse[(*j)++] = ft_itoi(dest[*i] - '0');
	if (dest[*i + 1] != '\0' && dest[*i + 1] != '\0')
		parse[(*j)++] = write_higt_numbers(len - (*i));	
}

#include <stdio.h>

char	**parse_input(char *src)
{
	char	**parse;
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	dest = normalize_input(src);
	printf("%i\n\n", size_absolute_input(src));
	parse = malloc(sizeof(char *) * (size_absolute_input(src) + 1));
	if (!dest || !parse)
		return (free(parse), free(dest), NULL);
	while (dest[i] && dest[i] == '0')
		i++;
	while (dest[i] && j < size_absolute_input(src))
	{
		while (dest[i] == '0')
			i++;
		if (i % 3 == 0)
			process_hundreds(parse, dest, &i, &j);
		if (i % 3 == 1)
			process_tens(parse, dest, &i, &j, size_absolute_input(dest));
		if (i % 3 == 2)
			process_units(parse, dest, &i, &j, size_absolute_input(dest));
		i++;
	}
	parse[j] = NULL;
	free(dest);
	return (parse);
}
