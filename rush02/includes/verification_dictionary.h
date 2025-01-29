#ifndef VERIFICATION_DICTIONARY_H
# define VERIFICATION_DICTIONARY_H

int     strcmp_keys(char *dict, char *keys);
int     true_keys(char *dict, char *src);
int     dict_verif_key(char *dict, char *src);
int     dict_verif_content(char *dict);
int     verif_dict(char **dict, char *src);

#endif
