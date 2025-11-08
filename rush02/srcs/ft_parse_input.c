#include <stdlib.h>
#include "ft_utils_convert.h"
#include "ft_utils_input.h"
#include "ft_utils_parse.h"

void	process_hundreds(char **parse, char *dest, int *i, int *j)
{
	parse[(*j)++] = ft_itoi(dest[*i] - '0');
	parse[(*j)++] = ft_itoi(100);
}

void	process_tens(char **parse, char *dest, int *i, int *j, int total_len)
{
	if (dest[*i] == '1')
	{
		if (*i + 1 < total_len)
		{
			parse[(*j)++] = ft_itoi(ft_atoi_char(dest[*i], dest[*i + 1]));
			(*i)++;
		}
		if (dest[*i + 1] != '\0')
			parse[(*j)++] = write_higt_numbers(total_len - (*i) - 1);
	}
	else
	{
		parse[(*j)++] = ft_itoi((dest[*i] - '0') * 10);
	}
}

void	process_units(char **parse, char *dest, int *i, int *j, int total_len)
{
	parse[(*j)++] = ft_itoi(dest[*i] - '0');
	if (dest[*i + 1] != '\0')
		parse[(*j)++] = write_higt_numbers(total_len - (*i) - 1);	
}



char	**parse_input(char *src)
{
	char	**parse;
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	dest = normalize_input(src);
	if (!dest)
		return (NULL);
	/* Upper bound allocation: each digit can yield up to 2 tokens */
	parse = malloc(sizeof(char *) * ((ft_strlen(dest) * 2) + 1));
	if (!parse)
		return (free(dest), NULL);
	while (dest[i] && dest[i] == '0')
		i++;
	while (dest[i])
	{
		while (dest[i] == '0')
			i++;
		if (i % 3 == 0)
			process_hundreds(parse, dest, &i, &j);
		if (i % 3 == 1)
			process_tens(parse, dest, &i, &j, ft_strlen(dest));
		else if (i % 3 == 2)
			process_units(parse, dest, &i, &j, ft_strlen(dest));
		i++;
	}
	parse[j] = NULL;
	free(dest);
	return (parse);
}
