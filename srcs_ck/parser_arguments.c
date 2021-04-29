/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_arguments.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timotheein <timotheein@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:58:23 by timotheein        #+#    #+#             */
/*   Updated: 2021/04/29 17:39:50 by timotheein       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int is_int(char *str)
{
    int i;
    long out;
    long sign;

    i = -1;
    while (++i < ft_strlen(str))
        if (!((i == 0 && str[i] == '-') || (str[i] > '0' && str[i] < '9')))
            return (0);
    if (ft_strlen(str) > 10)
        return (0);
    sign = 1;
    i = -1;
    if (str[0] == '-')
    {
        sign = -1;
        i = 0;
    }
    if (str[0] == '+')
        i = 0;
    out = 0;
    while (str[++i])
        out = out * 10 + (str[i] - '0') * sign;
    if (out > 2147483648 || out < -2147483647)
        return (0);
    return (1);
}

int check_n_get_arguments(int ac, char **av, t_all *all)
{
    int i;
    t_list *elt;

    i = 0;
    while (++i < ac)
    {
        if (!is_int(av[i]))
            return (0);
        if (!all->sk_a)
        {
            all->sk_a = ft_lstnew(av[i]);
            elt = all->sk_a;
            continue ;
        }
        elt->next = ft_lstnew(av[i]);
        elt = elt->next;
    }
    printf("int ok\n");
    return (1);
}
