/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiin <tiin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 12:30:24 by tiin              #+#    #+#             */
/*   Updated: 2019/11/29 12:49:26 by tiin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*my_malloc(char *s, char c)
{
	int		n;
	char	*out;

	n = 0;
	while (s[n] && s[n] != c)
		n++;
	if (!(out = ft_calloc(sizeof(char), n + 1)))
		return (NULL);
	return (out);
}

static int	str_nb(char *s, char c)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		while (*s && *s != c)
		{
			s++;
			nb++;
		}
	}
	return (nb);
}

char		**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**out;
	char	*str;

	i = 0;
	str = (char *)s;
	if (!str || !(out = ft_calloc(sizeof(char *), (str_nb(str, c) + 1))))
		return (0);
	while (*str)
	{
		j = 0;
		while (*str == c)
			str++;
		if (*str && *str != c)
		{
			out[i] = my_malloc(str, c);
			while (*str && *str != c)
				out[i][j++] = *str++;
			i++;
		}
	}
	return (out);
}
