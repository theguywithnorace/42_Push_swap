/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timotheein <timotheein@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:14:21 by timotheein        #+#    #+#             */
/*   Updated: 2021/05/13 13:03:43 by timotheein       ###   ########.fr       */
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

# define BKED 3
# define OLD -1
# define PIVOT 1



typedef struct	s_all
{
	// int		i_nxtp;
	int		v_nxtp;

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
	t_elt	*sk_a;
	t_elt	*sk_b;
	t_list	*instruction;
	int		check;
}				t_all;


//main
void execute_algo(t_all *all);


//pivot algo
void get_pivots(t_elt *elt, int s);
int find_midd(t_elt *elt);
void	find_pivot(t_elt *e, int midd, int s);

//ps_actions_to_b
void send_low_values_b(t_all *all);
void send_pivot_b(t_all *all);
void stock_hig_values_a(t_all *all);
void set_pivot_top_b(t_all *all);
void send_hig_values_b(t_all *all);
int is_last_seen(t_elt *e);
int is_all_end_sup(t_elt *e, int max);
void set_bked_sk(t_elt *e);
void set_pivot_at_top(t_all *all);
int less_elt_than(int n, t_elt *e);
void quick_send_b(t_all *all);



//ps_actions to a
void send_low_values_a(t_all *all);
void send_pivot_a(t_all *all);
void stock_low_values_b(t_all *all);
void set_pivot_top_a(t_all *all);
void send_hig_values_a(t_all *all);
int is_all_end_inf(t_elt *e, int max);
void quick_send_a(t_all *all);





int eq(t_elt *elt, int v);
int val(t_elt *e);
void set_next_pivot(t_all *all, t_elt *e);
void send_to_b(t_all *all);
void send_to_a(t_all *all);
int		is_still_less_than_pvt(t_all *all, t_elt *e);
int in_packet(t_all *all, t_elt *e);

//Error and debugger
void bug(char *s, int n);
void print_situation_a(t_all *all);
void print_situation_b(t_all *all);



//Short algo
void execute_short_algo(t_all *all);


void			end_algo(t_all *all);
int				ft_strlen_ps(const char *s);
void			find_lowest_values_a(t_all *all);
int				is_sk_ordered(t_elt *all);
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
int				max_lgth(t_elt *e);
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
