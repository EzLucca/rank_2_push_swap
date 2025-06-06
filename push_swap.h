/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlucca <edlucca@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:17:03 by edlucca           #+#    #+#             */
/*   Updated: 2025/06/04 11:25:28 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// Libraries
# include "library/libft.h"

typedef struct s_ps
{
	int		*a;
	int		*b;
	int		ac;
	int		height_a;
	int		height_b;
} t_ps;

// Input validation
int	input_validation(int ac, char **av, t_ps *stack);
// // Check for doubles
int	double_validation(t_ps *stack);
// // check int size
// // check integers
int	number_validation(int ac, char **av);
int	ft_isnum(char *str);
// error Handling
// stack operations
int	initialize_stacks(int ac, char **av, t_ps *stack, int number_count);
// moves 
#endif // !PUSH_SWAP_H
