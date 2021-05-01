/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timotheein <timotheein@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 11:26:50 by timotheein        #+#    #+#             */
/*   Updated: 2021/05/01 16:43:07 by timotheein       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int check_final_order(t_all *all)
{
    int i;
    t_list *elt;

    printf("here check_order\n");
    if (all->sk_b)
        return (-1);
    // IS THAT REALLY USEFUL ?? :
    //
    // if (!all->sk_a)
    // {
    //     printf("check_order_pb\n");
    //     return (-1);
    // }

    elt = all->sk_a;
    if (elt)
        i = ft_atoi(elt->content);
    while (elt && elt->next)
    {
        if (ft_atoi(elt->next->content) <= i)
            return (-1);
        i = ft_atoi(elt->next->content);
        elt = elt->next;
    }
    return (1);
}

int execute_instruction(t_all *all)
{
    t_int_list *elt;

    elt = all->instruction;
    write(1, "Initial situation : \n", 21);
    print_elt(all);
    while (elt)
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
        print_elt(all);

        elt = elt->next;
    }
    return (1);
}