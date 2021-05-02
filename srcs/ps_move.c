/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timotheein <timotheein@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 23:25:18 by timotheein        #+#    #+#             */
/*   Updated: 2021/05/02 20:37:36 by timotheein       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void send_closest_value_to_top(t_all *all)
{
    int i;

    i = 0;
    if (all->len_a == 2)
        i--;
    // write(1, "HEY10\n", 6);

    while (++i <= all->p_low)
    {
        // write(1, "HEY00\n", 6);
        print_action("ra", all);
    }
    // write(1, "HEY11\n", 6);

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