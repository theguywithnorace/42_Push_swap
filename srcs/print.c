/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timotheein <timotheein@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 17:38:37 by timotheein        #+#    #+#             */
/*   Updated: 2021/05/01 18:35:48 by timotheein       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void print_init(t_all *all)
{
    if (all->bonus)
        write(1, "\nInitial situation : \n\n", 23);
    if (all->bonus)
        print_elt(all);
}

void print_action(char *action, t_all *all)
{
    if (all->bonus)
    {
        write(1, "-> Executing ", 13);
        write(1, action, ft_strlen(action));
        write(1, " ->\n\n", 5);
        print_elt(all);
    }
    else if (all->p_s)
    {
        write(1, action, ft_strlen(action));
        write(1, "\n", 1);
    }
}

void print_elt(t_all *all)
{
    t_list *ea;
    t_list *eb;
    int a;
    int b;

    ea = all->sk_a;
    eb = all->sk_b;
    a = ft_lstsize(ea);
    b = ft_lstsize(eb);
    while (ft_max(a, b) > 0)
    {
        if (a >= b)
        {
            write(1, " ", 1);
            write(1, ea->content, ft_strlen(ea->content));
            ea = ea->next;
            a--;
        }
        else
            write(1, "  ", 1);
        write(1, "\t", 1);
        if (b > a)
        {
            write(1, " ", 1);
            write(1, eb->content, ft_strlen(eb->content));
            eb = eb->next;
            b--;
        }
        write(1, "\n", 1);
    }

    write(1, "---\t---\n A \t B\n\n\n", 17);
}