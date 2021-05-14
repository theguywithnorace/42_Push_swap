/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_actions_to_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timotheein <timotheein@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 20:05:41 by timotheein        #+#    #+#             */
/*   Updated: 2021/05/14 11:45:07 by timotheein       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void send_hig_values_a(t_all *all)
{
	bug("send_hig_values_a", 0);
	print_action("pa", all);
}

void send_pivot_a(t_all *all)
{

	print_action("pa", all);
	if (all->sk_a)
	{
		if (all->sk_a->is_pivot == OLD)
			set_next_pivot(all, all->sk_b);
		else
			all->sk_a->is_pivot = OLD;
	}

	if (!is_all_end_inf(all->sk_b, all->v_nxtp))
		print_action("ra", all);
}

void stock_low_values_b(t_all *all)
{
	if (all->sk_b)
		bug("stock_low_values_b", val(all->sk_b));
	all->sk_b->is_pivot = BKED;
	print_action("rb", all);
}

// void set_pivot_top_a(t_all *all)
// {
// 	bug("set_pivot_top_a", 0);
// 	if (val(ft_lstlast_e(all->sk_a)) == all->v_nxtp)
// 		print_action("rra", all);
// 	all->sk_a->is_pivot = OLD;
// }

void send_low_values_a(t_all *all)
{
	bug("send_low_values_a", val(all->sk_b));

	if (all->sk_b->is_pivot != BKED)
		print_action("rrb", all);
	print_action("pa", all);
	all->sk_a->is_pivot = 0;
}

int is_all_end_inf(t_elt *e, int max)
{
	t_elt *bk;

	bk = e;
	if (!e)
		return (0);
	while (e)
	{
		if (val(e) >= max)
			return (0);
		e = e->next;
	}
	e = bk;
	// while (e)
	// {
	// 	if (e->is_pivot == BKED)
	// 		e->is_pivot = 0;
	// 	e = e->next;
	// }
	bug("all end is inf than pivot, pivot :", max);
	return (1);
}

void quick_send_a(t_all *all)
{
	all->sk_b->is_pivot = OLD;
	bug("send less than 1 elt", 1);
	print_action("pa", all);
}