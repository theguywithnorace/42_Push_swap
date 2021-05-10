/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timotheein <timotheein@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 00:11:18 by timotheein        #+#    #+#             */
/*   Updated: 2021/05/10 22:40:40 by timotheein       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void print_situation_a(t_all *all)
{
	t_elt *e;

	e = all->sk_a;
	while (e)
	{
		ft_putstr_fd("elt no :", 1);
		ft_putstr_fd(e->content, 1);
		ft_putstr_fd(" -> is_pivot: ", 1);
		ft_putnbr_fd(e->is_pivot, 1);
		ft_putstr_fd(" // ", 1);
		e = e->next;
	}
}

void bug(char *s, int n)
{
	ft_putstr_fd(s, 1);
	ft_putstr_fd(": ", 1);
	ft_putnbr_fd(n, 1);
	ft_putendl_fd("",1);
}

int		error_arguments(t_all *all)
{
	write(1, "Error\n", 6);
	freeer(all);
	return (0);
}

int		error_instruction(t_all *all)
{
	write(1, "Error\n", 6);
	freeer(all);
	return (0);
}

int		error_execution(t_all *all)
{
	write(1, "Error\n", 6);
	freeer(all);
	return (0);
}

void	check_result(t_all *all)
{
	if (all->check == 1)
		write(1, "OK\n", 3);
	if (all->check == -1)
		write(1, "KO\n", 3);
	return ;
}

int		ft_strlen_ps(const char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
