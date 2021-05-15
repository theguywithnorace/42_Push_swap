/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_actions_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timotheein <timotheein@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 20:05:41 by timotheein        #+#    #+#             */
/*   Updated: 2021/05/15 13:33:17 by timotheein       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		is_all_end_sup(t_elt *e, int max)
{
	t_elt *bk;

	bk = e;
	if (!e)
		return (0);
	while (e)
	{
		if (val(e) <= max)
			return (0);
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
	return (1);
}

void	set_bked_sk(t_elt *e)
{
	while (e)
	{
		e->is_pivot = BKED;
		e = e->next;
	}
}

void	set_pivot_at_top_a(t_all *all)
{
	if (!all->sk_a)
		return ;
	if (val(all->sk_a) == all->v_nxtp)
		return ;
	print_action("rra", all);
}

void	set_pivot_at_top_b(t_all *all)
{
	if (!all->sk_b)
		return ;
	if (val(all->sk_b) == all->v_nxtp)
		return ;
	print_action("rrb", all);
}

int		less_elt_than(int n, t_elt *e, t_all *all)
{
	int		i;
	t_elt	*elt;

	i = 0;
	elt = e;
	if (!elt)
		return (0);
	while (elt && elt->is_pivot != OLD)
	{
		i++;
		elt = elt->next;
	}
	if (i > n)
		return (0);
	all->p_tomov = i;
	return (1);
}
