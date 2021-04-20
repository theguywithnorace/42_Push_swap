/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timothee <timothee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 11:38:09 by timothee          #+#    #+#             */
/*   Updated: 2019/11/26 10:07:46 by tiin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *tmp;

	if (!new || !alst)
		return ;
	if (!(*alst))
	{
		*alst = new;
		return ;
	}
	tmp = (*alst);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return ;
}
