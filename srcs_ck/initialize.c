/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timotheein <timotheein@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:54:04 by timotheein        #+#    #+#             */
/*   Updated: 2021/04/21 15:57:24 by timotheein       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int    intitialize_all(t_all *all)
{
    if(!(all = malloc(sizeof(t_all))))
        return (0);
    all->check = -1;
    all->instructions = 0;
    all->sk = 0;
    return (1);
}
