/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timotheein <timotheein@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:14:21 by timotheein        #+#    #+#             */
/*   Updated: 2021/04/28 10:17:53 by timotheein       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"

# define SA 1
# define SB 2
# define SS 3
# define PA 4
# define PB 5
# define RA 6
# define RB 7
# define RR 8
# define RRA 9
# define RRB 10
# define RRR 11

typedef struct	s_int_list
{
	int			content;
	struct s_int_list	*next;
}				t_int_list;

// typedef struct	s_list
// {
// 	void			*content;
// 	struct s_list	*next;
// }				t_list;

typedef struct s_all
{
    t_list *sk_a;
    t_list *sk_b;
    t_int_list *instruction;
    int check;
}				t_all;

// Checker
void			check_result(t_all *all);
int				intitialize_all(t_all *all);
int				is_int(char *str);
int				check_n_get_arguments(int ac, char **av, t_all *all);
int				check_instruction(t_int_list *instruction, char *line);
int				read_instruction(t_all *all);
int				check_order(t_all *all);
int				execute_instruction(t_all *all);
void			sa(t_all *all);
void			sb(t_all *all);
void			ss(t_all *all);
void			pa(t_all *all);
void			pb(t_all *all);
void			ra(t_all *all);
void			rb(t_all *all);
void			rr(t_all *all);
void			rra(t_all *all);
void			rrb(t_all *all);
void			rrr(t_all *all);


#endif