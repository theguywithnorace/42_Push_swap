/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timothee <timothee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 12:13:08 by timothee          #+#    #+#             */
/*   Updated: 2019/11/27 18:52:34 by timotheein       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*my_lstnew(void *content)
{
	t_list *out;

	if (!(out = malloc(sizeof(t_list))))
		return (0);
	out->content = content;
	out->next = 0;
	return (out);
}

t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *n;
	t_list *i;

	if (!lst)
		return (0);
	i = my_lstnew((*f)(lst->content));
	if (!i)
		return (0);
	n = i;
	lst = lst->next;
	while (lst)
	{
		n->next = my_lstnew((*f)(lst->content));
		if (!n->next)
			return (0);
		n = n->next;
		lst = lst->next;
	}
	(void)del;
	return (i);
}
