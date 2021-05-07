/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timotheein <timotheein@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 11:39:48 by tiin              #+#    #+#             */
/*   Updated: 2021/05/07 20:23:02 by timotheein       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int i;
	int out;
	int sign;

	i = 0;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\f' ||
			str[i] == '\r' || str[i] == '\v' || str[i] == ' ')
		i++;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	out = 0;
	while (str[i] >= '0' && str[i] <= '9' && i < 20)
	{
		out = out * 10 + (str[i] - '0') * sign;
		i++;
	}
	return (out);
}
