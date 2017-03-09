#include "fdf.h"

double    *ox(double *tab, double alpha)
{
    double y;
    double z;

    alpha = (M_PI * alpha) / 180;
    y = tab[1];
    z = -tab[2];
    tab[1] = y * cos(alpha) + z * sin(alpha);
    tab[2] = z * cos(alpha) - y * sin(alpha);
    return (tab);
}

double    *oy(double *tab, double beta)
{
    double x;
    double z;

    beta = (M_PI * beta) / 180;
    x = tab[0];
    z = -tab[2];
    tab[0] = x * cos(beta) - z * sin(beta);
    tab[2] = z * cos(beta) + x * sin(beta);
    return (tab);
}

double    *oz(double *tab, double gama)
{
    double x;
    double y;

    gama = (M_PI * gama) / 180;
    x = tab[0];
    y = tab[1];
    tab[0] = x * cos(gama) + y * sin(gama);
    tab[1] = y * cos(gama) - x * sin(gama);
    return (tab);
}

double     *matrix(t_win *ptr, int y, int x)
{
    double *t_n;
    double *tab;

    t_n = (double *)malloc(sizeof(double) * 2);
    tab = (double *)malloc(sizeof(double) * 3);
    tab[0] = ptr->origin[y][x][0];
    tab[1] = ptr->origin[y][x][1];
    tab[2] = ptr->origin[y][x][2];
    tab = oz(tab, ptr->gama);
    tab = ox(tab, ptr->alpha);
    tab = oy(tab, ptr->beta);
    t_n[0] = tab[0] * ptr->prop + ptr->left;
    t_n[1] = tab[1] * ptr->prop + ptr->high;
    return (t_n);
}

t_win   *trans(t_win *ptr)
{
    ptr->y = 0;
    ptr->new = (double ***)malloc(sizeof(double **) * ptr->size_y);
    while (ptr->y < ptr->size_y)
    {
        ptr->x = 0;
        ptr->new[ptr->y] = (double **)malloc(sizeof(double *) * ptr->size_x);
        while (ptr->x < ptr->size_x)
        {
            ptr->new[ptr->y][ptr->x] = (double *)malloc(sizeof(double) * 2);
            ptr->x++;
        }
        ptr->y++;
    }
    ptr->y = 0;
    while (ptr->y < ptr->size_y)
    {
        ptr->x = 0;
        while (ptr->x < ptr->size_x)
        {
            ptr->new[ptr->y][ptr->x] = matrix(ptr, ptr->y, ptr->x);
            ptr->x++;
        }
        ptr->y++;
    }
    return (ptr);
}

void drawLine(int x1, int y1, int x2, int y2, t_win *ptr) {
    const int deltaX = abs(x2 - x1);
    const int deltaY = abs(y2 - y1);
    const int signX = x1 < x2 ? 1 : -1;
    const int signY = y1 < y2 ? 1 : -1;
    //
    int error = deltaX - deltaY;
    //
    mlx_pixel_put(ptr->mlx, ptr->win, x2, y2, 0xFFFFFF);
    while(x1 != x2 || y1 != y2)
    {
        mlx_pixel_put(ptr->mlx, ptr->win, x1, y1, 0xFFFFFF);
        const int error2 = error * 2;
        //
        if(error2 > -deltaY)
        {
            error -= deltaY;
            x1 += signX;
        }
        if(error2 < deltaX)
        {
            error += deltaX;
            y1 += signY;
        }
    }

}

void   draw_map(t_win *ptr)
{
    ptr = trans(ptr);
    ptr->y = 0;
   while (ptr->y < ptr->size_y - 1)
     {
    ptr->x = 0;
        while (ptr->x < ptr->size_x - 1)
       {
           drawLine((int) (ptr->new[ptr->y][ptr->x][0]), (int)( ptr->new[ptr->y][ptr->x][1]),
                     (int)( ptr->new[ptr->y][ptr->x + 1][0]), (int)(ptr->new[ptr->y][ptr->x + 1][1]), ptr);
            drawLine((int)( ptr->new[ptr->y][ptr->x][0]), (int)( ptr->new[ptr->y][ptr->x][1]), (int)( ptr->new[ptr->y + 1][ptr->x][0]), (int)(ptr->new[ptr->y + 1][ptr->x][1]), ptr);
           ptr->x++;
        }
         ptr->y++;
    }
    ptr->y = 0;
    ptr->x = ptr->size_x - 1;
    while (ptr->y < ptr->size_y - 1)
    {
        drawLine((int) ptr->new[ptr->y][ptr->x][0], (int) ptr->new[ptr->y][ptr->x][1],
                 (int) ptr->new[ptr->y + 1][ptr->x][0], (int) ptr->new[ptr->y + 1][ptr->x][1], ptr);
        ptr->y++;
    }
    ptr->x = 0;
    ptr->y = ptr->size_y - 1;
    while (ptr->x < ptr->size_x - 1)
    {
        drawLine((int) ptr->new[ptr->y][ptr->x][0], (int) ptr->new[ptr->y][ptr->x][1],
               (int) ptr->new[ptr->y][ptr->x + 1][0], (int) ptr->new[ptr->y][ptr->x + 1][1], ptr);
        ptr->x++;
    }
}