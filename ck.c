/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ck.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timotheein <timotheein@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:27:13 by timotheein        #+#    #+#             */
/*   Updated: 2021/05/04 21:05:14 by timotheein       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main(int ac, char **av)
{
    t_all *all;

    all = 0;
    if (!(all = malloc(sizeof(t_all))))
        return (0);
    // write(1, "HEY5\n", 5);

    intitialize_all(all);
    // write(1, "HEY5\n", 5);

    if ((ac > 1) && !(ft_strcmp(av[1], "-v")))
        all->bonus = 1;
    // write(1, "HEY5\n", 5);

    if (ac < 2 || (ac < 3 && all->bonus))
        return (freeer(all));
    // write(1, "HEY5\n", 5);

    if (!check_n_get_arguments(ac, av, all))
        return (error_arguments(all));
    // write(1, "HEY5\n", 5);

    if (!read_instruction(all))
        return (error_instruction(all));
    // write(1, "HEY5\n", 5);

    if (!execute_instruction(all))
        return (error_execution(all));
    // write(1, "HEY5\n", 5);

    all->check = check_final_order(all);
    check_result(all);
    return (freeer(all));
}
