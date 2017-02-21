#include "fdf.h"

int     main(int ac, char **av)
{
    if (ac > 1)
    {
        t_size *size;
        int     **arr;

        size = (t_size *)malloc(sizeof(t_size));
        arr = or_file(av[1], size);
    }
    return (0);
}