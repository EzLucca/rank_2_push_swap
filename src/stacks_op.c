/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlucca <edlucca@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 11:34:43 by edlucca           #+#    #+#             */
/*   Updated: 2025/06/28 16:35:56 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief Returns the last node in the stack.
 *
 * Traverses the entire stack and returns a pointer to the last element.
 *
 * @param stack Pointer to the stack.
 * @return Pointer to the last node in the stack.
 */
t_stack	*stack_last(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

/**
 * @brief Calculates the number of elements in the stack.
 *
 * Iterates through the stack to count the total nodes.
 *
 * @param stack Pointer to the stack.
 * @return The number of nodes in the stack.
 */
int	stack_size(t_stack **stack)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

/**
 * @brief Finds the maximum value in the stack.
 *
 * Iterates through the stack to find the largest `nbr` value.
 *
 * @param stack Pointer to the stack.
 * @return The highest integer value found in the stack.
 */
int	stack_max(t_stack **stack)
{
	int		max;
	t_stack	*tmp;

	tmp = *stack;
	max = tmp->nbr;
	while (tmp)
	{
		if (tmp->nbr > max)
			max = tmp->nbr;
		tmp = tmp->next;
	}
	return (max);
}

/**
 * @brief Finds the minimum value in the stack.
 *
 * Iterates through the stack to find the smallest `nbr` value.
 *
 * @param stack Pointer to the stack.
 * @return The lowest integer value found in the stack.
 */
int	stack_min(t_stack **stack)
{
	int		min;
	t_stack	*tmp;

	tmp = *stack;
	min = tmp->nbr;
	while (tmp)
	{
		if (tmp->nbr < min)
			min = tmp->nbr;
		tmp = tmp->next;
	}
	return (min);
}

/**
 * @brief Finds the index of a value in the stack.
 *
 * Returns the 0-based position of the node whose `nbr` matches `nbr`.
 * If the value is not found, returns the position where traversal ends.
 *
 * @param stack Pointer to the stack.
 * @param nbr The number to locate in the stack.
 * @return The index (0-based) of the node with value `nbr`.
 */
int	stack_position(t_stack **stack, int nbr)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = *stack;
	while (tmp && tmp->nbr != nbr)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
