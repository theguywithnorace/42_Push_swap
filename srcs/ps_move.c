/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timotheein <timotheein@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 23:25:18 by timotheein        #+#    #+#             */
/*   Updated: 2021/05/02 21:32:28 by timotheein       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void make_final_ordering(t_all *all)
{
    int reverse;

    printf("make_final_ordering\n");
    reverse = 1;
    if (all->p_min <= ((all->len_a) / 2))
        reverse = 0;
    while (ft_atoi(all->sk_a->content) != all->min)
    {
        if (reverse)
            print_action("rra", all);
        else
            print_action("ra", all);
    }
}

void send_mid_hig_to_top(t_all *all)
{
    int reverse;

    printf("send_mid_to_top\n");
    reverse = 1;
    if (all->p_hig <= ((all->len_a) / 2))
        reverse = 0;
    while (ft_atoi(all->sk_a->content) != all->v_hig)
    {
        if (reverse)
            print_action("rra", all);
        else
            print_action("ra", all);
    }
}

void send_closest_value_to_top(t_all *all)
{
    int i;

    i = 0;
    if (all->len_a == 2)
        i--;
    while (++i <= all->p_tomov)
        print_action("ra", all);
    // if (all->sk_a->next->next && (all->sk_a->content < all->sk_a->next->next->content))
    //     print_action("sa", all);
    // else
    //     print_action("ra", all);
    all->p_low = 0;
    all->v_low = 0;
    all->v_hig = 0;
    all->p_hig = 0;
}

void reverse_send_closest_value_to_top(t_all *all)
{
    int i;

    i = all->p_tomov;
    while (i++ < all->len_a)
        print_action("rra", all);
}

// void send_to_top(t_all *all)
// {
//     int i;

//     i = 0;
//     if (all->len_a == 2)
//         i--;
//     while (++i < all->p_low)
//     {
//         print_action("ra", all);
//         if (all->len_t > 5)
//         {
//             if (ft_atoi(all->sk_a->content) == all->v_low2)
//             {
//                 print_action("pb", all);
//                 all->p_low--;
//                 all->v_low_sent = 1;
//             }
//         }
//     }
//     if ((all->sk_a->next && all->sk_a->next->next) && !(ft_atoi(all->sk_a->content) == all->v_low))
//     {
//         if (all->sk_a->content < all->sk_a->next->next->content)
//             print_action("sa", all);
//         else
//             print_action("ra", all);
//     }
//     all->p_low = 0;
//     all->v_low = 0;
// }

// void reverse_send_to_top(t_all *all)
// {
//     int i;

//     i = all->p_low;
//     while (i++ < all->len_a)
//         print_action("rra", all);
// }