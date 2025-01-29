#ifndef FT_PRINT_LIST_H
# define FT_PRINT_LIST_H

# include "ft_utils.h"

void	print_list(t_dict **list, char **parse, int index, int (*cmp)(char *s1, char *s2));
int		ft_strcmp(char *s1, char *s2);
t_dict  **init_list(char *src);

#endif
