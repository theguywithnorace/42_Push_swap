/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timotheein <timotheein@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 20:05:41 by timotheein        #+#    #+#             */
/*   Updated: 2021/05/15 09:34:09 by timotheein       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void send_low_values_b(t_all *all)
{
	if (!all->sk_a)
		return;
	// bug("send_low_values_b", 0);
	print_action("pb", all);
}

void send_pivot_b(t_all *all)
{
	if (!all->sk_a)
		return;
	// bug("send_pivot_b", 0);

	print_action("pb", all);
	if (all->sk_b->is_pivot == OLD)
		set_next_pivot(all, all->sk_a);
	else
		all->sk_b->is_pivot = OLD;
	if (all->sk_b)
		if (!is_all_end_sup(all->sk_a, all->v_nxtp))
			print_action("rb", all);
	// bug("send_pivot_b", all->sk_b->is_pivot);

	// //print_situation_b(all);
}

void stock_hig_values_a(t_all *all)
{
	if (!all->sk_a)
		return;
	// bug("stock_hig_values_a", val(all->sk_a));
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
	if (!all->sk_a)
		return;
	// bug("send_hig_values_b", val(all->sk_a));

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
	t_elt *bk;

	bk = e;
	if (!e)
		return (0);
	while (e)
	{
		if (val(e) <= max)
		{
			// bug("not all sup for", val(e));
			return (0);
		}
		e = e->next;
	}
	e = bk;
	if (is_sk_ordered(e, 1))
	{
		while (e)
		{
			e->is_pivot = OLD;
			e = e->next;
		}
	}
	// bug("ALL END IS sup than pivot", 1);
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

void set_pivot_at_top_a(t_all *all)
{
	if (!all->sk_a)
		return;
	if (val(all->sk_a) == all->v_nxtp)
		return;
	print_action("rra", all);
}

void set_pivot_at_top_b(t_all *all)
{
	if (!all->sk_b)
		return;
	if (val(all->sk_b) == all->v_nxtp)
		return;
	print_action("rrb", all);
}

int less_elt_than(int n, t_elt *e, t_all *all)
{
	int i;
	t_elt *elt;

	i = 0;
	elt = e;
	if (!elt)
		return (0);
	while (elt && elt->is_pivot != OLD)
	{
		i++;
		elt = elt->next;
	}
	// bug("less_elt_than", i);
	if (i > n)
		return (0);
	all->p_tomov = i;

	return (1);
}

void quick_send_b(t_all *all)
{
	if (!all->sk_a)
		return;
	all->sk_a->is_pivot = OLD;
	// bug("send less than 1 elt", 1);
	print_action("pb", all);
}

void back_up_if_bked_a(t_all *all)
{
	t_elt *e;

	if (!all->sk_a)
		return;
	e = all->sk_a;
	if (e->is_pivot == BKED)
	{
		while (e && e->is_pivot == BKED)
		{
			e->is_pivot = 0;
			e = e->next;
		}
		return;
	}
	while ((ft_lstlast_e(e))->is_pivot == BKED)
	{
		print_action("rra", all);
		all->sk_a->is_pivot = 0;
		e = all->sk_a;
	}
}

void back_up_if_bked_b(t_all *all)
{
	t_elt *e;

	if (!all->sk_b)
		return;
	e = all->sk_b;
	if (e->is_pivot == BKED)
	{
		while (e && e->is_pivot == BKED)
		{
			e->is_pivot = 0;
			e = e->next;
		}
		return;
	}
	while ((ft_lstlast_e(e))->is_pivot == BKED)
	{
		print_action("rrb", all);
		all->sk_b->is_pivot = 0;

		e = all->sk_b;
	}
}