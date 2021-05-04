/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timotheein <timotheein@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 00:11:18 by timotheein        #+#    #+#             */
/*   Updated: 2021/05/02 21:41:07 by timotheein       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	error_arguments(t_all *all)
{
	write(1, "Error\n", 6);
	freeer(all);
	return (0);
}

int	error_instruction(t_all *all)
{
	write(1, "Error\n", 6);
	freeer(all);
	return (0);
}

int	error_execution(t_all *all)
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
	return;
}
