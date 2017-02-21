#include "fdf.h"

int     arr_wid(void **arr)
{
      int i;

    i = 0;
    while (arr[i++] != '\0')
        ;
    return (i);
}

int     *arr_create(int *tab, char **arr, int   *x)
{
    int i;

    i = 0;
    while (arr[i] != '\0')
    {
        tab[i] = ft_atoi((const char *)arr[i]);
        i++;
    }
    *x = i;
    return (tab);
}
//проверка!
/*
void    *print(int *tab)
{
    int i;
    int l = sizeof(tab) / sizeof(int);
    i = 0;
    while (i < l)
        printf("%d", tab[i++]);
    printf("\n");
    return NULL;
}*/



int     **or_file(char *name, t_size *size)
{
    int **matrix;
    int fd;
    int i;
    char *str;

    i = 0;
    fd = open(name, O_RDONLY);
    while (get_next_line((const int)fd, &str) == 1)
        i++;
    close(fd);
    size->y = i;
    matrix = (int **)malloc(sizeof(int *) * i);
    fd = open(name, O_RDONLY);
    i = 0;
    while (get_next_line((const int)fd, &str) == 1)
    {

        matrix[i] = (int *)malloc(sizeof(int) * (arr_wid((void **)ft_strsplit(str, ' ')) - 1));
        matrix[i] = arr_create(matrix[i], ft_strsplit(str, ' '), &size->x);
        i++;
    }
    close(fd);
    return (matrix);
}
