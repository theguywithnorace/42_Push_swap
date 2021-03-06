/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ck.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timotheein <timotheein@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:27:13 by timotheein        #+#    #+#             */
/*   Updated: 2021/05/04 22:06:56 by timotheein       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_all	*all;

	all = 0;
	if (!(all = malloc(sizeof(t_all))))
		return (0);
	intitialize_all(all);
	if ((ac > 1) && !(ft_strcmp(av[1], "-v")))
		all->bonus = 1;
	if (ac < 2 || (ac < 3 && all->bonus))
		return (freeer(all));
	if (!check_n_get_arguments(ac, av, all))
		return (error_arguments(all));
	if (!read_instruction(all))
		return (error_instruction(all));
	if (!execute_instruction(all))
		return (error_execution(all));
	all->check = check_final_order(all);
	check_result(all);
	return (freeer(all));
}
