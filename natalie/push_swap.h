/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeintje <nmeintje@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 09:38:52 by nmeintje          #+#    #+#             */
/*   Updated: 2024/08/14 10:43:43 by nmeintje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <limits.h>

// STRUCTS
typedef struct s_stack
{
	int					num;
	int					index;
	struct s_stack		*next;
}	t_stack;

typedef struct s_steps
{
	int	rotate;
	int	reverse;
}	t_steps;

// PUSH SWAP OPERATIONS
void	ft_sa(t_stack **a);
void	ft_pa(t_stack **a, t_stack **b);
void	ft_pb(t_stack **a, t_stack **b);

// ROTATE OPERATIONS
void	ft_ra(t_stack **a);
void	ft_rb(t_stack **b);
void	ft_rr_a(t_stack **a, t_stack **b);
void	ft_rr_b(t_stack **b);

// REVERSE ROTATE OPERATIONS
void	ft_rra(t_stack **a);
void	ft_rrb(t_stack **b);
void	ft_rrr_a(t_stack **a, t_stack **b);
void	ft_rrr_b(t_stack **b);

// LIST FUNCTIONS
t_stack	*ft_lstlast(t_stack *stack);
void	ft_lstadd_back(t_stack **stack, t_stack *new);
t_stack	*ft_lstnew(int content);
int		ft_lstsize(t_stack *stack);

// ARGUMENT PROCESSING
t_stack	*ft_split_string(char **argv);
int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_isdigit(int c);
int		min_value(t_stack *stack);
int		max_value(t_stack *stack);
int		ft_check_sorted(t_stack *stack_a);
int		ft_find_index(t_stack *a, int nbr);
void	ft_swap(int *a, int *b);
void	ft_assign_index(t_stack **stack);
t_stack	*min_index(t_stack *stack);
t_stack	*max_index(t_stack *stack);

// SORTING FUNCTIONS
void	ft_sort(t_stack **stack_a);
void	ft_sort_small(t_stack **stack_a);
void	ft_sort_three(t_stack **a);
void	ft_sort_large(t_stack **stack_a, t_stack **b);
void	populate_stack_b(t_stack **a, t_stack **b);
void	populate_stack_a(t_stack **a, t_stack **b);
t_stack	*find_position_in_b(t_stack **b, int index);
t_stack	*mid_pos_in_stack_a(t_stack *stack, t_stack *node);
t_stack	*node_new_pos_a(t_stack **a, t_stack *node);
void	calculate_steps_to_head(t_stack **head, t_stack *node, t_steps *steps);
int		ft_move_cost(t_stack **a, t_stack **b, t_stack *cur_a, t_stack *tar_b);
int		dist_w_rot(t_stack *current, t_stack **head);
int		dist_w_rev(t_stack *current, t_stack **head);
void	minimum_to_top(t_stack **a);

// FREE AND ERROR
void	ft_free(t_stack **stack);
void	ft_free_str(char **stack);
void	ft_error(void);

#endif
