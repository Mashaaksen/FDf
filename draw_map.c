#include "fdf.h"

t_coord trans(t_coord origin, t_size size)
{
    int x;
    int y;
    int i;
    t_coord new;

    i = 0;
    x = 0;
    y = 0;
    size.beta = (M_PI * 35) / 180;
    size.alpha = (M_PI * 45) / 180;
    new.tab_x = (int *)malloc(sizeof(int) * size.x * size.y);
    new.tab_y = (int *)malloc(sizeof(int) * size.x * size.y);
    while (i < size.x * size.y)
    {
        if (x == size.x)
        {
            x = 0;
            y++;
        }
        new.tab_y[i] =(int)round(-origin.tab_x[x] * cos(size.beta)
                                 - origin.tab_z[i] * sin(size.beta));
        new.tab_x[i] =(int)round(origin.tab_x[x] * cos(size.alpha)
                         * sin(size.alpha) + origin.tab_y[y] * cos(size.alpha)
                        - origin.tab_z[i] * sin(size.alpha) * cos(size.beta));
        x++;
        i++;
    }
    return (new);
}

void    draw_line(t_coord new, t_size size, t_win *ptr)
{
    int res;
    int i;

    res = 0;
    i = 0;
    while (i < (size.x * size.y) - 1)
    {
        res = ptr->prop;
        new.x = new.tab_x[i];
        new.y = new.tab_y[i];
        new.ret_x = (new.tab_x[i + 1] - new.tab_x[i]);
        new.ret_y = (new.tab_y[i + 1] - new.tab_y[i]);
        while (res-- > 0)
        {
            mlx_pixel_put(ptr->mlx, ptr->win, new.x + ptr->place, new.y + ptr->place, 0xFFFFFF);
            new.x += new.ret_x;
            new.y += new.ret_y;
        }
        i++;
    }
}

void    draw_map(t_coord origin, t_size size, t_win *ptr)
{
    t_coord new;

    new = trans(origin, size);
    draw_line(new, size, ptr);
}