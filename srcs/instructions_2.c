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
        while (elta->next)
            elta = elta->next;
        elta->next = elt;
        elt->next = 0;
    }
    if (all->p_s)
        write(1, "ra\n", 3);
    else    
        write(1, "-> Executing ra\n\n", 17);}

void rb(t_all *all)
{
    t_list *elt;
    t_list *eltb;

    if (all->sk_b && all->sk_b->next)
    {
        elt = all->sk_b;
        all->sk_b = all->sk_b->next;
        eltb = all->sk_b;
        while (eltb->next)
            eltb = eltb->next;
        eltb->next = elt;
        elt->next = 0;
    }
    if (all->p_s)
        write(1, "rb\n", 3);
    else    
        write(1, "-> Executing rb\n\n", 17);}

void rr(t_all *all)
{
    ra(all);
    rb(all);
    if (all->p_s)
        write(1, "rr\n", 3);
    else    
        write(1, "-> Executing rr\n\n", 17);}

void rra(t_all *all)
{
    t_list *elta;
    t_list *eltz;

    if (all->sk_a && all->sk_a->next)
    {
        elta = all->sk_a;
        while (elta->next && elta->next->next)
            elta = elta->next;
        eltz = elta->next;
        eltz->next = all->sk_a;
        elta->next = 0;
        all->sk_a = eltz;
    }
    if (all->p_s)
        write(1, "rra\n", 4);
    else    
        write(1, "-> Executing rra\n\n", 18);}

void rrb(t_all *all)
{
    t_list *eltb;
    t_list *eltz;

    if (all->sk_b && all->sk_b->next)
    {
        eltb = all->sk_b;
        while (eltb->next && eltb->next->next)
            eltb = eltb->next;
        eltz = eltb->next;
        eltz->next = all->sk_b;
        eltb->next = 0;
        all->sk_b = eltz;
    }
    if (all->p_s)
        write(1, "rrb\n", 4);
    else    
        write(1, "-> Executing rrb\n\n", 18);}

void rrr(t_all *all)
{
    rra(all);
    rrb(all);
    if (all->p_s)
        write(1, "rrr\n", 4);
    else    
        write(1, "-> Executing rrr\n\n", 18);}