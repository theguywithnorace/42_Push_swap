/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timotheein <timotheein@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 00:11:18 by timotheein        #+#    #+#             */
/*   Updated: 2021/04/30 00:35:31 by timotheein       ###   ########.fr       */
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
    write(1, "sk_a :\n", 7);
    while (elt)
    {
        write(1, elt->content, ft_strlen(elt->content));
        write(1, "\n", 1);
        elt = elt->next;
    }
    elt = all->sk_b;
    write(1, "sk_b :\n", 7);
    while (elt)
    {
        write(1, elt->content, ft_strlen(elt->content));
        write(1, "\n", 1);
        elt = elt->next;
    }
    write(1, "END\n\n", 5);
}
