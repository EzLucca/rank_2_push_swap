/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlucca <edlucca@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:17:03 by edlucca           #+#    #+#             */
/*   Updated: 2025/06/16 16:13:11 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// Libraries
# include "library/libft/libft.h"
# include <stdbool.h>

typedef struct s_ps
{
	int		*a;
	int		*b;
	int		ac;
	int		height_a;
	int		height_b;
	struct s_ps *next;
} t_ps;

// Input validation
int	input_validation(int ac, char **av, t_ps *st);
// // Check for doubles
int	double_validation(t_ps *st);
// // check int size
// // check integers
int	number_validation(int ac, char **av);
int	ft_isnum(char *str);

// error Handling

// stack operations
int	initialize_stacks(int ac, char **av, t_ps *st, int number_count);


// moves 
int move_push_a(t_ps *st, int print_flag);
int move_push_b(t_ps *st, int print_flag);

int	move_swap_a(t_ps *st, int print_flag);
int	move_swap_b(t_ps *st, int print_flag);

int move_rotate_a(t_ps *st, int print_flag);
int move_rotate_b(t_ps *st, int print_flag);
int	move_rotate_r(t_ps *st, int print_flag);

int move_reverse_rotate_a(t_ps *st, int print_flag);
int move_reverse_rotate_b(t_ps *st, int print_flag);
int move_reverse_rotate_r(t_ps *st, int print_flag);

// utils
void	free_stacks(t_ps *st);
void	free_array(void ***array);
#endif // !PUSH_SWAP_H
