/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timotheein <timotheein@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 20:05:41 by timotheein        #+#    #+#             */
/*   Updated: 2021/05/10 22:31:20 by timotheein       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void send_low_values_b(t_all *all)
{
	bug("send_low_values_b", 0);
	print_action("pb", all);
}

void send_pivot_b(t_all *all)
{
	bug("send_pivot_b", 0);

	print_action("pb", all);
	print_action("rb", all);
}

void stock_hig_values_a(t_all *all)
{
	bug("stock_hig_values_a", 0);
	all->sk_a->is_pivot = BKED;
	print_action("ra", all);
}


void set_pivot_top_b(t_all *all)
{
	bug("set_pivot_top_b", 0);

	print_action("rrb", all);
	all->sk_b->is_pivot = OLD;
}

void send_hig_values_b(t_all *all)
{
	bug("send_hig_values_b... is_pivot", all->sk_a->is_pivot);

	if (all->sk_a->is_pivot != BKED)
		print_action("rra", all);
	print_action("pb", all);
	all->sk_b->is_pivot = 0;
}

int is_last_seen(t_elt *e)
{
	t_elt *f;

	if (!e)
		return (0);
	f = ft_lstlast_e(e);
	if (f->is_pivot == BKED)
		return (1);
	bug("is_last_seen : is pivot", f->is_pivot);
	return (0);
}