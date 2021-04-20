/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiin <tiin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:52:25 by tiin              #+#    #+#             */
/*   Updated: 2019/11/26 10:19:49 by tiin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;
	size_t	i;

	i = -1;
	d = (char*)dst;
	s = (char *)src;
	if (d > s)
	{
		while (len--)
			d[len] = s[len];
	}
	if (s > d)
	{
		while (++i < len)
			d[i] = s[i];
	}
	return (dst);
}
