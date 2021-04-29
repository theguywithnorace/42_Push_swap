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

t_int_list *ft_lstnew_int(int content)
{
    t_int_list *out;

    if (!(out = malloc(sizeof(t_list))))
        return (0);
    out->content = content;
    out->next = 0;
    return (out);
}

int check_instruction(char *line)
{
    printf("CHECK\n");
    if (ft_strcmp("sa", line) == 0)
    {
        printf("oh!!\n");
        return (SA);
    }
    else if (ft_strcmp("sb", line) == 0)
    {
        printf("oh!!\n");
        return (SB);
    }
    else if (ft_strcmp("ss", line) == 0)
    {
        printf("oh!!\n");
        return (SS);
    }
    else if (ft_strcmp("pa", line) == 0)
    {
        printf("oh!!\n");
        return (PA);
    }
    else if (ft_strcmp("pb", line) == 0)
    {
        printf("oh!!\n");
        return (PB);
    }
    else if (ft_strcmp("ra", line) == 0)
    {
        printf("ra\n");
        return (RA);
    }
    else if (ft_strcmp("rb", line) == 0)
    {
        printf("oh!!\n");

        return (RB);
    }
    else if (ft_strcmp("rr", line) == 0)
    {
        printf("ohh!!\n");
        return (RR);
    }
    else if (ft_strcmp("rra", line) == 0)
    {
        printf("rra\n");
        return (RRA);
    }
    else if (ft_strcmp("rrb", line) == 0)
        return (RRB);
    else if (ft_strcmp("rrr", line) == 0)
        return (RRR);
    printf("oh!!\n");
    return (0);
}

int read_instruction(t_all *all)
{
    char *line;
    t_int_list *elt;
    int r;

    line = 0;
    r = 0;
    while ((r = get_next_line(0, &line)) > 0 && ft_strcmp(line, ""))
    {
        if (!(r = check_instruction(line)))
            return (0);
        if (!all->instruction)
        {
            all->instruction = ft_lstnew_int(r);
            elt = all->instruction;
            continue;
        }
        elt->next = ft_lstnew_int(r);
        elt = elt->next;
    }
    printf("end of read instructions\n");
    return (1);
}
