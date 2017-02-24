#include "fdf.h"

void    draw_map(int  **tab, t_size size, t_win *ptr)
{
    int i;
    int j;
    double alpha = (M_PI * 135) / 180;
    double beta = (M_PI * 41.5) / 180;
    double x;
    double y;

    i = 0;
    while (i < size.y)
    {
        j = 0;
        while (j < size.x)
        {
            x = j * cos(beta) + tab[i][j] * sin(beta) + 400;
            y = j * sin(alpha) * cos(alpha) + i * cos(alpha) - tab[i][j] * sin(alpha) * cos(beta) + 400;
            mlx_pixel_put(ptr->mlx, ptr->win, (int)round(x), (int)round(y), 0xFFFFFF);
            j++;
        }
        i++;
    }
}