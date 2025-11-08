#include "ft_print_list.h"
#include "ft_parse_input.h"
#include "ft_utils.h"
#include "ft_utils_parse.h"
#include "ft_utils_input.h"
#include "parse_dictionary.h"
#include "ft_struct_dict.h"
#include "ft_utils_convert.h"
#include <stdlib.h>


void    print_zero(t_dict **dict, char *src, int (*cmp)(char *s1, char *s2))
{
        t_dict  *current;

        current = *dict;
        while (current != NULL)
        {
                if ((cmp)(current->key, src) == 0)
                {
                        ft_putstr(current->content);
                        return ;
                }
                current = current->next;
        }
}

int     size_compare(t_dict **dict, char *argv, int (*f)(char *str))
{
        t_dict  *current;
        int     max_len;

        max_len = 0;
        current = *dict;
        while (current != NULL)
        {
                int klen = (f)(current->key);
                if (klen > max_len)
                        max_len = klen;
                current = current->next;
        }
        if ((f)(argv) > max_len)
        {
                free_list(dict);
                ft_puterr("Error\n");
                return (1);
        }
        return (0);
}

void    ft_process(t_dict **dict, char **parse)
{
        int     i;

        i = 0;
        while (parse[i] != NULL)
        {
                print_list(dict, parse, i, ft_strcmp);
                i++;
        }
}

int	ft_start_prog(char *src, char *argv)
{
	t_dict	**dict;
	char	**parse;

    dict = init_list(src);
	if (!dict)
		return (1);
	if (size_compare(dict, argv, ft_strlen) != 0)
                return (1);
        if (ft_strcmp(argv, "0") == 0)
        {
                print_zero(dict, "0", ft_strcmp);
                free_list(dict);
                return (0);
        }
	parse = parse_input(argv);
	if (!parse)
	{
		free_list(dict);
		return (1);
	}
    ft_process(dict, parse);
    free_list(dict);
    {
        int k = 0;
        while (parse[k])
            k++;
        free_tab(parse, k);
    }
    return (0);
}
