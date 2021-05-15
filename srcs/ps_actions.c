/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timotheein <timotheein@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 20:05:41 by timotheein        #+#    #+#             */
/*   Updated: 2021/05/15 13:32:38 by timotheein       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	send_low_values_b(t_all *all)
{
	if (!all->sk_a)
		return ;
	print_action("pb", all);
}

void	send_pivot_b(t_all *all)
{
	if (!all->sk_a)
		return ;
	print_action("pb", all);
	if (all->sk_b->is_pivot == OLD)
		set_next_pivot(all, all->sk_a);
	else
		all->sk_b->is_pivot = OLD;
	if (all->sk_b)
		if (!is_all_end_sup(all->sk_a, all->v_nxtp))
			print_action("rb", all);
}

void	stock_hig_values_a(t_all *all)
{
	if (!all->sk_a)
		return ;
	all->sk_a->is_pivot = BKED;
	print_action("ra", all);
}

void	send_hig_values_b(t_all *all)
{
	if (!all->sk_a)
		return ;
	if (all->sk_a->is_pivot != BKED)
		print_action("rra", all);
	print_action("pb", all);
	all->sk_b->is_pivot = 0;
}

int		is_last_seen(t_elt *e)
{
	t_elt *f;

	if (!e)
		return (0);
	f = ft_lstlast_e(e);
	if (f->is_pivot == BKED)
		return (1);
	return (0);
}
