/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timotheein <timotheein@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 08:51:36 by timotheein        #+#    #+#             */
/*   Updated: 2021/04/26 08:55:17 by timotheein       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int strcmp(const char *s1, const char *s2)
{
    int i;

    i = -1;
    while (s1[++i])
    {
        if (s1[i] > s2[i])
            return (1);
        if (s1[i] < s2[i])
            return (-1);
    }
    return (0);
}