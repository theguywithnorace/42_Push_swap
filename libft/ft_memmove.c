/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timotheein <timotheein@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:52:25 by tiin              #+#    #+#             */
/*   Updated: 2021/05/07 20:23:24 by timotheein       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
