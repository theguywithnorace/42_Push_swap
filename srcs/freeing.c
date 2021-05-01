/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timotheein <timotheein@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 00:11:18 by timotheein        #+#    #+#             */
/*   Updated: 2021/05/01 19:04:09 by timotheein       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void free_a(t_all *all)
{
    t_list *elt;

    while (all->sk_a)
    {
        elt = all->sk_a->next;
        free(all->sk_a);
        all->sk_a = elt;
    }
}

void free_b(t_all *all)
{
    t_list *elt;

    while (all->sk_b)
    {
        elt = all->sk_b->next;
        free(all->sk_b);
        all->sk_b = elt;
    }
}

void free_inst(t_all *all)
{
    t_list *elt;

    while (all->instruction)
    {
        elt = all->instruction->next;
        free(all->instruction->content);
        free(all->instruction);
        all->instruction = elt;
    }
}

void freeer(t_all *all)
{
    free_a(all);
    free_b(all);
    free_inst(all);
    free(all);
}
