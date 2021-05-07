/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timotheein <timotheein@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 17:38:37 by timotheein        #+#    #+#             */
/*   Updated: 2021/05/05 11:43:59 by timotheein       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_init(t_all *all)
{
	if (all->bonus)
		write(1, "\nInitial situation : \n\n", 23);
	if (all->bonus)
		print_elt(all);
}

void	print_action(char *action, t_all *all)
{
	execute(action, all);
	if (all->bonus)
	{
		write(1, "-> Executing ", 13);
		write(1, action, ft_strlen_ps(action));
		write(1, " ->\n\n", 5);
		print_elt(all);
	}
	else if (all->p_s)
	{
		write(1, action, ft_strlen_ps(action));
		write(1, "\n", 1);
	}
}

int		write_a(t_list **ea, int a, t_all *all)
{
	int i;

	i = 0;
	write(1, " ", 1);
	if (ea == 0)
	{
		while (++i <= (max_lgth(all->sk_a)))
			write(1, " ", 1);
		write(1, " ", 1);
		return (a);
	}
	while (++i <= ((max_lgth(all->sk_a) - ft_strlen_ps((*ea)->content))))
		write(1, " ", 1);
	write(1, (*ea)->content, ft_strlen_ps((*ea)->content));
	write(1, " ", 1);
	(*ea) = (*ea)->next;
	a--;
	return (a);
}

int		write_b(t_list **eb, int b, t_all *all)
{
	int i;

	i = 0;
	write(1, " ", 1);
	if (eb == 0)
	{
		while (++i <= (max_lgth(all->sk_b)))
			write(1, " ", 1);
		write(1, " ", 1);
		return (b);
	}
	while (++i <= ((max_lgth(all->sk_b) - ft_strlen_ps((*eb)->content))))
		write(1, " ", 1);
	write(1, (*eb)->content, ft_strlen_ps((*eb)->content));
	write(1, " ", 1);
	(*eb) = (*eb)->next;
	b--;
	return (b);
}

void	print_elt(t_all *all)
{
	t_list	*ea;
	t_list	*eb;
	int		a;
	int		b;

	ea = all->sk_a;
	eb = all->sk_b;
	a = ft_lstsize(ea);
	b = ft_lstsize(eb);
	while (ft_max(a, b) > 0)
	{
		if (a >= b)
			a = write_a(&ea, a, all);
		else
			a = write_a(0, a, all);
		write(1, "   ", 3);
		if (b > a)
			b = write_b(&eb, b, all);
		write(1, "\n", 1);
	}
	write_tacks(all);
}
