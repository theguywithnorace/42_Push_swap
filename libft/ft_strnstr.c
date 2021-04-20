/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 11:28:57 by tiin              #+#    #+#             */
/*   Updated: 2019/11/06 13:25:40 by tiin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	if (needle[0] == 0)
		return ((char*)haystack);
	i = 0;
	while (haystack[i] != '\0' && i <= len)
	{
		j = 0;
		while ((haystack[i + j] == needle[j] || needle[j] == '\0')
				&& (i + j) <= len)
		{
			if (needle[j] == '\0')
				return ((char*)&haystack[i]);
			j++;
		}
		i++;
	}
	return (0);
}
