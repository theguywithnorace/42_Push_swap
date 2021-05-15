/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_send.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timotheein <timotheein@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 22:37:57 by timotheein        #+#    #+#             */
/*   Updated: 2021/05/15 13:19:41 by timotheein       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int all_rest_old(t_elt *e)
{
	if (!e)
		return (1);
	while (e)
	{
		if (e->is_pivot != -1)
			return (0);
		e = e->next;
	}
	return (1);
}

void while_send_b(t_all *all, t_elt *e)
{
	if (val(e) < all->v_nxtp)
		send_low_values_b(all);
	else if (val(e) == all->v_nxtp)
		send_pivot_b(all);
	else if (is_all_end_sup(all->sk_a, all->v_nxtp))
	{
		back_up_if_bked_a(all);
		set_pivot_at_top_b(all);
		if (is_sk_ordered(all->sk_a, 1))
			return;
		get_pivots(all->sk_a, 1);
		send_to_b(all);
		return;
	}
	else if (val(e) > all->v_nxtp)
		stock_hig_values_a(all);
}

void send_to_b(t_all *all)
{
	t_elt *e;
	get_pivots(all->sk_a, 1);
	e = all->sk_a;
	while (all->sk_a && !(is_sk_ordered(all->sk_a, 1) && !all->sk_b))
	{
		while (less_elt_than(3, all->sk_a, all))
		{
			if (all_rest_old(all->sk_a))
				return;
			opti_a(all, all->sk_a);
		}
		if (all->sk_a)
		{
			e = all->sk_a;
			set_next_pivot(all, e);
		}
		while (in_packet(e, all->v_nxtp) && ft_lstsize_e(all->sk_a) > 0)
		{
			while_send_b(all, e);
			if (all->sk_a)
				e = all->sk_a;
		}
		if (all->sk_b && val(ft_lstlast_e(all->sk_b)) == all->v_nxtp)
			set_pivot_at_top_b(all);
		if (is_sk_ordered(all->sk_a, -1) && is_all_end_sup(all->sk_a, all->v_nxtp))
			return;
		while (is_last_seen(all->sk_a))
			send_hig_values_b(all);
		if (all->sk_a)
			print_action("pb", all);
	}
}

void while_send_a(t_all *all, t_elt *e)
{
	if (val(e) > all->v_nxtp)
		send_hig_values_a(all);
	else if (val(e) == all->v_nxtp)
		send_pivot_a(all);
	else if (is_all_end_inf(all->sk_b, all->v_nxtp))
	{
		back_up_if_bked_b(all);
		set_pivot_at_top_a(all);
		get_pivots(all->sk_b, -1);
		send_to_a(all);
		return;
	}
	else if (val(e) < all->v_nxtp)
		stock_low_values_b(all);
}

void send_to_a(t_all *all)
{
	t_elt *e;

	e = all->sk_b;
	get_pivots(all->sk_b, -1);
	while (all->sk_b)
	{
		while (all->sk_b && less_elt_than(3, all->sk_b, all))
			opti_b(all, all->sk_b);
		e = all->sk_b;
		if (e)
			set_next_pivot(all, e);
		while (all->sk_b)
		{
			while_send_a(all, e);
			if (all->sk_b)
				e = all->sk_b;
		}
		if (all->sk_a && val(ft_lstlast_e(all->sk_a)) == all->v_nxtp)
			set_pivot_at_top_a(all);
		while (all->sk_b && is_last_seen(all->sk_b))
			send_low_values_a(all);
	}
}