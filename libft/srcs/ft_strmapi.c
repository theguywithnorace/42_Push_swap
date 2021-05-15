/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiin <tiin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 13:44:27 by tiin              #+#    #+#             */
/*   Updated: 2019/11/27 18:54:06 by timotheein       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*out;
	unsigned int	i;

	if (!s || !f || !(out = malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (0);
	i = -1;
	while (++i < ft_strlen(s))
		out[i] = (*f)(i, s[i]);
	out[i] = 0;
	return (out);
}
