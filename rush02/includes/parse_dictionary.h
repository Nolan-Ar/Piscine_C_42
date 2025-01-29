#ifndef PARSE_DICTIONARY_H
# define PARSE_DICTIONARY_H

void    write_dictionary(char **dict, char *str);
char    **parse_dictionary(char *str);
char    *read_files(char *filename);
int     	compt_colon(char *str);
long    		get_file_size_custom(const char *filename);

#endif
