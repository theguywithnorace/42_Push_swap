/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timotheein <timotheein@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 00:11:18 by timotheein        #+#    #+#             */
/*   Updated: 2021/04/30 00:11:31 by timotheein       ###   ########.fr       */
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
