/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 12:03:36 by jingwu            #+#    #+#             */
/*   Updated: 2024/08/14 10:47:51 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/libft/libft.h"

# define ARG_MAX_NUM (1025)

typedef struct s_stack
{
	int					nbr;
	struct s_stack		*next;
}	t_stack;

// push_swap_main
void		check_args(int ac, char **av);

// process_args
t_stack		*process_args(int argc, char **argv);
void		sub_process(char *str, t_stack **a);
int			ft_atoi_v2(char *str, t_stack **stack, char **strs);
int			is_duplicated(t_stack *stack);

// sort_ascending
void		sort_ascending(t_stack **stack_a);
t_stack		*push_sort_b(t_stack **stack_a);
t_stack		**push_sort_a(t_stack **stack_a, t_stack **stack_b);
void		sort_3(t_stack **stack);
void		sort_till_3(t_stack **stack_a, t_stack **stack_b);

// sort_caculate_steps
int			find_cheapest_steps_to_b(t_stack *a, t_stack *b);
int			find_cheapest_steps_to_a(t_stack *a, t_stack *b);

// sort_caculate_steps_assit
int			if_rarb(t_stack *a, t_stack *b, int num, int direction);
int			if_rrarrb(t_stack *a, t_stack *b, int num, int direction);
int			if_rrarb(t_stack *a, t_stack *b, int num, int direction);
int			if_rarrb(t_stack *a, t_stack *b, int num, int direction);

// operations_swap_push
void		swap(t_stack **s, int direction, int if_print);
void		push(t_stack **depa, t_stack **dest, int direction, int if_print);

// operations_rotate
void		rotate(t_stack **s, char direction, int if_print);
void		rotate_rr(t_stack **stack_a, t_stack **stack_b, int if_print);
void		rev_rotate(t_stack **s, char direction, int if_print);
void		rev_rotate_rrr(t_stack **stack_a, t_stack **stack_b, int if_print);

// operation_combs
int			execute_rarb(t_stack **a, t_stack **b, int num, int direction);
int			execute_rrarrb(t_stack **a, t_stack **b, int num, int direction);
int			execute_rrarb(t_stack **a, t_stack **b, int num, int direction);
int			execute_rarrb(t_stack **a, t_stack **b, int num, int direction);

// util_basic
void		free_stack(t_stack **stack);
void		free_strs_stack(char **strs, t_stack **stack);
void		free_str(char **str);
void		ft_error(void);
int			is_sorted(t_stack *stack);

// util_stacklist1
void		stack_add_back(t_stack **lst, t_stack *new);
t_stack		*stack_last(t_stack *lst);
t_stack		*stack_newnode(int content);
int			stack_size(t_stack *stack);

// util_stacklist2_find
int			min_value(t_stack *stack);
int			max_value(t_stack *stack);
int			find_index(t_stack *stack, int value);
int			find_place_in_stack_b(t_stack *a, int num);
int			find_place_in_stack_a(t_stack *b, int num);

#endif
