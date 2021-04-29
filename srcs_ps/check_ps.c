/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timotheein <timotheein@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 22:47:51 by timotheein        #+#    #+#             */
/*   Updated: 2021/04/29 23:19:05 by timotheein       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void find_lowest_value_a(t_all *all)
{
    t_list *elt;
    int i;

    i = 1;
    all->p_low = 0;
    all->v_low = ft_atoi(all->sk_a->content);
    elt = all->sk_a->next; //next existe forcement, sinon la liste serait deja triée
    while (elt)
    {
        if (ft_atoi(elt->content) < all->v_low)
        {
            all->v_low = ft_atoi(elt->content);
            all->p_low = i;
        }
        i++;
    }
    return ;
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
    printf("middle+ of check_order\n");
    while (elt && elt->next)
    {
        printf("-%s ", elt->content);
        if (ft_atoi(elt->next->content) <= i)
            return (0);
        i = ft_atoi(elt->next->content);
        elt = elt->next;
    }
    printf("-%s ", elt->content);

    printf("\n");
    printf("end of check_order\n");

    return (1);
}