/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timotheein <timotheein@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 22:47:51 by timotheein        #+#    #+#             */
/*   Updated: 2021/05/15 13:04:22 by timotheein       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void execute_short_algo(t_all *all)
{
	find_lowest_values_a(all);
	if (!in_order(all))
		print_action("sa", all);
	find_lowest_values_a(all);
	if (!is_sk_ordered(all->sk_a, 1))
	{
		if (all->p_low == 1)
			print_action("ra", all);
		if (all->p_low == 2)
			print_action("rra", all);
	}
	freeer(all);
}

void end_algo(t_all *all)
{
	if (!(is_sk_ordered(all->sk_a, 1) && all->sk_b == 0))
	{
		find_close_mid_values(all);
		send_mid_hig_to_top(all);
		while (all->sk_b)
			print_action("pa", all);
		find_close_mid_values(all);
		make_final_ordering(all);
	}
	freeer(all);
}


int		sk_a_ordered_by_packet(t_all *all)
{
	t_elt	*elt;
	int		k;

	elt = all->sk_a;
	k = ft_atoi(elt->content);
	if (!elt->next || !elt->next->next)
		return (1);
	elt = elt->next;
	while (elt && (k <= all->max))
	{
		if (k > ft_atoi(elt->content))
			return (0);
		k = ft_atoi(elt->content);
		elt = elt->next;
	}
	k = all->min;
	while (elt)
	{
		if (k > ft_atoi(elt->content))
			return (0);
		k = ft_atoi(elt->content);
		elt = elt->next;
	}
	return (1);
}

void	find_middle_value(t_all *all)
{
	t_elt		*elt;
	long long	sum;
	int			i;

	sum = 0;
	i = 0;
	elt = all->sk_a;
	all->min = ft_atoi(elt->content);
	all->max = ft_atoi(elt->content);
	while (elt)
	{
		if (ft_atoi(elt->content) < all->min)
			all->min = ft_atoi(elt->content);
		else if (ft_atoi(elt->content) > all->max)
			all->max = ft_atoi(elt->content);
		sum = sum + ft_atoi(elt->content);
		i++;
		elt = elt->next;
	}
	sum = sum / i;
	all->midd = (int)sum;
	if (all->len_t <= 5)
		all->midd = all->min;
}

void	find_value_to_move(t_all *all)
{
	int steps_l;
	int steps_h;

	if (all->p_low <= ((all->len_a) / 2))
		steps_l = all->p_low;
	else
		steps_l = all->len_a - all->p_low;
	if (all->p_hig <= ((all->len_a) / 2))
		steps_h = all->p_hig;
	else
		steps_h = all->len_a - all->p_hig + 1;
	if (((steps_h > steps_l) || all->v_hig == all->max) && !(all->min_sent))
	{
		all->is_tomov_low = 1;
		all->p_tomov = all->p_low;
		if (all->p_low == all->p_min)
			all->min_sent = 1;
	}
	else
	{
		all->is_tomov_low = 0;
		all->p_tomov = all->p_hig;
	}
}
