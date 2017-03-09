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
    int        left;
    int        high;
    int        prop;
    int        size_x;
    int        size_y;
    double     alpha;
    double     beta;
    double     gama;
    double     ***origin;
    double     ***new;
    int        x;
    int        y;
}              t_win;

int		get_next_line(const int fd, char **line);
int     key_hook(int keycode, t_win *param);
int		strchar(char *tmp);
char	*ft_strndup(char *str);
t_win   or_file(char *name);
void    fdf(t_win ptr);
void    draw_map(t_win *ptr);

#endif //FDF_FDF_H
