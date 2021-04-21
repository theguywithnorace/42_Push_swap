/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timotheein <timotheein@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:54:04 by timotheein        #+#    #+#             */
/*   Updated: 2021/04/21 21:11:43 by timotheein       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int    intitialize_all(t_all *all)
{
    if(!(all = malloc(sizeof(t_all))))
        return (0);
    all->check = -1;
    all->instruction = 0;
    all->sk_a = 0;
    all->sk_b = 0;
    return (1);
}
