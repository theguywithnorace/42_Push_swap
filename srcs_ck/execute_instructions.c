/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timotheein <timotheein@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 11:26:50 by timotheein        #+#    #+#             */
/*   Updated: 2021/04/22 12:02:17 by timotheein       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int check_order(t_all *all)
{
    int i;
    t_int_list *elt;

    if (all->sk_b)
        return (0);
    if (!all->sk_a)
        return (1);
    elt = all->instruction;
    i = elt->content;
    while (elt->next)
    {
        if (elt->next->content < i)
        {
            write(1, "KO\n", 3);
        }
        return (0);
        i = elt->next->content;
        elt = elt->next;
    }
    write(1, "OK\n", 3);
    return (1);
}

int execute_instruction(t_all *all)
{
    t_int_list *elt;

    elt = all->instruction;
    while (elt->next)
    {
        switch (elt->content)
        {
        case SA:
            sa(all);
            break;
        case SB:
            sb(all);
            break;
        case SS:
            ss(all);
            break;
        case PA:
            pa(all);
            break;
        case PB:
            pb(all);
            break;
        case RA:
            ra(all);
            break;
        case RB:
            rb(all);
            break;
        case RR:
            rr(all);
            break;
        case RRA:
            rra(all);
            break;
        case RRB:
            rrb(all);
            break;
        case RRR:
            rrr(all);
            break;
        default:
            return (0);
            break;
        }
        elt = elt->next;
    }
    return (1);
}