/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiin <tiin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 13:48:06 by tiin              #+#    #+#             */
/*   Updated: 2019/11/29 15:12:30 by tiin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*out;
	size_t	i;

	if (!s || len == 0 || ft_strlen(s) + 1 < start)
		return (ft_calloc(sizeof(char), 1));
	if (!(out = ft_calloc(sizeof(char), len + 1)))
		return (0);
	i = 0;
	while (i < len && s[i])
	{
		out[i] = (char)s[i + start];
		i++;
	}
	out[i] = 0;
	return (out);
}
