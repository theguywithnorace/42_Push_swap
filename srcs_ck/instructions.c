/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timotheein <timotheein@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 16:23:34 by timotheein        #+#    #+#             */
/*   Updated: 2021/04/21 21:05:59 by timotheein       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int check_instructions(t_list *instruction, char *line)
{
    if (ft_strcmp("sa", line) == 0)
        instruction = ft_lstnew(SA);
    else if (ft_strcmp("sb", line) == 0)
        instruction = ft_lstnew(SB);
    else if (ft_strcmp("ss", line) == 0)
        instruction = ft_lstnew(SS);
    else if (ft_strcmp("pa", line) == 0)
        instruction = ft_lstnew(PA);
    else if (ft_strcmp("pb", line) == 0)
        instruction = ft_lstnew(PB);
    else if (ft_strcmp("ra", line) == 0)
        instruction = ft_lstnew(RA);
    else if (ft_strcmp("rb", line) == 0)
        instruction = ft_lstnew(RB);
    else if (ft_strcmp("rr", line) == 0)
        instruction = ft_lstnew(RR);
    else if (ft_strcmp("rra", line) == 0)
        instruction = ft_lstnew(RRA);
    else if (ft_strcmp("rrb", line) == 0)
        instruction = ft_lstnew(RRB);
    else if (ft_strcmp("rrr", line) == 0)
        instruction = ft_lstnew(RRR);
    else
        return (0);
    return (1);
}

int read_instruction(t_all *all)
{
    char *line;
    t_list *elt;
    int r;
    int i;

    line = 0;
    r = 0;
    i = 0;
    elt = all->instruction;
    while ((r = get_next_line(0, &line)) > 0)
    {
        if (!check_instructions(elt, line))
            return (0);
        elt = elt->next;
    }

    all->instructions[i] = 0;

    if (!check_instructions(all))
        return (0);
    return (1);
}
