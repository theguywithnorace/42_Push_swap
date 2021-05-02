/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timotheein <timotheein@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 11:26:50 by timotheein        #+#    #+#             */
/*   Updated: 2021/05/02 20:41:22 by timotheein       ###   ########.fr       */
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
void execute(char *action, t_all *all)
{
    write(1, "HEY30\n", 6);
     ft_strcmp(action, "sa");
    write(1, "HEY30\n", 6);
     write(1, action, ft_strlen(action));

    if (!ft_strcmp(action, "sa"))
    {
        write(1, "HEY30\n", 6);
        sa(all);
    }
    else if (!ft_strcmp(action, "sb"))
    {
        write(1, "HEY30\n", 6);
        sb(all);
    }
    else if (!ft_strcmp(action, "ss"))
    {
        write(1, "HEY30\n", 6);
        ss(all);
    }
    else if (!ft_strcmp(action, "pa"))
    {
        write(1, "HEY30\n", 6);
        pa(all);
    }
    else if (!ft_strcmp(action, "pb"))
    {
        write(1, "HEY35\n", 6);
        pb(all);
    }
    else if (!ft_strcmp(action, "ra"))
    {
        write(1, "HEY30\n", 6);
        ra(all);
    }
    else if (!ft_strcmp(action, "rb"))
    {
        write(1, "HEY30\n", 6);
        rb(all);
    }
    else if (!ft_strcmp(action, "rr"))
        rr(all);
    else if (!ft_strcmp(action, "rra"))
        rra(all);
    else if (!ft_strcmp(action, "rrb"))
        rrb(all);
    else if (!ft_strcmp(action, "rrr"))
        rrr(all);
    write(1, "HEY30\n", 6);
}

int execute_instruction(t_all *all)
{
    t_list *elt;

    elt = all->instruction;
    print_init(all);
    while (elt)
    {
        print_action(elt->content, all);
        elt = elt->next;
    }
    return (1);
}