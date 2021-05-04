/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timotheein <timotheein@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 22:47:51 by timotheein        #+#    #+#             */
/*   Updated: 2021/05/04 22:23:28 by timotheein       ###   ########.fr       */
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
	t_list	*elt;
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

int		check_order_sk_a(t_all *all)
{
	int		i;
	t_list	*elt;

	if (!all->sk_a || !(all->sk_a->next))
		return (1);
	elt = all->sk_a;
	if (elt)
		i = ft_atoi(elt->content);
	while (elt && elt->next)
	{
		if (ft_atoi(elt->next->content) <= i)
			return (0);
		i = ft_atoi(elt->next->content);
		elt = elt->next;
	}
	return (1);
}
