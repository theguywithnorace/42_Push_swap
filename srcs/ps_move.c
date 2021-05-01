/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timotheein <timotheein@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 23:25:18 by timotheein        #+#    #+#             */
/*   Updated: 2021/05/01 22:15:45 by timotheein       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void send_to_top(t_all *all)
{
    int i;

    i = 0;
    if (all->len_a == 2)
        i--;
    while (++i < all->p_low)
        print_action("ra", all);
    if (all->sk_a->next && all->sk_a->next->next)
    {
        if (all->sk_a->content < all->sk_a->next->next->content)
            print_action("sa", all);
        else
            print_action("ra", all);
    }
    all->p_low = 0;
    all->v_low = 0;
}

void reverse_send_to_top(t_all *all)
{
    int i;

    i = all->p_low;
    while (i++ < all->len_a)
        print_action("rra", all);
}