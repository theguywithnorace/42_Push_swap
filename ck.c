/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ck.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timotheein <timotheein@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:27:13 by timotheein        #+#    #+#             */
/*   Updated: 2021/05/01 17:44:50 by timotheein       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main(int ac, char **av)
{
    t_all *all;

    all = 0;
    if (!(all = malloc(sizeof(t_all))))
        return (0);
    intitialize_all(all);
    if (!ft_strcmp(av[1], "-v"))
        all->bonus = 1;
    if (ac < 2 || (ac < 3 && all->bonus))
        return (0);
    if (!check_n_get_arguments(ac, av, all))
        return (Error_arguments(all));
    if (!read_instruction(all))
        return (Error_instruction(all));
    printf("WESHWESH : %s\n", all->instruction->content);

    if (!execute_instruction(all))
        return (Error_execution(all));
    all->check = check_final_order(all);
    check_result(all);
    freeer(all);
    return (0);
}
