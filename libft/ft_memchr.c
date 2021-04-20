/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiin <tiin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 11:03:21 by tiin              #+#    #+#             */
/*   Updated: 2019/11/08 23:47:55 by timotheein       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*tmp;

	tmp = (char*)s;
	i = -1;
	while (++i < n && tmp[i])
	{
		if (tmp[i] == (char)c)
			return ((void*)&tmp[i]);
	}
	if (i < n && tmp[i] == (char)c)
		return ((void*)&tmp[i]);
	return (0);
}
