#ifndef FT_UTILS_H
# define FT_UTILS_H

# define BUFFER 4096

typedef struct	s_dict 
{
	struct s_dict	*next;
	char			*content;
	char			*key;
}	t_dict;

void    ft_putstr(char *str);
void    ft_puterr(char *str);
void    free_tab(char **tab, int size);
char    *ft_strcat(char *dest, const char *src);
char    *substring_copy(char *str, int start, int end);

#endif
