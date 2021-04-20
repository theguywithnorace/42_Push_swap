/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiin <tiin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 13:36:02 by tiin              #+#    #+#             */
/*   Updated: 2019/11/09 12:12:16 by timotheein       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

static size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void			ft_putendl_fd(char *s, int fd)
{
	char c;

	c = '\n';
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
	write(fd, &c, 1);
}
