/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_send.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timotheein <timotheein@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 22:37:57 by timotheein        #+#    #+#             */
/*   Updated: 2021/05/10 22:38:20 by timotheein       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void send_to_b(t_all *all)
{
	t_elt *e;

	e = all->sk_a;
	while (e)
	{
		set_next_pivot(all, e);
		bug("new while send to b", 0);
		while (in_packet(all, e))
		{
			print_situation_a(all);
			if (val(e) < all->v_nxtp)
				send_low_values_b(all);
			else if (val(e) == all->v_nxtp)
				send_pivot_b(all);
			else if (val(e) > all->v_nxtp)
				stock_hig_values_a(all);
			e = all->sk_a;
		}
		set_pivot_top_b(all);
		if (is_sk_a_ordered(all))
			return (bug("sk_a ordered, than return, out of send_to_a", 0));
		while (is_last_seen(e))
			send_hig_values_b(all);
		if (all->sk_a)
		{
			printf("address e : %p\n", all->sk_a->next);
			print_action("pb", all);
		}
		bug("end of while", 0);
	}
}

void send_to_a(t_all *all)
{
	t_elt *e;
	int i;
	int k;

	e = all->sk_b;
	while (e)
	{
		i = 0;
		set_next_pivot(all, e);
		while (in_packet(all, e))
		{
			if (val(e) < all->v_nxtp)
				print_action("pa", all);
			else if (val(e) == all->v_nxtp)
			{
				print_action("pa", all);
				print_action("ra", all);
			}
			else if (val(e) > all->v_nxtp)
			{
				i++;
				e->is_pivot = BKED;
				print_action("rb", all);
			}
			e = all->sk_a;
		}
		print_action("rra", all);
		all->sk_b->is_pivot = -1;
		k = 0;
		if (is_sk_a_ordered(all))
			return;
		while (k < i)
		{
			print_action("rrb", all);
			print_action("pa", all);
			all->sk_b->is_pivot = 0;
		}
		if (e)
			print_action("pa", all);
	}
}