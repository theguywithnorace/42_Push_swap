/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timotheein <timotheein@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 22:47:51 by timotheein        #+#    #+#             */
/*   Updated: 2021/05/01 23:16:20 by timotheein       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int in_order(t_all *all)
{
    if (all->p_low == 0 && all->p_low2 == 2)
        return (0);
    if (all->p_low2 < all->p_low && all->p_low != 2)
        return (0);
    return (1);
}

void find_lowest_values_a(t_all *all)
{
    t_list *elt;
    int i;

    i = 1;
    elt = all->sk_a;
    all->p_low = 0;
    all->v_low = ft_atoi(elt->content);
    elt = elt->next;
    while (elt)
    {
        if (ft_atoi(elt->content) < all->v_low)
        {
            all->v_low2 = all->v_low;
            all->p_low2 = all->p_low;
            all->v_low = ft_atoi(elt->content);
            all->p_low = i;
        }
        i++;
        elt = elt->next;
    }
    return;
}

int check_order_fst_sk_b(t_all *all)
{
    t_list *elt;

    if (!all->sk_b || !(all->sk_b->next))
        return (1);
    elt = all->sk_b;
    if (ft_atoi(elt->content) < ft_atoi(elt->next->content))
        return (0);
    return (1);
}

int check_order_fst_sk_a(t_all *all)
{
    t_list *elt;

    if (!all->sk_a || !(all->sk_a->next))
        return (1);
    elt = all->sk_a;
    if (ft_atoi(elt->content) < ft_atoi(elt->next->content))
        return (0);
    return (1);
}

int check_order_sk_a(t_all *all)
{
    int i;
    t_list *elt;

    if (!all->sk_a || !(all->sk_a->next))
        return (1);
    elt = all->sk_a;
    if (elt)
        i = ft_atoi(elt->content);
    while (elt && elt->next)
    {
        if (ft_atoi(elt->next->content) <= i)
            return (0);
        i = ft_atoi(elt->next->content);
        elt = elt->next;
    }
    return (1);
}