#include "ft_utils.h"
#include "parse_dictionary.h"
#include <stdlib.h>


int     dict_verif_key(char *dict, char *src)
{
        int     	i;

        (void)src;
        i = 0;
        while (dict[i] >= '0' && dict[i] <= '9')
                i++;
        while (dict[i] != ':')
        {
                if (dict[i] != ' ')
                        return (1);
                i++;
        }
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
    while (dict[i] != '\n' && dict[i] != '\0')
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
