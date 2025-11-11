#include "bsq.h"

static int process_map_buffer(const char *buf, int len, int print_sep)
{
    t_map m;
    if (parse_buffer_to_map(buf, len, &m) != 0)
    {
        ft_putstr(2, "map error\n");
        if (print_sep) ft_putstr(1, "\n");
        return 1;
    }
    if (solve_bsq(&m) != 0)
    {
        free_map(&m);
        ft_putstr(2, "map error\n");
        if (print_sep) ft_putstr(1, "\n");
        return 1;
    }
    print_map(&m);
    if (print_sep) ft_putstr(1, "\n");
    free_map(&m);
    return 0;
}

int main(int argc, char **argv)
{
    int status;
    int i;
    int fd;
    char *buf;
    int len;

    status = 0;
    if (argc <= 1)
    {
        buf = NULL;
        len = 0;
        if (read_all_fd(0, &buf, &len) != 0)
            return (1);
        status |= process_map_buffer(buf, len, 0);
        free(buf);
        return (status ? 1 : 0);
    }
    i = 1;
    while (i < argc)
    {
        fd = open(argv[i], O_RDONLY);
        if (fd < 0)
        {
            ft_putstr(2, "map error\n");
            if (i < argc - 1)
                ft_putstr(1, "\n");
            status = 1;
            i++;
            continue;
        }
        buf = NULL;
        len = 0;
        if (read_all_fd(fd, &buf, &len) != 0)
        {
            close(fd);
            ft_putstr(2, "map error\n");
            if (i < argc - 1)
                ft_putstr(1, "\n");
            status = 1;
            i++;
            continue;
        }
        close(fd);
        status |= process_map_buffer(buf, len, (i < argc - 1));
        free(buf);
        i++;
    }
    return (status ? 1 : 0);
}
