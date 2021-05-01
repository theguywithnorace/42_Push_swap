/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timotheein <timotheein@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 14:28:47 by tiin              #+#    #+#             */
/*   Updated: 2021/04/30 15:25:28 by timotheein       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_str_free(char **str)
{
	if (*str)
		free(*str);
	*str = NULL;
}

static char	*ft_c_calloc(int size)
{
	char	*str;
	int		i;

	if (!(str = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = -1;
	while (++i < size)
		str[i] = 0;
	str[size] = 0;
	return (str);
}

static int	ft_write_line(char **str, char **line, int fd)
{
	char	*end;
	char	*tmp;

	if ((end = ft_strchr_gnl(str[fd], '\n')) == NULL)
	{
		*line = ft_strdup_gnl(str[fd]);
		ft_str_free(&str[fd]);
		return (0);
	}
	end++;
	*line = ft_substr(str[fd], 0, (end - str[fd] - 1));
	tmp = ft_strdup_gnl(str[fd] + (end - str[fd]));
	free(str[fd]);
	str[fd] = ft_strdup_gnl(tmp);
	ft_str_free(&tmp);
	return (1);
}

static int	ft_checker(char **str, char **buff, char **line, int fd)
{
	if (fd < 0 || !line || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (-1);
	if ((*buff = ft_c_calloc(BUFFER_SIZE)) == NULL)
		return (-1);
	if (*str == NULL)
		if ((*str = ft_c_calloc(0)) == NULL)
			return (-1);
	return (1);
}

int			get_next_line(int fd, char **line)
{
	char		*buff;
	char		*tmp;
	int			rd;
	static char *str[OPEN_MAX];

	rd = -2;
	buff = NULL;
	if (ft_checker(&str[fd], &buff, line, fd) == -1)
		return (-1);
	while (ft_strchr_gnl(str[fd], '\n') == NULL && rd != 0)
	{
		if ((rd = read(fd, buff, BUFFER_SIZE)) == -1)
		{
			ft_str_free(&buff);
			return (-1);
		}
		buff[rd] = 0;
		tmp = ft_strjoin_gnl(str[fd], buff);
		free(str[fd]);
		str[fd] = ft_strdup_gnl(tmp);
		ft_str_free(&tmp);
	}
	free(buff);
	return (ft_write_line(str, line, fd));
}
