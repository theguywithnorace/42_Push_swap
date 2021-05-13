/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timotheein <timotheein@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 20:05:41 by timotheein        #+#    #+#             */
/*   Updated: 2021/05/13 16:19:46 by timotheein       ###   ########.fr       */
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
	if (all->sk_b->is_pivot == OLD)
		set_next_pivot(all, all->sk_a);
	else
		all->sk_b->is_pivot = OLD;
	if (!is_all_end_sup(all->sk_a, all->v_nxtp))
		print_action("rb", all);
	bug("send_pivot_b", all->sk_b->is_pivot);

	// print_situation_b(all);
}

void stock_hig_values_a(t_all *all)
{
	bug("stock_hig_values_a", val(all->sk_a));
	all->sk_a->is_pivot = BKED;
	print_action("ra", all);
}

// void set_pivot_top_b(t_all *all)
// {
// 	bug("set_pivot_top_b", 0);

// 	if (val(ft_lstlast_e(all->sk_b)) == all->v_nxtp)
// 		print_action("rrb", all);
// 	all->sk_b->is_pivot = OLD;
// }

void send_hig_values_b(t_all *all)
{
	bug("send_hig_values_b", val(all->sk_a));

	if (all->sk_a->is_pivot != BKED) // la premiere  valeur du sk a deja été vue
		print_action("rra", all);
	print_action("pb", all);
	all->sk_b->is_pivot = 0;
}

int is_last_seen(t_elt *e)
{
	t_elt *f;

	// if (e)
	// 	bug("is_last_seen", val(e));
	// else
	// 	bug("end of is_last_seen", 0);

	if (!e)
		return (0);
	f = ft_lstlast_e(e);
	if (f->is_pivot == BKED)
		return (1);
	return (0);
}

int is_all_end_sup(t_elt *e, int max)
{
	while (e)
	{
		if (val(e) <= max)
			return (0);
		e = e->next;
	}
	bug("ALL END IS sup than pivot", 1);
	return (1);
}

void set_bked_sk(t_elt *e)
{
	while (e)
	{
		e->is_pivot = BKED;
		e = e->next;
	}
}

void set_pivot_at_top(t_all *all)
{
	if (all->sk_b)
		bug("LAST of sk_b", val(ft_lstlast_e(all->sk_b)));
	if ((all->sk_b && val(all->sk_b) == all->v_nxtp) || (all->sk_b && val(all->sk_a) == all->v_nxtp))
		return;
	if (all->sk_a && val(ft_lstlast_e(all->sk_a)) == all->v_nxtp)
		print_action("rra", all);
	else if (all->sk_b && val(ft_lstlast_e(all->sk_b)) == all->v_nxtp)
		print_action("rrb", all);
}

int less_elt_than(int n, t_elt *e)
{
	int i;

	i = 0;
	while (e && e->is_pivot != OLD)
	{
		i++;
		e = e->next;
	}
	bug("less_elt_than", i);
	if (i > n)
		return (0);
	return (1);
}

void quick_send_b(t_all *all)
{
	all->sk_a->is_pivot = OLD;
	bug("send less than 1 elt", 1);
	print_action("pb", all);
}