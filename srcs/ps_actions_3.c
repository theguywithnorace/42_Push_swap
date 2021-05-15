/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_actions_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timotheein <timotheein@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 20:05:41 by timotheein        #+#    #+#             */
/*   Updated: 2021/05/15 13:51:28 by timotheein       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	quick_send_b(t_all *all)
{
	if (!all->sk_a)
		return ;
	all->sk_a->is_pivot = OLD;
	print_action("pb", all);
}

void	back_up_if_bked_a(t_all *all)
{
	t_elt *e;

	if (!all->sk_a)
		return ;
	e = all->sk_a;
	if (e->is_pivot == BKED)
	{
		while (e && e->is_pivot == BKED)
		{
			e->is_pivot = 0;
			e = e->next;
		}
		return ;
	}
	while ((ft_lstlast_e(e))->is_pivot == BKED)
	{
		print_action("rra", all);
		all->sk_a->is_pivot = 0;
		e = all->sk_a;
	}
}

void	back_up_if_bked_b(t_all *all)
{
	t_elt *e;

	if (!all->sk_b)
		return ;
	e = all->sk_b;
	if (e->is_pivot == BKED)
	{
		while (e && e->is_pivot == BKED)
		{
			e->is_pivot = 0;
			e = e->next;
		}
		return ;
	}
	while ((ft_lstlast_e(e))->is_pivot == BKED)
	{
		print_action("rrb", all);
		all->sk_b->is_pivot = 0;
		e = all->sk_b;
	}
}

void	quick_send_a(t_all *all)
{
	all->sk_b->is_pivot = OLD;
	print_action("pa", all);
}
