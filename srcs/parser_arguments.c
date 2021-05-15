/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_arguments.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timotheein <timotheein@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:58:23 by timotheein        #+#    #+#             */
/*   Updated: 2021/05/15 13:00:05 by timotheein       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int value_already_found(t_all *all, char *s)
{
	t_elt *elt;

	elt = all->sk_a;
	while (elt)
	{
		if (!(ft_strcmp(elt->content, s)))
			return (0);
		elt = elt->next;
	}
	return (1);
}

int check_arg_s_args(char *str)
{
	int i;

	i = -1;
	while (++i < ft_strlen_ps(str))
		if (!((i == 0 && str[i] == '-') ||
			  (i == 0 && str[i] == '+') || (str[i] >= '0' && str[i] <= '9')))
			return (0);
	if (!((ft_strlen_ps(str) <= 10 &&
		   (str[0] != '-' || str[0] != '+')) ||
		  (ft_strlen_ps(str) <= 11 && (str[0] != '-' || str[0] != '+'))))
		return (0);
	return (1);
}

int is_int(char *str)
{
	int i;
	long out;
	long sign;

	i = -1;
	if (!(check_arg_s_args(str)))
		return (0);
	sign = 1;
	i = -1;
	if (str[0] == '-')
	{
		sign = -1;
		i = 0;
	}
	if (str[0] == '+')
		i = 0;
	out = 0;
	while (str[++i])
		out = out * 10 + (str[i] - '0') * sign;
	if (out > 2147483647 || out < -2147483648)
		return (0);
	return (1);
}

int check_n_get_arguments(int ac, char **av, t_all *all)
{
	int i;
	t_elt *elt;

	i = all->bonus;
	while (++i < ac)
	{
		if (!is_int(av[i]))
			return (0);
		if (!all->sk_a)
		{
			if (!(value_already_found(all, av[i])) || !(all->sk_a = ft_lstnew_e(av[i])))
				return (0);
			all->len_a++;
			elt = all->sk_a;
			continue;
		}
		if (!(value_already_found(all, av[i])) || !(elt->next = ft_lstnew_e(av[i])))
			return (0);
		all->len_a++;
		elt = elt->next;
	}
	all->len_t = ft_lstsize_e(all->sk_a);
	return (1);
}
