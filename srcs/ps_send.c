/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_send.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timotheein <timotheein@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 22:37:57 by timotheein        #+#    #+#             */
/*   Updated: 2021/05/14 11:27:38 by timotheein       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void send_to_b(t_all *all)
{
	t_elt *e;
	get_pivots(all->sk_a, 1); //parcours en sommant jusqu'a [fin ou pivot] -> moyenne -> [elt >= moy] = pivot

	bug("\n\nBEGIN of send to B", 1);
	e = all->sk_a;
	while (all->sk_a)
	{
		bug(">>> new while send back to a", 0);
		// set_next_pivot(all, e);
		while (less_elt_than(1, all->sk_a))
			quick_send_b(all);
		if (all->sk_a)
		{
			e = all->sk_a;
			set_next_pivot(all, e);
		}
		while (in_packet(e) && ft_lstsize_e(all->sk_a) > 0)
		{

			if (val(e) < all->v_nxtp)
				send_low_values_b(all);
			else if (val(e) == all->v_nxtp)
				send_pivot_b(all);
			else if (is_all_end_sup(all->sk_a, all->v_nxtp))
			{
				back_up_if_bked_a(all);
				set_pivot_at_top_b(all);
				if (is_sk_ordered(all->sk_a))
					return;
				get_pivots(all->sk_a, 1); //parcours en sommant jusqu'a [fin ou pivot] -> moyenne -> [elt >= moy] = pivot
				bug("\nRECURSION", 1);
				send_to_b(all);
				bug("\nEND  OF RECURSION\n", 1);
				return;
			}
			else if (val(e) > all->v_nxtp)
				stock_hig_values_a(all);
			if (all->sk_a)
				e = all->sk_a;
		}
		if (all->sk_b && val(ft_lstlast_e(all->sk_b)) == all->v_nxtp)
			set_pivot_at_top_b(all);
		bug("all->v_nxtpvt", all->v_nxtp);
		if (is_sk_ordered(all->sk_a) && is_all_end_sup(all->sk_a, all->v_nxtp))
			return (bug("END BY RETURN of send to b. pb", 0));
		print_situation_a(all);
		while (is_last_seen(all->sk_a))
			send_hig_values_b(all);
		if (all->sk_a)
		{
			// printf("address e : %p\n", all->sk_a->next);
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
	get_pivots(all->sk_b, -1);
	bug("\n\nBEGIN of send to A", val(all->sk_b));
	while (all->sk_b)
	{
		bug(">>> new while send back to a", val(all->sk_b));
		while (all->sk_b && less_elt_than(1, all->sk_b))
			quick_send_a(all);
		e = all->sk_b;
		if (e)
			set_next_pivot(all, e);
		// while (all->sk_b && in_packet(all->sk_b))
		while (all->sk_b)
		{
			if (val(e) > all->v_nxtp)
				send_hig_values_a(all);
			else if (val(e) == all->v_nxtp)
				send_pivot_a(all);
			else if (is_all_end_inf(all->sk_b, all->v_nxtp))
			{
				bug("LAST ELT", val(ft_lstlast_e(e)));
				back_up_if_bked_b(all);
				set_pivot_at_top_a(all);
				get_pivots(all->sk_b, -1); //parcours en sommant jusqu'a [fin ou pivot] -> moyenne -> [elt >= moy] = pivot
				bug("\nRECURSION", 1);
				send_to_a(all);
				bug("\nEND  OF RECURSION\n", 1);
				return;
			}
			else if (val(e) < all->v_nxtp)
				stock_low_values_b(all);
			if (all->sk_b)
				e = all->sk_b;
		}
		if (all->sk_a && val(ft_lstlast_e(all->sk_a)) == all->v_nxtp)
			set_pivot_at_top_a(all);
		// if (is_sk_ordered(all->sk_b))
		// 	return (bug("END of send to A. pb0", 0));
		while (all->sk_b && is_last_seen(all->sk_b))
			send_low_values_a(all);

		bug("end of while of send_to_b", 0);
	}
	bug("END of send to A. pb", 0);
}