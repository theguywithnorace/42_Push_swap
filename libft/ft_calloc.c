/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timotheein <timotheein@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 12:25:21 by tiin              #+#    #+#             */
/*   Updated: 2021/05/07 20:23:24 by timotheein       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
