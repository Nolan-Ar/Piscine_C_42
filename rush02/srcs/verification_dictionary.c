#include "ft_utils.h"
#include "parse_dictionary.h"
#include "ft_keys_ring.h"
#include <stdlib.h>


int	strcmp_keys(char *dict, char *keys)
{
	int	i;

	i = 0;
	while (keys[i])
	{
		if (keys[i] != dict[i])
			return(1);
		i++;
	}
	return (0);
}

int	true_keys(char *dict, char *src)
{
	char	**keys;
	int		i;
	int		len;

	i = 0;
	len = compt_colon(src);
	keys = create_keys_ring(len);
	if (!keys)
		return (1);
	while (keys[i] != NULL)
	{
		if (strcmp_keys(dict, keys[i]) == 0)
		{
			free_tab(keys, len);
			return (0);
		}
		i++;
	}
	free_tab(keys, len);
	return (1);
}

int     dict_verif_key(char *dict, char *src)
{
        int     	i;

        i = 0;
        while (dict[i] >= '0' && dict[i] <= '9')
        {
		if (!(dict[i] >= '0' && dict[i] <= '9'))
			return (1);
                i++;
        }
	while (dict[i] != ':')
	{
		if (dict[i] != ' ')
			return (1);
		i++;
	}
	if(true_keys(dict, src) == 1)
		return (1);
        return (0);
}

int	dict_verif_content(char *dict)
{
	int	i;

	i = 0;
	while (dict[i] != ':')
		i++;
	i += 1;
	while (dict[i] == ' ')
		i++;
	while (dict[i] != '\n')
	{
		if ((dict[i] > 0 && dict[i] < 32) || dict[i]  > 126)
			return (1);
		i++;
	}
	return (0);
}

int	verif_dict(char **dict, char *src)
{
	int	i;

	i = 0;
	while (dict[i] != NULL)
	{
		if (dict_verif_key(dict[i], src) != 0)
		{
			ft_puterr("Dict Error\n");
			return (1);
		}
		if (dict_verif_content(dict[i]) != 0)
		{
			ft_puterr("Dict Error\n");
			return (1);
		}
		i++;
	}
	return (0);
}
