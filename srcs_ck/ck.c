/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ck.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timotheein <timotheein@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:27:13 by timotheein        #+#    #+#             */
/*   Updated: 2021/04/29 23:20:58 by timotheein       ###   ########.fr       */
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
int Error_basic(void)
{
    printf("basic Error\n");
    return (0);
}

void check_result(t_all *all)
{
    if (all->check == 1)
        write(1, "OK\n", 3);
    if (all->check == -1)
        write(1, "KO\n", 3);
    return;
}

void print_elt(t_all *all)
{
    t_list *elt;

    elt = all->sk_a;
    printf("elements sk_a :\n");
    while (elt)
    {
        printf("->%s-\n", elt->content);
        elt = elt->next;
    }
    elt = all->sk_b;
    printf("elements sk_b :\n");
    while (elt)
    {
        printf("->%s-\n", elt->content);
        elt = elt->next;
    }
    printf("END\n\n");
}

int main(int ac, char **av)
{
    t_all *all;

    all = 0;
    printf("\n\n%d\n\n", 3/2);
    if (!(all = malloc(sizeof(t_all))) || !intitialize_all(all))
        return (Error_basic());
    if (ac < 2)
        return (0);
    if (!check_n_get_arguments(ac, av, all))
        return (Error_arguments()); //need to free the lists
    print_elt(all);
    if (!read_instruction(all))
        return (Error_instruction());
    if (!execute_instruction(all))
        return (Error_execution());
    // print_elt(all);
    all->check = check_final_order(all);
    check_result(all);
    return (0);
}
