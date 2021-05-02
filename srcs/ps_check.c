/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timotheein <timotheein@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 22:47:51 by timotheein        #+#    #+#             */
/*   Updated: 2021/05/02 21:29:49 by timotheein       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int in_order(t_all *all)
{
    if (all->p_low == 0 && all->p_hig == 2)
        return (0);
    if (all->p_hig < all->p_low && all->p_low != 2)
        return (0);
    return (1);
}

int sk_a_ordered_by_packet(t_all *all)
{
    t_list *elt;
    int k;

    elt = all->sk_a;
    k = ft_atoi(elt->content);
    if (elt->next == 0)
        return (1);
    elt = elt->next;
    while (elt && (k <= all->max))
    {
        if (k > ft_atoi(elt->content))
            return (0);
        k = ft_atoi(elt->content);
        elt = elt->next;
    }
    k = all->min;
    while (elt)
    {
        if (k > ft_atoi(elt->content))
            return (0);
        k = ft_atoi(elt->content);
        elt = elt->next;
    }
    return (1);
}

void find_middle_value(t_all *all)
{
    t_list *elt;
    int sum;
    int i;

    sum = 0;
    i = 0;
    elt = all->sk_a;
    all->min = ft_atoi(elt->content);
    all->max = ft_atoi(elt->content);
    while (elt)
    {
        if (ft_atoi(elt->content) < all->min)
            all->min = ft_atoi(elt->content);
        else if (ft_atoi(elt->content) > all->max)
            all->max = ft_atoi(elt->content);
        sum = sum + ft_atoi(elt->content);
        i++;
        elt = elt->next;
    }
    all->midd = sum / i;
}

void find_value_to_move(t_all *all)
{
    int steps_l;
    int steps_h;

    if (all->p_low <= ((all->len_a) / 2))
        steps_l = all->p_low;
    else
        steps_l = all->len_a - all->p_low;
    if (all->p_hig <= ((all->len_a) / 2))
        steps_h = all->p_hig;
    else
        steps_h = all->len_a - all->p_hig + 1;
    // if ((steps_h > steps_l) || all->v_hig == all->max)
    if ((steps_h > steps_l))
    {
        all->is_tomov_low = 1;
        all->p_tomov = all->p_low;
        printf("fuck\n");
    }
    else
    {
        all->is_tomov_low = 0;
        all->p_tomov = all->p_hig;
    }
    printf("value to mov at position : %d to mov low ? %d\n", all->p_tomov, all->is_tomov_low);
}

void find_close__mid_values(t_all *all)
{
    t_list *elt;
    int i;
    int e;

    i = 0;
    elt = all->sk_a;
    all->p_low = 0;
    all->v_low = all->min;
    all->p_hig = 0;
    all->v_hig = all->max;
    while (elt)
    {
        e = ft_atoi(elt->content);
        if (e == all->min)
            all->p_min = i;
        if ((e <= all->midd) && (all->midd - all->v_low >= all->midd - e))
        {
            all->v_low = e;
            all->p_low = i;
        }
        else if ((e > all->midd) && (all->v_hig - all->midd >= e - all->midd))
        {
            all->v_hig = e;
            all->p_hig = i;
        }
        i++;
        elt = elt->next;
    }
    printf("close mid values : low : %d [%d] hig : %d [%d] min : %d [%d]\n", all->v_low, all->p_low, all->v_hig, all->p_hig, all->min, all->p_min);
}

void find_lowest_values_a(t_all *all)
{
    t_list *elt;
    int i;

    i = 1;
    elt = all->sk_a;
    all->p_low = 0;
    all->v_low = ft_atoi(elt->content);
    all->v_hig = all->v_low - 1;
    elt = elt->next;
    while (elt)
    {
        // // // write(1, "HEY2\n", 4);

        if (ft_atoi(elt->content) < all->v_low)
        {
            all->v_hig = all->v_low;
            all->p_hig = all->p_low;
            all->v_low = ft_atoi(elt->content);
            all->p_low = i;
        }
        else if (ft_atoi(elt->content) < all->v_hig)
        {
            all->v_hig = ft_atoi(elt->content);
            all->p_hig = i;
        }
        i++;
        elt = elt->next;
    }
    // printf("p_low %d v_low %d p_low2 %d v_low2 %d\n\n", all->p_low, all->v_low, all->p_low2, all->v_low2);
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