/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlucca <edlucca@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:17:03 by edlucca           #+#    #+#             */
/*   Updated: 2025/06/19 15:49:21 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// Libraries
# include "../lib/libft/include/libft.h"
# include <stdbool.h>
# include <limits.h>

typedef struct s_info
{
	int moves;
	int rotate;
	int reverse;
} t_info;

typedef struct s_stack
{
	int		nbr;
	t_info	info;
	struct s_stack *next;
} t_stack;

// check_data.c
char	**check_args(int ac, char **av);
void	stack_append(t_stack **st_a, int nbr);
void	create_stack (int ac, char **av, t_stack **st_a);

// check_errors.c
bool	int_check(char *str);
bool	syntax_check(char *str);
bool	ascending_check(t_stack **st_a);
bool	duplicates_check(t_stack *st_a);
bool	overflow_check(long nbr, int sign, char c);

// push_swap.c
void	long_check(char *str);
void	push_swap(char **av, t_stack **st);

// executions_choice.c
void	ra_rra(t_stack **st_a, t_stack *node);
void	rb_rrb(t_stack **st_b, t_stack *node);
void	ra_rb_rr(t_stack **st_a, t_stack **st_b, t_stack *node, t_stack *target);
void	rra_rrb_rrr(t_stack **st_a, t_stack **st_b, t_stack *node, t_stack *target);

//operations_a
void	a_to_b(t_stack **src, t_stack **dst);
t_stack	*find_target_b(t_stack **dst, t_stack *node);
t_stack	*find_node_b(t_stack **src, t_stack **dst);
int	execute_a(t_stack **src, t_stack **dst, t_stack *node, t_stack *target);

// operations_b.c
void	b_to_a(t_stack **src, t_stack **dst);
t_stack	*find_target_a(t_stack **dst, t_stack *node);
t_stack	*find_node_a(t_stack **src, t_stack **dst);
int		execute_b(t_stack **src, t_stack **dst, t_stack *node, t_stack *target);

// stack operations
int	stack_size(t_stack **st);
int	stack_max(t_stack **stack);
int	stack_min(t_stack **stack);
int	stack_position(t_stack **stack, int nbr);
t_stack	*stack_last(t_stack **st);

// sort.c
void	sort_three(t_stack **st_a);
void	sort_big(t_stack **st_a, t_stack **st_b);
void	sort_stack(t_stack **st_a, t_stack **st_b);

// moves 
void	move_push(t_stack **src, t_stack **dst);
void	push_a(t_stack **src, t_stack **dst);
void	push_b(t_stack **src, t_stack **dst);

void	move_swap(t_stack **src);
void	swap_a(t_stack **st);
void	swap_b(t_stack **st);
void	swap_s(t_stack **st_a, t_stack **st_b);

void	move_rotate(t_stack **src);
void	rotate_a(t_stack **st);
void	rotate_b(t_stack **st);
void	rotate_r(t_stack **st_a, t_stack **st_b);

void	move_reverse_rotate(t_stack **src);
void	reverse_rotate_a(t_stack **st);
void	reverse_rotate_b(t_stack **st);
void	reverse_rotate_r(t_stack **st_a, t_stack **st_b);

// utils
int		max_return(int a, int b);
void	free_stack(t_stack **st);
void	free_arrays(char **av);
void	error_found(void);
void	free_exit(t_stack **st_a, t_stack **st_b);


// delete
void print_stack(t_stack *stack, char *name);

#endif // !PUSH_SWAP_H
