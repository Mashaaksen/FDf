/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maksenov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 15:51:15 by maksenov          #+#    #+#             */
/*   Updated: 2017/01/31 16:09:19 by maksenov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		strchar(char *tmp)
{
	while (*tmp)
	{
		if (*tmp == '\n')
			return (1);
		tmp++;
	}
	return (0);
}

char	*ft_strndup(char *str)
{
	char	*line;
	int		size;
	int		i;

	i = 0;
	size = 0;
	if (str[size] == 0)
		return (NULL);
	while (str[size] != '\n' && str[size] != 0)
	{
		if (str[size] == '\\' && str[size + 1] == 'n')
			break ;
		size++;
	}
	line = (char *)malloc(sizeof(char) * size + 1);
	line[size] = '\0';
	while (size-- >= 1)
	{
		line[i] = *str;
		str++;
		i++;
	}
	return (line);
}

int		get_next_line(const int fd, char **line)
{
	static char *str;
	int			ret;
	char		*tmp;
	char		*p;

	tmp = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
	tmp[BUFF_SIZE] = '\0';
	ret = (int)read(fd, tmp, BUFF_SIZE);
	if (str)
		tmp = ft_strjoin(str, tmp);
	*tmp == '\n' ? tmp++ : 0;
	if (ret < 0)
		return (ret);
	while (strchar(tmp) != 1 && ret != 0)
	{
		p = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
		p[BUFF_SIZE] = '\0';
		ret = (int)read(fd, p, BUFF_SIZE);
		tmp = ft_strjoin(tmp, p);
	}
	str = ft_strchr(tmp, '\n');
	*line = ft_strndup(tmp);
	if (*line != NULL)
		return (1);
	return (0);
}
