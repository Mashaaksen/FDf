#include "fdf.h"

int     main(int ac, char **av)
{
        if (ac > 1)
    {
        t_win ptr;

        ptr = or_file(av[1]);
        fdf(ptr);
    }
    return (0);
}