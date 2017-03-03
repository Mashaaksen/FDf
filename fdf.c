#include "fdf.h"

int     key_hook(int keycode, t_win *param)
{
    if (keycode == 53 && param)
        exit (0);
    else if (keycode == 123)
        param->place += 50;
   /* else if (keycode == 124)

    else if (keycode == 125)

    else if (keycode == 126)

    else if (keycode == 78)

    else if (keycode == 69)
*/
    return (0);
}

void    fdf(t_coord origin, t_size size)
{
    t_win   ptr;

    ptr.mlx = mlx_init();
    ptr.win = mlx_new_window(ptr.mlx, 1000, 1000, "MY_FDF");
    ptr.place = 400;
    ptr.prop = 10;
    draw_map(origin, size, &ptr);
    mlx_key_hook(ptr.win, key_hook, (void *)&ptr);
    mlx_loop(ptr.mlx);
}

