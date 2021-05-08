/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timotheein <timotheein@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:14:21 by timotheein        #+#    #+#             */
/*   Updated: 2021/05/08 17:51:29 by timotheein       ###   ########.fr       */
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

typedef struct	s_all
{
	int		len_a;
	int		len_t;
	int		p_low;
	int		v_low;
	int		p_hig;
	int		v_hig;
	int		p_tomov;
	int		is_tomov_low;
	int		midd;
	int		min;
	int		min_sent;
	int		p_min;
	int		max;
	int		p_s;
	int		bonus;
	t_list	*sk_a;
	t_list	*sk_b;
	t_list	*instruction;
	int		check;
}				t_all;

void			end_algo(t_all *all);
int				ft_strlen_ps(const char *s);
void			find_lowest_values_a(t_all *all);
int				check_order_sk_a(t_all *all);
void			send_mid_hig_to_top(t_all *all);
void			make_final_ordering(t_all *all);
void			reverse_send_to_top(t_all *all);
void			send_to_top(t_all *all);
int				in_order(t_all *all);
void			find_value_to_move(t_all *all);
void			find_middle_value(t_all *all);
void			find_close_mid_values(t_all *all);
void			execute_algo_2(t_all *all);
int				sk_a_ordered_by_packet(t_all *all);
void			find_value_to_move(t_all *all);
void			send_closest_value_to_top(t_all *all);
void			reverse_send_closest_value_to_top(t_all *all);
int				error_arguments(t_all *all);
int				error_instruction(t_all *all);
int				error_execution(t_all *all);
void			check_result(t_all *all);
void			print_elt(t_all *all);
int				freeer(t_all *all);
void			print_action(char *action, t_all *all);
void			print_init(t_all *all);
void			execute(char *action, t_all *all);
void			check_result(t_all *all);
int				intitialize_all(t_all *all);
int				is_int(char *str);
int				check_n_get_arguments(int ac, char **av, t_all *all);
int				check_instruction(char *line);
int				read_instruction(t_all *all);
int				check_final_order(t_all *all);
int				execute_instruction(t_all *all);
int				max_lgth(t_list *e);
void			write_tacks(t_all *all);
void			write_spaces(t_all *all);
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
void			print_elt(t_all *all);

#endif
