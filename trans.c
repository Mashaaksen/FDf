#include "fdf.h"

int     *new_tab(int **tab, int coord, double size, double x, double y)
{
    int *n_tab;
    int i;
    int j;
    int p;
    int min;

    min = 0;
    p = 0;
    i = -1;
    n_tab = (int *)malloc((size_t) (sizeof(int) * size));
    if (coord == 1)
    {
        while (i++ < y && size-- > 0)
        {
            j = -1;
            while (j++ < x && size-- > 0)
            {
                n_tab[p] = (int)round((1 / sqrt(6.0)) * (sqrt(3.0) * j - sqrt(3.0) * tab[i][j]));
                n_tab[p] < 0 ? min = n_tab[p] * (-1) : 0;
                n_tab[p] += min;
                p++;
            }
        }
    }
    else if (coord == 2)
    {
        while (i++ < y && size-- > 0)
        {
            j = -1;
            while (j++ < x && size-- > 0)
            {
                n_tab[p++] = (int)round((1 / sqrt(6.0)) * (1 * j  + 2 * i + 1 * tab[i][j]));
                n_tab[p] < 0 ? min = n_tab[p] * (-1) : 0;
                n_tab[p] += min;
                p++;
            }
        }
    }
    else if (coord == 3)
    {
        while (i++ < y && size-- > 0)
        {
            j = -1;
            while (j++ < x && size-- > 0)
            {
                n_tab[p++] = (int)round((1 / sqrt(6.0)) * (sqrt(2.0) * j - sqrt(2.0) * i + sqrt(2.0) * tab[i][j]));
                n_tab[p] < 0 ? min = n_tab[p] * (-1) : 0;
                n_tab[p] += min;
                p++;
            }
        }
    }
    return (n_tab);
}

t_ncoord    *trans(int **tab, t_size size)
{
    t_ncoord *n_tab;

    n_tab = (t_ncoord *)malloc(sizeof(t_ncoord));
    n_tab->tab_x = new_tab(tab, 1, size.x * size.y, size.x, size.y);
    n_tab->tab_y = new_tab(tab, 2, size.x * size.y, size.x, size.y);
    n_tab->tab_y = new_tab(tab, 3, size.x * size.y, size.x, size.y);
    return (n_tab);
}