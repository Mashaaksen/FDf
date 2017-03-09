#include "fdf.h"

int     arr_wid(void **arr)
{
      int i;

    i = 0;
    while (arr[i++] != '\0')
        ;
    return (i);
}

void    centre(t_win *ptr)
{
    double x;
    double y;

    x = (ptr->size_x - 1) / 2;
    y = (ptr->size_y - 1) / 2;
    ptr->y = 0;
    while (ptr->y < ptr->size_y)
    {
        ptr->x = 0;
        while (ptr->x < ptr->size_x)
        {
            ptr->origin[ptr->y][ptr->x][0] = ptr->origin[ptr->y][ptr->x][0] - x;
            ptr->origin[ptr->y][ptr->x][1] = ptr->origin[ptr->y][ptr->x][1] - y;
            ptr->x++;
        }
        ptr->y++;
    }
}

t_win or_file(char *name)
{
    char **arr;
    t_win ptr;
    int fd;
    char *str;

    ptr.y = 0;
    fd = open(name, O_RDONLY);
    while (get_next_line((const int)fd, &str) == 1)
    {
        ptr.size_x = arr_wid((void **)ft_strsplit(str, ' ')) - 1;
        ptr.size_y++;
    }
    close(fd);
    ptr.origin = (double ***)malloc(sizeof(double **) * ptr.size_y);
    fd = open(name, O_RDONLY);
    while (get_next_line((const int)fd, &str) == 1)
    {
        arr = ft_strsplit(str, ' ');
        ptr.origin[ptr.y] = (double **)malloc(sizeof(double *) * ptr.size_x);
        ptr.x = 0;
        while (ptr.x < ptr.size_x)
        {
            ptr.origin[ptr.y][ptr.x] = (double *)malloc(sizeof(double) * 3);
            ptr.origin[ptr.y][ptr.x][0] = ptr.x;
            ptr.origin[ptr.y][ptr.x][1] = ptr.y;
            ptr.origin[ptr.y][ptr.x][2] = ft_atoi(arr[ptr.x]);
            ptr.x++;
        }
        ptr.y++;
    }
    centre(&ptr);
    close(fd);
    return (ptr);
}
