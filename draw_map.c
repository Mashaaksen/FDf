#include "fdf.h"

int     **new_tab(int **tab)
{
    int **n_tab;


    return (n_tab);
}

void    draw_pix(t_win  *ptr, int x, int y)
{
    ptr->str[x + y * ptr->ls + 0] = (char) 255;
    ptr->str[x + y * ptr->ls + 1] = (char) 255;
    ptr->str[x + y * ptr->ls + 2] = (char) 255;
}

void    draw_map(int  **tab, t_size size, t_win *ptr)
{
    int    **n_tab;

    n_tab = new_tab(tab);
    size.x = 0;
    tab = 0;
}