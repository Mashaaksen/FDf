#ifndef FDF_FDF_H
#define FDF_FDF_H
# define BUFF_SIZE 100

# include <math.h>
# include <mlx.h>
# include <unistd.h>
# include <zconf.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include "libft/libft.h"
# include <stdio.h>

typedef struct s_win{
    void       *mlx;
    void       *win;
    int        place;
    int        prop;
}              t_win;

typedef struct s_size{
    int        x;
    int        y;
    double     beta;
    double     alpha;
}              t_size;

typedef struct s_coord{
    int        *tab_x;
    int        *tab_y;
    int        *tab_z;
    int        x;
    int        y;
    int        ret_x;
    int        ret_y;
}              t_coord;

int		get_next_line(const int fd, char **line);
int     key_hook(int keycode, t_win *param);
int		strchar(char *tmp);
char	*ft_strndup(char *str);
t_coord or_file(char *name, t_size *size);
void    fdf(t_coord origin, t_size size);
void    draw_map(t_coord origin, t_size size, t_win *ptr);
void    *print(int *tab, int size);
void    *print(int *tab, int size);

#endif //FDF_FDF_H
