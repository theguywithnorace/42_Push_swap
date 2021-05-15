/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_opti_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timotheein <timotheein@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 17:47:41 by timotheein        #+#    #+#             */
/*   Updated: 2021/05/15 13:37:16 by timotheein       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	opti_a(t_all *all, t_elt *e)
{
	if (all->p_tomov < 2)
		quick_send_b(all);
	if (all->p_tomov == 2)
	{
		if (val(e) > val(e->next))
			print_action("sa", all);
		quick_send_b(all);
		quick_send_b(all);
	}
	if (all->p_tomov == 3)
		algo_3_a(all, e);
}

void	opti_b(t_all *all, t_elt *e)
{
	if (all->p_tomov < 2)
		quick_send_a(all);
	if (all->p_tomov == 2)
	{
		if (val(all->sk_b) < val(all->sk_b->next))
			print_action("sb", all);
		quick_send_a(all);
		quick_send_a(all);
	}
	if (all->p_tomov == 3)
		algo_3_b(all, e);
}
