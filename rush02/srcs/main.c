#include "ft_start_prog.h"
#include "parse_dictionary.h"
#include "ft_utils.h"
#include "ft_utils_input.h"
#include <stdlib.h>

int     main(int argc, char **argv)
{
        char    *src;

        src = NULL;

        if (argc == 2)
        {
                if (ft_str_is_numeric(argv[1]) != 0)
                {
                        ft_puterr("Error\n");
                        return (1);
                }
                src = read_files("numbers.dict");
                if (!src)
                {
                        ft_puterr("Dict Error\n");
                        return (1);
                }
                ft_start_prog(src, argv[1]);
        }
        else if (argc == 3)
        {
                if (ft_str_is_numeric(argv[2]) != 0)
                {
                        ft_puterr("Error\n");
                        return (1);
                }
                src = read_files(argv[1]);
                if (!src)
                {
                        ft_puterr("Dict Error\n");
                        return (1);
                }
                ft_start_prog(src, argv[2]);
        }
        ft_putstr("\n");
        if (src)
                free(src);
        return (0);
}
