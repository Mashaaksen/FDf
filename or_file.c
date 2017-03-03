#include "fdf.h"

int     arr_wid(void **arr)
{
      int i;

    i = 0;
    while (arr[i++] != '\0')
        ;
    return (i);
}

int     *arr_create(int size)
{
    int *tab;
    int i;

    i = 0;
    tab = (int *) malloc(sizeof(int) * size);
    while (i < size)
    {
        tab[i] = i;
        i++;
    }
    return (tab);
}

int    *create_z(int *tab, char **arr, int len)
{
    int j;
    int i;

    j = 0;
    i = -1;
    while (i++ < len)
        ;
    while (arr[j] != 0)
        tab[i++] = ft_atoi(arr[j++]);
    return (tab);
}
//проверка!
void    *print(int *tab, int size)
{
    int i;

    i = 0;
    while (i < size)
        printf("%d ", tab[i++]);
    printf("\n");
    return NULL;
}

t_coord     or_file(char *name, t_size *size)
{
    int x;
    int fd;
    int y;
    char *str;
    t_coord origin;

    y = 0;
    x = 0;
    fd = open(name, O_RDONLY);
    while (get_next_line((const int)fd, &str) == 1)
    {
        x = arr_wid((void **)ft_strsplit(str, ' '));
        y++;
    }
    close(fd);
    size->x = --x;
    size->y = y;
    origin.tab_x = arr_create(x);
    origin.tab_y = arr_create(y);
    origin.tab_z = (int *)malloc(sizeof(int) * x * y);
    fd = open(name, O_RDONLY);
    y = 1;
    while (get_next_line((const int)fd, &str) == 1)
        create_z(origin.tab_z, ft_strsplit(str, ' '), x * y++);
    close(fd);
    return (origin);
}
