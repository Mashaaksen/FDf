#include "fdf.h"

void    hook(int keycode, t_win *param)
{
    if (keycode == 2)
        param->gama -= 5;
    else if (keycode == 1)
        param->beta -= 5;
    else if (keycode == 0)
        param->alpha -= 5;
    else if (keycode == 12)
        param->alpha += 5;
    else if (keycode == 13)
        param->beta += 5;
    else if (keycode == 14)
        param->gama += 5;
    else if (keycode == 69)
        param->prop += 5;
    else if (keycode == 78)
        param->prop -= 5;
    else if (keycode == 126)
        param->high -= 50;
    else if (keycode == 125)
        param->high += 50;
    else if (keycode == 123)
        param->left -= 100;
    else if (keycode == 124)
        param->left += 100;
}

int     key_hook(int keycode, t_win *param)
{
    if (keycode == 53 && param)
        exit (0);
    else if (keycode == 2 || keycode == 1 || keycode == 0 || keycode == 14 ||
        keycode == 13 || keycode == 12 || keycode == 69 || keycode == 78 ||
          keycode == 125 || keycode == 126 || keycode == 123 || keycode == 124)
    {
        mlx_clear_window(param->mlx, param->win);
        hook(keycode, param);
        draw_map(param);
    }
    return (0);
}

void    fdf(t_win ptr)
{
    ptr.mlx = mlx_init();
    ptr.win = mlx_new_window(ptr.mlx, 1000, 1000, "MY_FDF");
    ptr.left = 400;
    ptr.high = 400;
    ptr.prop = 2;
    ptr.alpha = 48.5;
    ptr.beta = 0;
    ptr.gama = 315;
    draw_map(&ptr);
    mlx_key_hook(ptr.win, key_hook, (void *)&ptr);
    mlx_loop(ptr.mlx);
}

