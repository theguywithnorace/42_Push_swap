/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timotheein <timotheein@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 13:29:29 by tiin              #+#    #+#             */
/*   Updated: 2021/05/07 20:23:24 by timotheein       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*funct(int n, char *s, int i)
{
	long	dec;
	long	fz;

	fz = 0;
	dec = 1000000000;
	while (dec > 0)
	{
		if (n / dec || fz || dec == 1)
		{
			s[++i] = n / dec + '0';
			fz = 1;
		}
		n = n % dec;
		dec = dec / 10;
	}
	s[++i] = 0;
	return (s);
}

char		*ft_itoa(int n)
{
	int		i;
	char	*s;

	i = -1;
	if (!(s = malloc(sizeof(char) * 12)))
		return (0);
	if (n == -2147483648)
	{
		s[++i] = '-';
		s[++i] = '2';
		n = 147483648;
	}
	else if (n < 0)
	{
		s[++i] = '-';
		n = -1 * n;
	}
	return (funct(n, s, i));
}
