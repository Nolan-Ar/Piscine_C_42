#include "ft_utils.h"
#include "ft_utils_input.h"
#include <stdlib.h>

void    free_list(t_dict **list)
{
        t_dict  *current;
        t_dict  *next_node;

        if (!list || !*list)
                return ;
        current = *list;
        while (current != NULL)
        {
                next_node = current->next;
                if (current->content != NULL)
                        free(current->content);
                if (current->key != NULL)
                        free(current->key);
                free(current);
                current = next_node;
        }
        *list = NULL;
	free(list);
}


char	*extract_content(char *src)
{
	char	*dest;
	int		i;
	int		j;
	int		len;

	i = 0;
	while (src[i] != ':' && src[i] != '\0')
		i++;
	if (src[i] == ':')
		i++;
	while (src[i] == ' ')
		i++;
	j = i;
	while (src[j] != '\n' && src[j] != '\0')
		j++;
	len = j - i;
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	j = 0;
	while (src[i] != '\n' && src[i] != '\0')
		dest[j++] = src[i++];
	dest[j] = '\0';
	return (dest);
}

t_dict  *ft_create_elem(char *content, char *key)
{
        t_dict  *elem;

        elem = (t_dict *)malloc(sizeof(t_dict));
        if (elem == NULL)
                return (NULL);
        elem->content = content;
	elem->key = key;
        elem->next = NULL;
        return (elem);
}

int	push_dict_list(t_dict **list, char **dict, char **key_ring)
{
	t_dict	*current;
	int		i;

	*list = ft_create_elem(extract_content(dict[0]), ft_strdump(key_ring[0], ft_strlen(key_ring[0])));
	i = 1;
        if (!*list)
                return (1);
	current = *list;
        while (dict[i] != NULL)
        {
                current->next = ft_create_elem(extract_content(dict[i]), ft_strdump(key_ring[i], ft_strlen(key_ring[i])));
                if (!current->next)
                {
                        free_list(list);
                        return (1);
                }
                current = current->next;
		i++;
        }
	return (0);
}

t_dict	**create_list_dict(char **dict, char **key_ring, int size)
{
	t_dict	**list_dict;

	if (size <= 0)
		return (NULL);
	list_dict = malloc(sizeof(t_dict *) * (size + 1));
	if (!list_dict)
		return (NULL);
	if (push_dict_list(list_dict, dict, key_ring) != 0)
	{
		free_list(list_dict);
		return (NULL);
	}
	list_dict[size] = NULL;
	return (list_dict);
}
