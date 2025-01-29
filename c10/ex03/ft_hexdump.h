#ifndef FT_HEXDUMP_H
# define FT_HEXDUMP_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>

# define BUFFER_SIZE 16

void    print_hex(unsigned char c);
void    print_address(unsigned int address);
void    print_buffer_hex(unsigned char *buffer, int size);
void    print_buffer_ascii(unsigned char *buffer, int size);
void    ft_hexdump(int fd);

#endif

