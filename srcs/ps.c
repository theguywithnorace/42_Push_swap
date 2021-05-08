/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timotheein <timotheein@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 22:37:57 by timotheein        #+#    #+#             */
/*   Updated: 2021/05/08 17:23:10 by timotheein       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void execute_short_algo(t_all *all)
{
    find_lowest_values_a(all);
    if (!in_order(all))
        print_action("sa", all);
    find_lowest_values_a(all);
    if (!check_order_sk_a(all))
    {
        if (all->p_low == 1)
            print_action("ra", all);
        if (all->p_low == 2)
            print_action("rra", all);
    }
}

void execute_algo_2(t_all *all)
{
    find_middle_value(all);
    while (!sk_a_ordered_by_packet(all))
    {
        find_close_mid_values(all);
        find_value_to_move(all);
        if ((all->p_tomov != 0) && (all->p_tomov <= ((all->len_a) / 2)))
            send_closest_value_to_top(all);
        else if ((all->p_tomov > ((all->len_a) / 2)))
            reverse_send_closest_value_to_top(all);
        if (!sk_a_ordered_by_packet(all))
        {
            print_action("pb", all);
            if (all->is_tomov_low && (ft_lstsize(all->sk_b) > 1))
                print_action("rb", all);
        }
    }
    if (!(check_order_sk_a(all) && all->sk_b == 0))
    {
        find_close_mid_values(all);
        send_mid_hig_to_top(all);
        while (all->sk_b)
            print_action("pa", all);
        find_close_mid_values(all);
        make_final_ordering(all);
    }
    freeer(all);
}

int main(int ac, char **av)
{
    t_all *all;

    all = 0;
    if (ac < 2)
        return (0);
    if (!(all = malloc(sizeof(t_all))))
        return (0);
    intitialize_all(all);
    all->p_s = 1;
    if (!ft_strcmp(av[1], "-v"))
        all->bonus = 1;
    if (ac < 3 && all->bonus)
        return (freeer(all));
    if (!check_n_get_arguments(ac, av, all))
        return (error_arguments(all));
    print_init(all);
    if (all->len_t == 3)
        execute_short_algo(all);
    else
        execute_algo_2(all);
}
