/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timotheein <timotheein@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 14:28:38 by tiin              #+#    #+#             */
/*   Updated: 2021/04/27 10:17:55 by timotheein       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_gnl(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return ((size_t)i);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	size_t i;

	i = -1;
	while (((char *)s)[++i])
		if ((char)c == ((char *)s)[i])
			return ((char *)s + i);
	return (NULL);
}

char	*ft_strdup_gnl(char *s1)
{
	int		len;
	int		i;
	char	*cpy;

	len = 0;
	if (s1)
		len = ft_strlen_gnl(s1);
	if (!(cpy = malloc(sizeof(*s1) * (len + 1))))
		return (NULL);
	i = -1;
	while (s1[++i])
		cpy[i] = s1[i];
	cpy[i] = 0;
	return (cpy);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = -1;
	while (++i < len && i + start < ft_strlen_gnl(s))
		str[i] = s[start + i];
	str[i] = 0;
	return (str);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	size_t	i;
	size_t	len1;
	size_t	len2;
	char	*res;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen_gnl(s1);
	len2 = ft_strlen_gnl(s2);
	if (!(res = malloc(sizeof(*s1) * (len1 + len2 + 1))))
		return (NULL);
	i = -1;
	while (++i < len1)
		res[i] = s1[i];
	i = -1;
	while (++i < len2)
		res[len1 + i] = s2[i];
	res[len1 + len2] = 0;
	return (res);
}
