/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_opti.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timotheein <timotheein@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 17:47:41 by timotheein        #+#    #+#             */
/*   Updated: 2021/05/15 13:06:34 by timotheein       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void set_ispvt(t_elt *e, int k, int min)
{
	while (e && e->is_pivot != OLD)
	{
		if (val(e) == min)
		{
			e->is_pivot = k;
			return;
		}
		e = e->next;
	}
}

int value_not_set(t_elt *e)
{
	while (e && e->is_pivot != OLD)
	{
		if (e->is_pivot < 10)
			return (1);
		e = e->next;
	}
	return (0);
}

void set_order(t_elt *e, t_all *all)
{
	int k;
	int min;
	t_elt *bk;

	(void)all;
	bk = e;
	k = 11;
	while (e && value_not_set(e))
	{
		while (e && e->is_pivot > 10)
			e = e->next;
		min = val(e);
		e = bk;
		while (e && e->is_pivot != OLD)
		{
			if (e->is_pivot < 11 && val(e) < min)
				min = val(e);
			e = e->next;
		}
		set_ispvt(bk, k, min);
		k++;
		e = bk;
	}
}

void algo_3_a(t_all *all, t_elt *e)
{
	t_elt *elt;

	set_order(e, all);
	print_action("pb", all);
	if (val(all->sk_a) > val(all->sk_a->next))
		print_action("sa", all);
	print_action("pb", all);
	if (all->sk_b->is_pivot == 11)
		print_action("sb", all);
	print_action("pb", all);
	if (all->sk_b->is_pivot == 12)
		print_action("sb", all);
	elt = all->sk_b;
	while (elt && elt->is_pivot > 10)
	{
		elt->is_pivot = -1;
		elt = elt->next;
	}
	return;
}

void algo_3_b(t_all *all, t_elt *e)
{
	t_elt *elt;

	set_order(e, all);
	print_action("pa", all);
	if (val(all->sk_b) < val(all->sk_b->next))
		print_action("sb", all);
	print_action("pa", all);
	if (all->sk_a->is_pivot == 13)
		print_action("sa", all);
	print_action("pa", all);
	if (all->sk_a->is_pivot == 12)
		print_action("sa", all);
	elt = all->sk_a;
	while (elt && elt->is_pivot > 10)
	{
		elt->is_pivot = -1;
		elt = elt->next;
	}
	return;
}
