/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timotheein <timotheein@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 11:06:20 by timotheein        #+#    #+#             */
/*   Updated: 2021/05/09 18:56:35 by timotheein       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		max_lgth(t_elt *e)
{
	int max;

	max = 1;
	if (e)
	{
		max = ft_strlen_ps(e->content);
		e = e->next;
	}
	while (e)
	{
		if (ft_strlen_ps(e->content) > max)
			max = ft_strlen_ps(e->content);
		e = e->next;
	}
	return (max);
}

void	write_spaces(t_all *all)
{
	int i;

	i = 0;
	write(1, "   ", 3);
	while (++i < max_lgth(all->sk_a))
		write(1, " ", 1);
	return ;
}

void	write_tacks(t_all *all)
{
	int i;

	i = 0;
	write(1, "---", 3);
	while (++i < max_lgth(all->sk_a))
		write(1, "-", 1);
	write(1, "   ", 3);
	write(1, "---", 3);
	i = 0;
	while (++i < max_lgth(all->sk_b))
		write(1, "-", 1);
	write(1, "\n", 1);
	i = 0;
	while (++i <= (((max_lgth(all->sk_a) / 2) * 2) / 2) + 1)
		write(1, " ", 1);
	write(1, "A", 1);
	i = 0;
	while (++i <= ((((max_lgth(all->sk_a) + 1) / 2) * 2) / 2))
		write(1, " ", 1);
	write(1, "    ", 3);
	i = 0;
	while (++i <= (((max_lgth(all->sk_b) / 2) * 2) / 2) + 1)
		write(1, " ", 1);
	write(1, "B\n\n\n", 4);
}
