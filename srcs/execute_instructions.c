/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timotheein <timotheein@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 11:26:50 by timotheein        #+#    #+#             */
/*   Updated: 2021/05/07 22:19:53 by timotheein       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		check_final_order(t_all *all)
{
	int		i;
	t_list	*elt;

	if (all->sk_b)
		return (-1);
	elt = all->sk_a;
	if (elt)
		i = ft_atoi(elt->content);
	while (elt && elt->next)
	{
		if (ft_atoi(elt->next->content) <= i)
			return (-1);
		i = ft_atoi(elt->next->content);
		elt = elt->next;
	}
	return (1);
}

void	execute(char *action, t_all *all)
{
	if (!ft_strcmp(action, "sa"))
		sa(all);
	else if (!ft_strcmp(action, "sb"))
		sb(all);
	else if (!ft_strcmp(action, "ss"))
		ss(all);
	else if (!ft_strcmp(action, "pa"))
		pa(all);
	else if (!ft_strcmp(action, "pb"))
		pb(all);
	else if (!ft_strcmp(action, "ra"))
		ra(all);
	else if (!ft_strcmp(action, "rb"))
		rb(all);
	else if (!ft_strcmp(action, "rr"))
		rr(all);
	else if (!ft_strcmp(action, "rra"))
		rra(all);
	else if (!ft_strcmp(action, "rrb"))
		rrb(all);
	else if (!ft_strcmp(action, "rrr"))
		rrr(all);
}

int		execute_instruction(t_all *all)
{
	t_list	*elt;

	elt = all->instruction;
	print_init(all);
	while (elt)
	{
		print_action(elt->content, all);
		elt = elt->next;
	}
	return (1);
}
