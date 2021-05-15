/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 12:38:31 by tiin              #+#    #+#             */
/*   Updated: 2019/11/06 13:22:29 by tiin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	size_t	i;
	char	*out;

	len = 0;
	while (s1[len])
		len++;
	if (!(out = malloc(sizeof(char) * (len + 1))))
		return (0);
	i = -1;
	while (s1[++i])
		out[i] = s1[i];
	out[i] = 0;
	return (out);
}
