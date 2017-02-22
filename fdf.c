#include "fdf.h"

int     key_hook(int keycode, t_win *param)
{
    if (keycode == 53 && param)
        exit (0);
    return (0);
}

void    init(t_win *ptr)
{
    ptr->mlx = mlx_init();
    ptr->win = mlx_new_window(ptr->mlx, 1000, 1000, "MY_FDF");
    ptr->img = mlx_new_image(ptr->mlx, 700, 700);
    ptr->str = mlx_get_data_addr(ptr->img, &ptr->bit_p_pix, &ptr->ls,
                                 &ptr->endion);
}

void    fdf(int **tab, t_size size)
{
    t_win   ptr;

    init(&ptr);
    draw_map(tab, size, &ptr);
    mlx_put_image_to_window(ptr.mlx, ptr.win, ptr.img, 350, 350);
    mlx_key_hook(ptr.win, key_hook, (void *)&ptr);
    mlx_loop(ptr.mlx);
}

