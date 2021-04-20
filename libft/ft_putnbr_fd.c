/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 13:37:07 by tiin              #+#    #+#             */
/*   Updated: 2019/11/06 13:57:55 by tiin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

static void	funct(int n, int fd)
{
	long dec;
	long fz;
	char c;

	fz = 0;
	dec = 1000000000;
	while (dec > 0)
	{
		if (n / dec || fz || dec == 1)
		{
			c = n / dec + '0';
			write(fd, &c, 1);
			fz = 1;
		}
		n = n % dec;
		dec = dec / 10;
	}
	return ;
}

void		ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -1 * n;
	}
	funct(n, fd);
	return ;
}
