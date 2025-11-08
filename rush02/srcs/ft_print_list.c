#include <stdlib.h>
#include "ft_utils.h"
#include "ft_utils_convert.h"
#include "ft_struct_dict.h"
#include "parse_dictionary.h"


int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void     print_ponctuation(int index, char **parse, char *content)
{
        int     i;

        if (ft_strcmp(parse[index], "0") == 0)
                return ;
        ft_putstr(content);
        if (parse[index + 1])
        {
                i = (ft_atoi(parse[index]) + ft_atoi(parse[index + 1]));
                if (i > 20 && i < 100 && i % 10 != 0)
                {
                        ft_putstr("-");
                        return ;
                }
        }
        if (ft_strcmp(parse[index], "100") == 0 && parse[index + 1] != NULL)
	{
                ft_putstr(" ");
		return ;
	}
	if (parse[index + 1] != NULL)
		ft_putstr(" ");
}

void	print_list(t_dict **list, char **parse, int index, int (*cmp)(char *s1, char *s2))
{
	t_dict	*current;

	if (!list || !*list)
		return ;
	current = *list;
	while (current != NULL)
	{
		if ((cmp)(current->key, parse[index]) == 0)
		{
			print_ponctuation(index, parse, current->content);
		}
		current = current->next;
	}
}

t_dict	**init_list(char *src)
{
	t_dict	**list;
	char		**dict;
	int	len;

	len = compt_colon(src);
	dict = 	parse_dictionary(src);
	if (!dict)
		return (NULL);
	list = create_list_dict(dict, len);
	free_tab(dict, len);
	return (list);
}
