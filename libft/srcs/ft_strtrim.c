/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiin <tiin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 13:46:02 by tiin              #+#    #+#             */
/*   Updated: 2019/11/29 15:14:11 by tiin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_in_set(char c, char const *set)
{
	int i;

	i = -1;
	while (set[++i])
	{
		if (set[i] == c)
			return (1);
	}
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	size_t	a;
	size_t	z;
	size_t	i;
	char	*s;

	s = (char *)s1;
	if (!s || !set)
		return (NULL);
	a = 0;
	z = ft_strlen(s);
	while (is_in_set(s[a], set) && s[a])
		a++;
	while (is_in_set(s[z - 1], set) && z > a)
		z--;
	i = 0;
	if (a == z)
		return (ft_calloc(sizeof(char), 1));
	return (ft_substr(s1, a, z - a));
}
