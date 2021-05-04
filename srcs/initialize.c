/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timotheein <timotheein@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:54:04 by timotheein        #+#    #+#             */
/*   Updated: 2021/05/04 20:41:37 by timotheein       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		intitialize_all(t_all *all)
{
	all->check = -1;
	all->min_sent = 0;
	all->len_a = 0;
	all->p_low = 0;
	all->p_s = 0;
	all->bonus = 0;
	all->instruction = 0;
	all->sk_a = 0;
	all->sk_b = 0;
	return (1);
}

void	rrr(t_all *all)
{
	rra(all);
	rrb(all);
}
