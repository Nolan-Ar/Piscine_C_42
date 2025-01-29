#ifndef FT_PARSE_INPUT_H
# define FT_PARSE_INPUT_H

char    **parse_input(char *src);
void    process_units(char **parse, char *dest, int *i, int *j, int len);
void    process_tens(char **parse, char *dest, int *i, int *j, int len);
void    process_hundreds(char **parse, char *dest, int *i, int *j);

#endif
