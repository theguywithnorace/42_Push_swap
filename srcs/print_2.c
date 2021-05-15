/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timotheein <timotheein@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 17:38:37 by timotheein        #+#    #+#             */
/*   Updated: 2021/05/15 13:28:42 by timotheein       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_situation_a(t_all *all)
{
	t_elt *e;

	if (!all->sk_a)
		return ;
	e = all->sk_a;
	while (e)
	{
		ft_putstr_fd("elt no :", 1);
		ft_putstr_fd(e->content, 1);
		ft_putstr_fd(" -> is_pivot: ", 1);
		ft_putnbr_fd(e->is_pivot, 1);
		ft_putstr_fd("\n", 1);
		e = e->next;
	}
}

void	print_situation_b(t_all *all)
{
	t_elt *e;

	if (!all->sk_b)
		return ;
	e = all->sk_b;
	while (e)
	{
		ft_putstr_fd("elt no :", 1);
		ft_putstr_fd(e->content, 1);
		ft_putstr_fd(" -> is_pivot: ", 1);
		ft_putnbr_fd(e->is_pivot, 1);
		ft_putstr_fd(" \n", 1);
		e = e->next;
	}
	write(1, "\n", 1);
}

void	bug(char *s, int n)
{
	ft_putstr_fd(s, 1);
	ft_putstr_fd(": ", 1);
	ft_putnbr_fd(n, 1);
	ft_putendl_fd("", 1);
}
