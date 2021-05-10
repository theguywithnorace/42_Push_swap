/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_pvt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timotheein <timotheein@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 20:05:41 by timotheein        #+#    #+#             */
/*   Updated: 2021/05/10 22:10:33 by timotheein       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void get_pivots(t_elt *elt)
{
	long long sum;
	int midd;

	sum = 0;
	while (elt)
	{
		midd = find_midd(elt);
		bug("midd", midd);
		find_pivot(elt, midd);
		while (elt && (elt->is_pivot != STOP))
			elt = elt->next;
		if (elt)
			elt = elt->next;
	}
}

int find_midd(t_elt *elt)
{
	int i;
	long long sum;
	int midd;

	sum = 0;
	i = 0;
	while (elt && (elt->is_pivot != STOP))
	{
		sum += (long long)ft_atoi(elt->content);
		elt = elt->next;
		i++;
	}
	midd = (int)(sum / i);
	return (midd);
}

void find_pivot(t_elt *elt, int midd)
{
	int v;
	t_elt *bk;

	bk = elt;
	if (elt)
		v = val(elt);
	while (elt && (elt->is_pivot != STOP))
	{
		if (midd - val(elt) > 0 && midd - val(elt) < midd - v)
			v = val(elt);
		elt = elt->next;
	}
	bug("val of pivot", v);
	elt = bk;
	while (elt)
	{
		if (val(elt) == v)
		{
			bug("is_pivot foud for val", v);
			elt->is_pivot = PIVOT;
		}
		elt = elt->next;
	}
}

int in_packet(t_all *all, t_elt *e)
{
	(void)all;
	if (!e || e->is_pivot == BKED || e->is_pivot == STOP)
	{
		bug("out of packet", 0);
		return (0);
	}
	bug("IN DA PACKET", 0);
	return (1);
}

void set_next_pivot(t_all *all, t_elt *e)
{
	while (e)
	{
		if (e->is_pivot == PIVOT)
		{
			all->v_nxtp = ft_atoi(e->content);
			return;
		}
		e = e->next;
	}
}