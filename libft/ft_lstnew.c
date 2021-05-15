/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timotheein <timotheein@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 11:05:13 by timothee          #+#    #+#             */
/*   Updated: 2021/05/15 13:56:19 by timotheein       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *out;

	if (!(out = malloc(sizeof(t_list))))
		return (0);
	out->content = content;
	out->next = 0;
	return (out);
}

t_elt	*ft_lstnew_e(void *content)
{
	t_elt *out;

	if (!(out = malloc(sizeof(t_elt))))
		return (0);
	out->content = content;
	out->is_pivot = 0;
	out->is_last = 0;
	out->next = 0;
	return (out);
}
