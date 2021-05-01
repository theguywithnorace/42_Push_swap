/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timotheein <timotheein@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 22:37:57 by timotheein        #+#    #+#             */
/*   Updated: 2021/05/01 18:52:22 by timotheein       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void execute_algo(t_all *all)
{
    while (!check_order_sk_a(all))
    {
        find_lowest_value_a(all);
        if ((all->p_low != 0) && (all->p_low <= ((all->len_a) / 2)))
            send_to_top(all);
        else if ((all->p_low > ((all->len_a) / 2)))
            reverse_send_to_top(all);
        if (!check_order_sk_a(all))
        {
            pb(all);
            print_action("pb", all);
        }
    }
    while (all->sk_b)
    {
        pa(all);
        print_action("pa", all);
    }
    freeer(all);
}

int main(int ac, char **av)
{
    t_all *all;

    all = 0;
    if (!(all = malloc(sizeof(t_all))))
        return (0);
    intitialize_all(all);
    all->p_s = 1;
    if (!ft_strcmp(av[1], "-v"))
        all->bonus = 1;
    if (ac < 2 || (ac < 3 && all->bonus))
        return (0);
    if (!check_n_get_arguments(ac, av, all))
        return (Error_arguments(all));
    print_init(all);
    execute_algo(all);
}