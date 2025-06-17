/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlucca <edlucca@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:17:03 by edlucca           #+#    #+#             */
/*   Updated: 2025/06/17 15:21:59 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// Libraries
# include "library/libft/libft.h"
# include <stdbool.h>

typedef struct s_stack
{
	int		*a;
	int		*b;
	int		ac;
	int		height_a;
	int		height_b;
	struct s_ps *next;
} t_stack;

// input_validation.c
int		ft_isdigit_mod(int c);
void	check_repetition(char **av);
void	check_int(char **av);
char	**input_validation(char **av, bool split);

// error Handling

// push_swap.c
void	long_check(char *str);
void	push_swap(char **av, t_stack **st);

// stack operations
int	initialize_stacks(int ac, char **av, t_stack *st, int number_count);
t_stack	*ft_stack_last(t_stack **st);

// moves 
void	move_push(t_stack **st_c, t_stack **st_d);
void	push_a(t_stack **st_b, t_stack **st_a);
void	push_b(t_stack **st_a, t_stack **st_b);

void	move_swap(t_stack **st);
void	swap_a(t_stack **st);
void	swap_b(t_stack **st);
void	swap_s(t_stack **st_a, t_stack **st_b);

void	move_rotate(t_stack **st);
void	rotate_ra(t_stack **st);
void	rotate_rb(t_stack **st);
void	rotate_rr(t_stack **st_a, t_stack **st_b);

void	move_reverse_rotate(t_stack **st);
void	reverse_rotate_a(t_stack **st);
void	reverse_rotate_b(t_stack **st);
void	reverse_rotate_r(t_stack **st_a, t_stack **st_b);

// utils
void	free_stack(t_stack **st);
void	free_arrays(char **av);
void	error(t_stack **st, int num);
#endif // !PUSH_SWAP_H
