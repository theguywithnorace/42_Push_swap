/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timotheein <timotheein@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 11:36:00 by timothee          #+#    #+#             */
/*   Updated: 2021/05/10 22:34:17 by timotheein       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_elt	*ft_lstlast_e(t_elt *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
