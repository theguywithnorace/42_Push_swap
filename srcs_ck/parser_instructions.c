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

t_int_list	*ft_lstnew_int(int content)
{
	t_int_list *out;

	if (!(out = malloc(sizeof(t_list))))
		return (0);
	out->content = content;
	out->next = 0;
	return (out);
}

int check_instruction(t_int_list *instruction, char *line)
{
    printf("line gnl : -%s-\n", line);
    if (ft_strcmp("sa", line) == 0)
        instruction = ft_lstnew_int(SA);
    else if (ft_strcmp("sb", line) == 0)
        instruction = ft_lstnew_int(SB);
    else if (ft_strcmp("ss", line) == 0)
        instruction = ft_lstnew_int(SS);
    else if (ft_strcmp("pa", line) == 0)
        instruction = ft_lstnew_int(PA);
    else if (ft_strcmp("pb", line) == 0)
        instruction = ft_lstnew_int(PB);
    else if (ft_strcmp("ra", line) == 0)
        instruction = ft_lstnew_int(RA);
    else if (ft_strcmp("rb", line) == 0)
        instruction = ft_lstnew_int(RB);
    else if (ft_strcmp("rr", line) == 0)
        instruction = ft_lstnew_int(RR);
    else if (ft_strcmp("rra", line) == 0)
        instruction = ft_lstnew_int(RRA);
    else if (ft_strcmp("rrb", line) == 0)
        instruction = ft_lstnew_int(RRB);
    else if (ft_strcmp("rrr", line) == 0)
        instruction = ft_lstnew_int(RRR);
    else
        return (0);
    return (1);
}

int read_instruction(t_all *all)
{
    char *line;
    t_int_list *elt;
    int r;

    line = 0;
    r = 0;
    elt = all->instruction;
    while ((r = get_next_line(0, &line)) > 0)
    {
        if (!check_instruction(elt, line))
            return (0);
        elt = elt->next;
    }
    return (1);
}
