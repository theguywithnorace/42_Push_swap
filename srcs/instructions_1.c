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
    if (all->p_s)
        write(1, "sa\n", 3);
    else    
        write(1, "-> Executing sa\n\n", 17);
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
    if (all->p_s)
        write(1, "sb\n", 3);
    else    
        write(1, "-> Executing sb\n\n", 17);}

void ss(t_all *all)
{
    sa(all);
    sb(all);
    if (all->p_s)
        write(1, "ss\n", 3);
    else    
        write(1, "-> Executing sb\n\n", 17);}

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
    all->len_a++;
    if (all->p_s)
        write(1, "pa\n", 3);
    else    
        write(1, "-> Executing pa\n\n", 17);}

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
    all->len_a--;
    if (all->p_s)
        write(1, "pb\n", 3);
    else    
        write(1, "-> Executing pb\n\n", 17);}