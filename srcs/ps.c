/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timotheein <timotheein@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 22:37:57 by timotheein        #+#    #+#             */
/*   Updated: 2021/05/13 12:52:23 by timotheein       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void execute_algo(t_all *all)
{
	while (!is_sk_ordered(all->sk_a))
	{
		bug("BEGIN get_pivots A", 1);
		get_pivots(all->sk_a, 1); //parcours en sommant jusqu'a [fin ou pivot] -> moyenne -> [elt >= moy] = pivot
		print_situation_a(all);
		send_to_b(all);
		bug("BEGIN get_pivots B", 1);
		get_pivots(all->sk_b, -1); //parcours en sommant jusqu'a [fin ou pivot] -> moyenne -> [elt >= moy] = pivot
		send_to_a(all);
	}
}

int main(int ac, char **av)
{
	t_all *all;

	all = 0;
	if (ac < 2)
		return (0);
	if (!(all = malloc(sizeof(t_all))))
		return (0);
	intitialize_all(all);
	all->p_s = 1;
	if (!ft_strcmp(av[1], "-v"))
		all->bonus = 1;
	if (ac < 3 && all->bonus)
		return (freeer(all));
	if (!check_n_get_arguments(ac, av, all))
		return (error_arguments(all));
	print_init(all);
	if (all->len_t == 3)
		execute_short_algo(all);
	else
		execute_algo(all);
}
