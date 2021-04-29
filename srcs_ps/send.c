/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timotheein <timotheein@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 23:25:18 by timotheein        #+#    #+#             */
/*   Updated: 2021/04/29 23:37:24 by timotheein       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void send_to_top(t_all *all)
{
    int i;

    i = 0;
    while (++i < all->p_low)
        ra(all);
    if (all->sk_a->next && all->sk_a->next->next)
    {
        if (all->sk_a->content < all->sk_a->next->next->content)
            sa(all);
        else
            ra(all);
    }
    all->p_low = 0;
    all->v_low = 0;
}

void reverse_send_to_top(t_all *all)
{
    int i;

    i = all->p_low;
    while (i <= all->len_a)
    {
        rra(all);
        i++;
    }
}