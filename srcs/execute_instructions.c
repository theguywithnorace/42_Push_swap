/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timotheein <timotheein@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 11:26:50 by timotheein        #+#    #+#             */
/*   Updated: 2021/05/01 18:35:20 by timotheein       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int check_final_order(t_all *all)
{
    int i;
    t_list *elt;

    if (all->sk_b)
        return (-1);
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
    t_list *elt;

    elt = all->instruction;
    print_init(all);
    while (elt)
    {
        if (!ft_strcmp(elt->content, "sa"))
            sa(all);
        else if (!ft_strcmp(elt->content, "sb"))
            sb(all);
        else if (!ft_strcmp(elt->content, "ss"))
            ss(all);
        else if (!ft_strcmp(elt->content, "pa"))
            pa(all);
        else if (!ft_strcmp(elt->content, "pb"))
            pb(all);
        else if (!ft_strcmp(elt->content, "ra"))
            ra(all);
        else if (!ft_strcmp(elt->content, "rb"))
            rb(all);
        else if (!ft_strcmp(elt->content, "rr"))
            rr(all);
        else if (!ft_strcmp(elt->content, "rra"))
            rra(all);
        else if (!ft_strcmp(elt->content, "rrb"))
            rrb(all);
        else if (!ft_strcmp(elt->content, "rrr"))
            rrr(all);
        print_action(elt->content, all);


        elt = elt->next;
    }
    return (1);
}