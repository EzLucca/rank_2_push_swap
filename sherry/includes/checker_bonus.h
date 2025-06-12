/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 13:48:38 by jingwu            #+#    #+#             */
/*   Updated: 2024/08/14 10:45:44 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "../lib/get_next_line/get_next_line.h"
# include "../lib/libft/libft.h"

# define ARG_MAX_NUM (1025)

typedef struct s_stack
{
	int					nbr;
	struct s_stack		*next;
}	t_stack;

// checker_main_bonus
void		check_sub(t_stack **a, t_stack **b, char *instrcs);
char		*check(t_stack **a, t_stack **b, char *instrcs);
void		checker(t_stack **a, t_stack **b, char *instrcs);

// process_args_bonus
t_stack		*process_args(int argc, char **argv);
void		sub_process(char *str, t_stack **a);
int			ft_atoi_v2(char *str, char **strs, t_stack **stack);
int			is_duplicated(t_stack *stack);

// util_basic_bonus
void		free_stack(t_stack **stack);
void		free_strs_stack(char **strs, t_stack **stack, int error_type);
void		free_str(char **str);
void		ft_error(int type);
int			is_sorted(t_stack *stack);

// operations_swap_push_bonus
void		swap_bns(t_stack **s);
void		push_bns(t_stack **depa, t_stack **dest);

// operations_rotate_bonus
void		rotate_bns(t_stack **s);
void		rotate_rr_bns(t_stack **stack_a, t_stack **stack_b);
void		rev_rotate_bns(t_stack **s);
void		rev_rotate_rrr_bns(t_stack **stack_a, t_stack **stack_b);

// util_stacklist_bonus
void		stack_add_back(t_stack **stack, t_stack *new);
t_stack		*stack_newnode(int content);
t_stack		*stack_last(t_stack *stack);

#endif
