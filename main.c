#include "fdf.h"

int     main(int ac, char **av)
{
    if (ac > 1)
    {
        t_size size;
        t_coord origin;

        origin = or_file(av[1], &size);
        fdf(origin, size);
    }
    return (0);
}