/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timotheein <timotheein@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 21:09:48 by timotheein        #+#    #+#             */
/*   Updated: 2021/04/21 21:09:55 by timotheein       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void ra(t_all *all)
{
    t_list *elt;
    t_list *elta;

    if (all->sk_a && all->sk_a->next)
    {
        elt = all->sk_a;
        all->sk_a = all->sk_a->next;
        elta = all->sk_a;
        while (elta)
            elta = elta->next;
        elta = elt;
        elt->next = 0;
    }
}

void rb(t_all *all)
{
    t_list *elt;
    t_list *eltb;

    if (all->sk_b && all->sk_b->next)
    {
        elt = all->sk_b;
        all->sk_b = all->sk_b->next;
        eltb = all->sk_b;
        while (eltb)
            eltb = eltb->next;
        eltb = elt;
        elt->next = 0;
    }
}

void rr(t_all *all)
{
    ra(all);
    rb(all);
}

void rra(t_all *all)
{
    t_list *elta;
    t_list *elt;

    if (all->sk_a && all->sk_a->next)
    {
        elta = all->sk_a;
        while (elta->next && elta->next->next)
            elta = elta->next;
        elt = elta->next;
        elt->next = all->sk_a;
        elta->next = 0;
        all->sk_a = elt;
    }
}

void rrb(t_all *all)
{
    t_list *eltb;
    t_list *elt;

    if (all->sk_b && all->sk_b->next)
    {
        eltb = all->sk_b;
        while (eltb->next && eltb->next->next)
            eltb = eltb->next;
        elt = eltb->next;
        elt->next = all->sk_b;
        eltb->next = 0;
        all->sk_b = elt;
    }
}

void rrr(t_all *all)
{
    rra(all);
    rrb(all);
}