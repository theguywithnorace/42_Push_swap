/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timotheein <timotheein@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 21:09:48 by timotheein        #+#    #+#             */
/*   Updated: 2021/05/09 18:58:25 by timotheein       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_all *all)
{
	t_elt *elt;
	t_elt *elta;

	if (all->sk_a && all->sk_a->next)
	{
		elt = all->sk_a;
		all->sk_a = all->sk_a->next;
		elta = all->sk_a;
		while (elta->next)
			elta = elta->next;
		elta->next = elt;
		elt->next = 0;
	}
}

void	rb(t_all *all)
{
	t_elt *elt;
	t_elt *eltb;

	if (all->sk_b && all->sk_b->next)
	{
		elt = all->sk_b;
		all->sk_b = all->sk_b->next;
		eltb = all->sk_b;
		while (eltb->next)
			eltb = eltb->next;
		eltb->next = elt;
		elt->next = 0;
	}
}

void	rr(t_all *all)
{
	ra(all);
	rb(all);
}

void	rra(t_all *all)
{
	t_elt *elta;
	t_elt *eltz;

	if (all->sk_a && all->sk_a->next)
	{
		elta = all->sk_a;
		while (elta->next && elta->next->next)
			elta = elta->next;
		eltz = elta->next;
		eltz->next = all->sk_a;
		elta->next = 0;
		all->sk_a = eltz;
	}
}

void	rrb(t_all *all)
{
	t_elt *eltb;
	t_elt *eltz;

	if (all->sk_b && all->sk_b->next)
	{
		eltb = all->sk_b;
		while (eltb->next && eltb->next->next)
			eltb = eltb->next;
		eltz = eltb->next;
		eltz->next = all->sk_b;
		eltb->next = 0;
		all->sk_b = eltz;
	}
}
