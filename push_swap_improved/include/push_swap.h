/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlucca <edlucca@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:17:03 by edlucca           #+#    #+#             */
/*   Updated: 2025/06/25 17:14:17 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// Libraries
# include "../lib/libft/include/libft.h"
# include <stdbool.h>
# include <limits.h>

typedef enum e_move
{
	A_TO_B,
	B_TO_A,
}	t_move;

typedef struct s_st
{
	int			nbr;
	int			moves;
	int			rotate;
	int			reverse;
	struct s_st	*next;
}	t_st;

// check_data.c
char	**check_args(int ac, char **av);
void	stack_append(t_st **st_a, int nbr);
void	create_stack(int ac, char **av, t_st **st_a);

// check_errors.c
bool	int_check(char *str);
bool	syntax_check(char *str);
bool	ascending_check(t_st **st_a);
bool	duplicates_check(t_st *st_a);
bool	overflow_check(long nbr, int sign, char c);

// push_swap.c
void	long_check(char *str);
void	push_swap(char **av, t_st **st);

// executions_choice.c
void	ra_rra(t_st **st_a, t_st *node);
void	rb_rrb(t_st **st_b, t_st *node);
void	ra_rb_rr(t_st **st_a, t_st **st_b, t_st *node, t_st *target);
void	rra_rrb_rrr(t_st **st_a, t_st **st_b, t_st *node, t_st *target);
int		choose(int cond, int a, int b);

//operations_a
void	src_to_dst(t_st **src, t_st **dst, t_move directions);
// void	stacks_op(t_st **src, t_st **dst, t_move directions);
void	stacks_op1(t_st **src, t_st **dst, t_move dir);
int		min_moves(t_st **src, t_st **dst, t_st *node, t_st *target);
t_st	*find_target(t_st **src, t_st *node, t_move directions);
t_st	*find_node(t_st **src, t_st **dst, t_move directions);

// stack operations
int		stack_size(t_st **st);
int		stack_max(t_st **stack);
int		stack_min(t_st **stack);
int		stack_position(t_st **stack, int nbr);
t_st	*stack_last(t_st **st);

// sort.c
void	sort_three(t_st **st_a);
void	sort_big(t_st **st_a, t_st **st_b);
void	sort_stack(t_st **st_a, t_st **st_b);

// moves 
void	move_push(t_st **src, t_st **dst);
void	push_a(t_st **src, t_st **dst);
void	push_b(t_st **src, t_st **dst);

void	move_swap(t_st **src);
void	swap_a(t_st **st);
void	swap_b(t_st **st);
void	swap_s(t_st **st_a, t_st **st_b);

void	move_rotate(t_st **src);
void	rotate_a(t_st **st);
void	rotate_b(t_st **st);
void	rotate_r(t_st **st_a, t_st **st_b);

void	move_reverse_rotate(t_st **src);
void	reverse_rotate_a(t_st **st);
void	reverse_rotate_b(t_st **st);
void	reverse_rotate_r(t_st **st_a, t_st **st_b);

// utils
int		max_return(int a, int b);
void	free_stack(t_st **st);
void	error_found(void);
void	free_exit(t_st **st_a, t_st **st_b);

// delete
void	print_stack(t_st *stack, char *name);

#endif // !PUSH_SWAP_H
