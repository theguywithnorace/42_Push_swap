/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timotheein <timotheein@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 16:23:34 by timotheein        #+#    #+#             */
/*   Updated: 2021/04/21 16:33:26 by timotheein       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int read_instructions(t_all *all)
{
    char *line;
    int r;
    int i;

    line = 0;
    r = 0;
    i = 0;
    while ((r = get_next_line(0, &line)) > 0)
    {
        if (!(all->instructions[i] = malloc(sizeof(char *))))
            return (0);
        all->instructions = line;
        i++;
    }
}
