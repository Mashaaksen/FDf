#include "fdf.h"

int     main(int ac, char **av)
{
    if (ac > 1)
    {
        t_size size;
        int     **arr;

        arr = or_file(av[1], &size);
        fdf(arr, size);
    }
    return (0);
}