/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ck.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timotheein <timotheein@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:27:13 by timotheein        #+#    #+#             */
/*   Updated: 2021/04/28 10:21:41 by timotheein       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int Error_arguments(void)
{
    printf("Error argument\n");
    return (0);
}

int Error_instruction(void)
{
    printf("Error instruction\n");
    return (0);
}
int Error_execution(void)
{
    printf("Error execution\n");
    return (0);
}

void check_result(t_all *all)
{
    if (all->check == 0)
        write(1, "OK\n", 3);
    if (all->check == -1)
        write(1, "KO\n", 3);
    return;
}

int main(int ac, char **av)
{
    int i;
    t_all *all;

    all = 0;
    if (!(all = malloc(sizeof(t_all))))
        return (0);
    if (ac == 0 || !intitialize_all(all))
        return (0);

    if (!check_n_get_arguments(ac, av, all))
        return (Error_arguments()); //need to free the lists
    if (!read_instruction(all))
        return (Error_instruction());
    if (!execute_instruction(all))
        return (Error_execution());
    check_result(all);
    return (0);
}
