/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:05:05 by hutzig            #+#    #+#             */
/*   Updated: 2024/08/30 17:49:47 by hutzig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/libft/libft.h"
# include <limits.h>
# include <stdbool.h>

typedef struct s_info
{
	int	rotate;
	int	reverse;
	int	moves;
}	t_info;

typedef struct s_stack
{
	int				nb;
	t_info			info;
	struct s_stack	*next;
}	t_stack;

/* sorting functions - main algorithm */
void	stack_sorting(t_stack **a, t_stack **b);
void	sorting_three(t_stack **a);
void	sorting_big(t_stack **a, t_stack **b);

/* pushing from a to b functions */
void	pushing_from_a_to_b(t_stack **a, t_stack **b);
t_stack	*find_node_to_push_to_b(t_stack **a, t_stack **b);
t_stack	*target_in_b(t_stack **b, t_stack *node_a);
int		moves_to_b(t_stack **a, t_stack **b, t_stack *node, t_stack *target);

/* pushing from b to a functions */
void	pushing_from_b_to_a(t_stack **a, t_stack **b);
t_stack	*find_node_to_push_to_a(t_stack **a, t_stack **b);
t_stack	*target_in_a(t_stack **a, t_stack *node_b);
int		moves_to_a(t_stack **a, t_stack **b, t_stack *node, t_stack *target);

/* push_swap operations */
void	pa(t_stack **b, t_stack **a);
void	pb(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	sa(t_stack **a);
void	sb(t_stack **b);

/* execute operations */
void	rr_ra_rb(t_stack **a, t_stack **b, t_stack *node_a, t_stack *node_b);
void	rrr_rra_rrb(t_stack **a, t_stack **b, t_stack *node_a, t_stack *node_b);
void	ra_or_rra(t_stack **a, t_stack *node);
void	rb_or_rrb(t_stack **a, t_stack *node);

/* utils functions */
t_stack	*ft_stack_last(t_stack **stack);
int		ft_stack_size(t_stack **stack);
int		ft_stack_min(t_stack **stack);
int		ft_stack_max(t_stack **stack);
int		ft_stack_position(t_stack **stack, int nb);

/* checkings and processing arguments */
void	stack_processing(int argc, char **argv, t_stack **a);
bool	stack_sorting_check(t_stack **a);
bool	stack_checking_dup(t_stack *a);
bool	checking_syntax_error(char *str);
bool	checking_is_integer(char *str);

/* error and free */
void	ft_error(void);
void	ft_free_array(char **args);
void	ft_free_stack(t_stack **a);
void	exit_success(t_stack **a, t_stack **b);
void	exit_failure(t_stack **a, t_stack **b);

#endif
