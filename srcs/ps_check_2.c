/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timotheein <timotheein@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 22:47:51 by timotheein        #+#    #+#             */
/*   Updated: 2021/05/15 13:35:46 by timotheein       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		in_order(t_all *all)
{
	if (all->p_low == 0 && all->p_hig == 1)
		return (0);
	if (all->p_low == 1 && all->p_hig == 2)
		return (0);
	if (all->p_low == 2 && all->p_hig == 0)
		return (0);
	return (1);
}

void	find_lowest_values_a(t_all *all)
{
	t_elt	*elt;
	int		i;

	i = 1;
	elt = all->sk_a;
	all->p_low = 0;
	all->v_low = ft_atoi(elt->content);
	all->v_hig = all->v_low + 1;
	elt = elt->next;
	while (elt)
	{
		if (ft_atoi(elt->content) < all->v_low)
		{
			all->v_low = ft_atoi(elt->content);
			all->p_low = i;
		}
		else if (ft_atoi(elt->content) >= all->v_hig)
		{
			all->v_hig = ft_atoi(elt->content);
			all->p_hig = i;
		}
		i++;
		elt = elt->next;
	}
	return ;
}

int		is_sk_ordered(t_elt *e, int s)
{
	int		i;
	t_elt	*elt;

	if (!e || !(e->next))
		return (1);
	elt = e;
	if (elt)
		i = val(elt);
	while (elt && elt->next)
	{
		if (s * (val(elt->next)) <= s * i)
			return (0);
		i = val(elt->next);
		elt = elt->next;
	}
	return (1);
}

int		init(t_all *all)
{
	all->p_low = 0;
	all->v_low = all->min;
	all->p_hig = 0;
	all->v_hig = all->max;
	return (0);
}

void	find_close_mid_values(t_all *all)
{
	t_elt	*elt;
	int		i;
	int		e;

	i = init(all);
	elt = all->sk_a;
	while (elt)
	{
		e = ft_atoi(elt->content);
		if (e == all->min)
			all->p_min = i;
		if ((e <= all->midd) && (all->midd - all->v_low >= all->midd - e))
		{
			all->v_low = e;
			all->p_low = i;
		}
		else if ((e > all->midd) && (all->v_hig - all->midd >= e - all->midd))
		{
			all->v_hig = e;
			all->p_hig = i;
		}
		i++;
		elt = elt->next;
	}
}
