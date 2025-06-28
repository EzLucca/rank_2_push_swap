/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlucca <edlucca@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 20:58:41 by edlucca           #+#    #+#             */
/*   Updated: 2025/06/28 16:38:25 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief Frees all nodes in a stack.
 *
 * Iterates through the stack and deallocates each node.
 *
 * @param stack Pointer to the stack to free.
 */
void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

/**
 * @brief Prints an error message and exits the program.
 *
 * Outputs "Error" to standard error and terminates the program with exit 
 * code 1.
 * Used when input validation or other fatal conditions are encountered.
 */
void	error_found(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

/**
 * @brief Frees both stacks and exits the program.
 *
 * Safely free the memory from stacks A and B and terminates the program.
 * Typically used for clean exits after errors or at program end.
 *
 * @param a Pointer to stack A.
 * @param b Pointer to stack B.
 */
void	free_exit(t_stack **a, t_stack **b)
{
	free_stack(a);
	free_stack(b);
	exit(0);
}

/**
 * @brief Returns the maximum of two integers.
 *
 * Simple utility function used in move cost calculations.
 *
 * @param a First integer.
 * @param b Second integer.
 * @return The larger of the two integers.
 */
int	max_return(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}
