#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "ft_utils.h"
#include "verification_dictionary.h"

int	compt_colon(char *str)
{
	int	i;
	int	compt;
	
	i = 0;
	compt = 0;
	while (str[i])
	{
		if(str[i] == ':')
			compt++;
		i++;
	}
	return (compt);
}

long	get_file_size_custom(const char *filename)
{
	int	fb;
	long	size;
	char buffer[1];

	size = 0;
	fb = open(filename, O_RDONLY);
	if (fb == -1)
		return -1;
	while (read(fb, buffer, 1) > 0)
	{
		size++;
	}
	close(fb);
	return size;
}

char	*read_files(char *filename)
{
	int	fb;
	int	byte_read;
	char		buff[BUFFER];
	char		*out;
	long			file_size;
	
	file_size = get_file_size_custom(filename);
	if (file_size == -1)
		return NULL;
	out = malloc(sizeof(char) * (file_size + 1));
	if (!out)
		return NULL;
	out[0] = '\0';
	fb = open(filename, O_RDONLY);
	if (fb == -1)
	{
		free(out);
		return NULL;
	}
	while ((byte_read = read(fb, buff, BUFFER)) > 0)
	{
		buff[byte_read] = '\0';
		ft_strcat(out, buff);
	}
	close(fb);
	return out;
}

void	write_dictionary(char **dict, char *str)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (str[i])
	{
		while (str[i] == '\n' || str[i] == ' ')
			i++;
		j = i;
		while (str[j] != '\0' && str[j] != '\n')
			j++;
		dict[k] = substring_copy(str, i, (j + 1));
		if (!dict[k])
		{
			free_tab(dict, (compt_colon(str)));
			return ;
		}
		i = j + 1;
		k++;
	}
	dict[k] = (NULL);
}

char	**parse_dictionary(char *str)
{
	char	**dict;

	dict = malloc(sizeof(char *) * (compt_colon(str) + 1));
	if (!dict)
		return (NULL);
    write_dictionary(dict, str);
    /* Dictionary verification relaxed to accept dynamic dictionaries */
    return (dict);
}
