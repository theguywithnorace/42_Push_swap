/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_send.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timotheein <timotheein@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 22:37:57 by timotheein        #+#    #+#             */
/*   Updated: 2021/05/13 13:04:25 by timotheein       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void send_to_b(t_all *all)
{
	t_elt *e;

	e = all->sk_a;
	bug("\n\nBEGIN of send to B", 1);
	while (ft_lstsize_e(all->sk_a) > 1)
	{
		bug(">>> new while send back to a", 0);
		print_situation_a(all);
		set_next_pivot(all, e);
		while (less_elt_than(1, all->sk_a))
			quick_send_b(all);
		e = all->sk_a;
		set_next_pivot(all, e);
		while (in_packet(all, e) && ft_lstsize_e(all->sk_a) > 1)
		{
			print_situation_a(all);
			if (val(e) < all->v_nxtp)
				send_low_values_b(all);
			else if (val(e) == all->v_nxtp)
				send_pivot_b(all);
			else if (is_all_end_sup(all->sk_a, all->v_nxtp))
			{
				set_pivot_at_top(all);
				get_pivots(all->sk_a, 1); //parcours en sommant jusqu'a [fin ou pivot] -> moyenne -> [elt >= moy] = pivot
				bug("\nRECCURSION", 1);
				send_to_b(all);
			}
			else if (val(e) > all->v_nxtp)
				stock_hig_values_a(all);
			e = all->sk_a;
		}
		set_pivot_at_top(all);
		bug("all->v_nxtpvt", all->v_nxtp);
		if (is_sk_ordered(all->sk_a) && is_all_end_sup(all->sk_a, all->v_nxtp))
			return (bug("END BY RETURN of send to b. pb", 0));
		print_situation_a(all);
		while (is_last_seen(all->sk_a))
			send_hig_values_b(all);
		if (all->sk_a)
		{
			printf("address e : %p\n", all->sk_a->next);
			print_action("pb", all);
		}
		bug("end of while of send_to_b", 0);
	}
	bug("END of send to b. pb", 0);
}

void send_to_a(t_all *all)
{
	t_elt *e;

	e = all->sk_b;
	bug("\n\nBEGIN of send to A", 1);
	while (all->sk_b)
	{
		bug(">>> new while send back to a", 0);
		print_situation_b(all);
		while (less_elt_than(1, all->sk_b))
			quick_send_a(all);
		e = all->sk_b;
		set_next_pivot(all, e);
		while (all->sk_b && in_packet(all, all->sk_b))
		{
			if (val(e) > all->v_nxtp)
				send_hig_values_a(all);
			else if (val(e) == all->v_nxtp)
				send_pivot_a(all);
			else if (is_all_end_inf(all->sk_b, all->v_nxtp))
			{
				set_pivot_at_top(all);
				get_pivots(all->sk_b, -1); //parcours en sommant jusqu'a [fin ou pivot] -> moyenne -> [elt >= moy] = pivot
				bug("\nRECCURSION", 1);
				send_to_a(all);
			}
			else if (val(e) < all->v_nxtp)
				stock_low_values_b(all);
			if (all->sk_b)
				e = all->sk_b;
		}
		set_pivot_at_top(all);
		if (is_sk_ordered(all->sk_b))
			return (bug("END of send to A. pb0", 0));
		while (all->sk_b && is_last_seen(all->sk_b))
			send_low_values_a(all);
		// if (all->sk_b)
		// {
		// 	printf("address e : %p\n", all->sk_b->next);
		// 	print_action("pa", all);
		// }
		bug("end of while of send_to_b", 0);
	}
	bug("END of send to A. pb", 0);
}