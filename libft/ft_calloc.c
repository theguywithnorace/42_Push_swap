/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 12:25:21 by tiin              #+#    #+#             */
/*   Updated: 2019/11/06 13:04:17 by tiin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*out;

	i = 0;
	if (!(out = malloc(count * size)))
		return (0);
	while (i < count * size)
	{
		out[i] = 0;
		i++;
	}
	return ((void*)out);
}
