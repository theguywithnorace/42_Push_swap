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

void sa(t_all *all)
{
    t_list *elt;

    if (all->sk_a && all->sk_a->next)
    {
        elt = all->sk_a;
        all->sk_a = all->sk_a->next;
        elt->next = all->sk_a->next;
        all->sk_a->next = elt;
    }
}

void sb(t_all *all)
{
    t_list *elt;

    if (all->sk_b && all->sk_b->next)
    {
        elt = all->sk_b;
        all->sk_b = all->sk_b->next;
        elt->next = all->sk_b->next;
        all->sk_b->next = elt;
    }
}

void ss(t_all *all)
{
    sa(all);
    sb(all);
}

void pa(t_all *all)
{
    t_list *elt;

    if (all->sk_b)
    {
        elt = all->sk_b;
        all->sk_b = all->sk_b->next;
        elt->next = all->sk_a;
        all->sk_a = elt;
    }
}

void pb(t_all *all)
{
    t_list *elt;

    if (all->sk_a)
    {
        elt = all->sk_a;
        all->sk_a = all->sk_a->next;
        elt->next = all->sk_b;
        all->sk_b = elt;
    }
}