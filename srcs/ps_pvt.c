/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_pvt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timotheein <timotheein@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 20:05:41 by timotheein        #+#    #+#             */
/*   Updated: 2021/05/15 13:40:35 by timotheein       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	get_pivots(t_elt *elt, int s)
{
	long long	sum;
	int			midd;

	sum = 0;
	while (elt)
	{
		while (elt && (elt->is_pivot == OLD))
			elt = elt->next;
		if (elt)
		{
			midd = find_midd(elt);
			find_pivot(elt, midd, s);
		}
		while (elt && (elt->is_pivot != OLD))
			elt = elt->next;
	}
}

int		find_midd(t_elt *elt)
{
	int			i;
	long long	sum;
	int			midd;

	sum = 0;
	i = 0;
	while (elt && (elt->is_pivot != OLD))
	{
		if (elt->is_pivot == BKED || elt->is_pivot == PIVOT)
			elt->is_pivot = 0;
		sum += (long long)ft_atoi(elt->content);
		elt = elt->next;
		i++;
	}
	midd = (int)(sum / i);
	return (midd);
}

void	find_pivot(t_elt *elt, int midd, int s)
{
	int		v;
	t_elt	*bk;

	(void)s;
	bk = elt;
	if (elt)
		v = val(elt);
	while (elt && (elt->is_pivot != OLD))
	{
		if (midd - val(elt) >= 0
				&& ft_abs(midd - val(elt)) < ft_abs(midd - v))
			v = val(elt);
		elt = elt->next;
	}
	elt = bk;
	while (elt && (elt->is_pivot != OLD))
	{
		if (val(elt) == v)
			elt->is_pivot = PIVOT;
		elt = elt->next;
	}
}

int		in_packet(t_elt *e, int nxtp)
{
	if (!e || (e->is_pivot == BKED
				&& !is_all_end_sup(e, nxtp)) || e->is_pivot == OLD)
		return (0);
	return (1);
}

void	set_next_pivot(t_all *all, t_elt *e)
{
	while (e)
	{
		if (e->is_pivot == PIVOT)
		{
			all->v_nxtp = ft_atoi(e->content);
			return ;
		}
		e = e->next;
	}
}
