#ifndef FT_STRUCT_DICT_H
# define FT_STRUCT_DICT_H

# include "ft_utils.h"

void    free_list(t_dict **list);
char    *extract_content(char *src);
char    *extract_key(char *src);
int     	push_dict_list(t_dict **list, char **dict);
t_dict  	*ft_create_elem(char *content, char *key);
t_dict  	**create_list_dict(char **dict, int size);

#endif
