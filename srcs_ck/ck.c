/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ck.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timotheein <timotheein@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:27:13 by timotheein        #+#    #+#             */
/*   Updated: 2021/04/21 21:05:11 by timotheein       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void check_result(t_all *all)
{
    if (all->check == 0)
        write(1, "OK\n", 3);
    if (all->check == -1)
        write(1, "KO\n", 3);
    return ;
}

int main(int ac, char **av)
{
    int i;
    t_all *all;

    all = 0;   
    if (ac == 0 || !intitialize_all(all))
        return (0);
    
    if (!check_n_get_arguments(ac, av, all))
        return (Error_arguments()); //need to free the lists
    if(!read_instructions(all))
        return (Error_instruction());
    execute_instructions(all);
    check_result(all);
    return (0);
}
