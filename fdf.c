#include "fdf.h"

int     key_hook(int keycode, t_win *param)
{
    if (keycode == 53 && param)
        exit (0);
    return (0);
}

void    fdf(int **tab, t_size size)
{
    t_win   ptr;

    ptr.mlx = mlx_init();
    ptr.win = mlx_new_window(ptr.mlx, 1000, 1000, "MY_FDF");
    draw_map(tab, size, &ptr);
    mlx_key_hook(ptr.win, key_hook, (void *)&ptr);
    mlx_loop(ptr.mlx);
    tab = 0;
    size.x = 0;
}

