/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timotheein <timotheein@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 16:23:34 by timotheein        #+#    #+#             */
/*   Updated: 2021/04/21 21:08:27 by timotheein       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int check_instruction(char *line)
{
    if (ft_strcmp("sa", line) == 0)
        return (SA);
    else if (ft_strcmp("sb", line) == 0)
        return (SB);
    else if (ft_strcmp("ss", line) == 0)
        return (SS);
    else if (ft_strcmp("pa", line) == 0)
        return (PA);
    else if (ft_strcmp("pb", line) == 0)
        return (PB);
    else if (ft_strcmp("ra", line) == 0)
        return (RA);
    else if (ft_strcmp("rb", line) == 0)
        return (RB);
    else if (ft_strcmp("rr", line) == 0)
        return (RR);
    else if (ft_strcmp("rra", line) == 0)
        return (RRA);
    else if (ft_strcmp("rrb", line) == 0)
        return (RRB);
    else if (ft_strcmp("rrr", line) == 0)
        return (RRR);
    return (0);
}

int read_instruction(t_all *all)
{
    char *line;
    t_list *elt;
    int r;

    line = 0;
    while ((r = get_next_line(0, &line)) > 0 && ft_strcmp(line, ""))
    {
        if (!(check_instruction(line)))
        {
            free(line);
            return (0);
        }
        if (!all->instruction)
        {
            all->instruction = ft_lstnew(ft_strdup(line));
            elt = all->instruction;
            free(line);
            continue;
        }
        elt->next = ft_lstnew(ft_strdup(line));
        elt = elt->next;
        free(line);
    }
    free(line);
    return (1);
}
