/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timotheein <timotheein@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 00:11:18 by timotheein        #+#    #+#             */
/*   Updated: 2021/05/01 15:54:22 by timotheein       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"




void free_a(t_all *all)
{
    t_list *elt;

    while (all->sk_a)
    {
        elt = all->sk_a->next;
        printf("\nfreeing sk_a elt : %s\n\n", all->sk_a->content);
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
        printf("\nfreeing sk_b elt : %s\n\n", all->sk_b->content);
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
        printf("\nfreeing inst : %d\n\n", all->instruction->content);
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
    printf("Error argument\n");
    write(1, "Error\n", 6);
    freeer(all);
    return (0);
}

int Error_instruction(t_all *all)
{
    printf("Error instruction\n");
    write(1, "Error\n", 6);
    freeer(all);
    return (0);
}
int Error_execution(t_all *all)
{
    printf("Error execution\n");
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
    t_list *elt;

    elt = all->sk_a;
    write(1, "sk_a :\n", 7);
    while (elt)
    {
        write(1, elt->content, ft_strlen(elt->content));
        write(1, "\n", 1);
        elt = elt->next;
    }
    elt = all->sk_b;
    write(1, "sk_b :\n", 7);
    while (elt)
    {
        write(1, elt->content, ft_strlen(elt->content));
        write(1, "\n", 1);
        elt = elt->next;
    }
    write(1, "END\n\n", 5);
}
