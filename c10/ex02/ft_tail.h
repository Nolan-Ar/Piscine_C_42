#ifndef FT_TAIL_H
# define FT_TAIL_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include <libgen.h>

void	ft_tail(int fd, int n, int use_bytes);
int		ft_atoi(const char *str);
void	ft_putstr_fd(int fd, const char *str);
void	ft_puterr(const char *msg);

#endif

