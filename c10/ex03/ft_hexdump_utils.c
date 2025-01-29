#include "ft_hexdump.h"

void    print_hex(unsigned char c)
{
    char *hex = "0123456789abcdef";
    write(1, &hex[c / 16], 1);
    write(1, &hex[c % 16], 1);
}

void    print_address(unsigned int address)
{
    char hex_address[9];
    int i = 7;
    while (i >= 0)
    {
        hex_address[i] = "0123456789abcdef"[address % 16];
        address /= 16;
        i--;
    }
    hex_address[8] = '\0';
    write(1, hex_address, 8);
}

void    print_buffer_hex(unsigned char *buffer, int size)
{
    int i = 0;
    while (i < size)
    {
        print_hex(buffer[i]);
        if (i % 2 == 1)
            write(1, " ", 1);
        i++;
    }
    while (i < BUFFER_SIZE)
    {
        write(1, "  ", 2);
        if (i % 2 == 1)
            write(1, " ", 1);
        i++;
    }
}

void    print_buffer_ascii(unsigned char *buffer, int size)
{
    int i = 0;
    while (i < size)
    {
        if (buffer[i] >= 32 && buffer[i] <= 126)
            write(1, &buffer[i], 1);
        else
            write(1, ".", 1);
        i++;
    }
}

