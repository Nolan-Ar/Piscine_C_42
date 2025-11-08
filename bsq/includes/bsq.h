#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_map
{
    int   rows;
    int   cols;
    char  empty;
    char  obst;
    char  full;
    char *grid; /* length rows*cols */
}   t_map;

/* utils.c */
int     ft_strlen(const char *s);
void    ft_putstr(int fd, const char *s);
void    ft_putchar(int fd, char c);
int     ft_atoi_nonneg(const char *s, int len, int *out);
void   *ft_realloc(void *ptr, size_t old_sz, size_t new_sz);

/* reader.c */
int     read_all_fd(int fd, char **out_buf, int *out_len);

/* parser.c */
int     parse_buffer_to_map(const char *buf, int len, t_map *out);
void    free_map(t_map *m);

/* solve.c */
int     solve_bsq(t_map *m);

/* output.c */
void    print_map(const t_map *m);

#endif

