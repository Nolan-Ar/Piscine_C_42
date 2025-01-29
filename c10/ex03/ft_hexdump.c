#include "ft_hexdump.h"

void    ft_hexdump(int fd)
{
    unsigned char buffer[BUFFER_SIZE];
    unsigned int  address = 0;
    int           bytes_read;

    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        print_address(address);
        write(1, "  ", 2);
        print_buffer_hex(buffer, bytes_read);
        write(1, " |", 2);
        print_buffer_ascii(buffer, bytes_read);
        write(1, "|\n", 2);
        address += bytes_read;
    }
}

int     main(int argc, char **argv)
{
    int fd;
    int i;

    if (argc < 2)
    {
        write(2, "Usage: ./ft_hexdump file\n", 25);
        return (1);
    }
    i = 1;
    while (i < argc)
    {
        fd = open(argv[i], O_RDONLY);
        if (fd == -1)
        {
            write(2, strerror(errno), strlen(strerror(errno)));
            write(2, "\n", 1);
            return (1);
        }
        ft_hexdump(fd);
        close(fd);
        i++;
    }
    return (0);
}

