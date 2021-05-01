/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timotheein <timotheein@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 00:11:18 by timotheein        #+#    #+#             */
/*   Updated: 2021/05/01 16:38:13 by timotheein       ###   ########.fr       */
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
    t_int_list *elt;

    while (all->instruction)
    {
        elt = all->instruction->next;
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

int Error_arguments(t_all *all)
{
    write(1, "Error\n", 6);
    freeer(all);
    return (0);
}

int Error_instruction(t_all *all)
{
    write(1, "Error\n", 6);
    freeer(all);
    return (0);
}
int Error_execution(t_all *all)
{
    write(1, "Error\n", 6);
    freeer(all);
    return (0);
}

void check_result(t_all *all)
{
    if (all->check == 1)
        write(1, "OK\n", 3);
    if (all->check == -1)
        write(1, "KO\n", 3);
    return;
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
    while (ft_max(a,b) > 0)
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
