/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlucca <edlucca@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:11:03 by edlucca           #+#    #+#             */
/*   Updated: 2025/06/28 16:20:31 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief Moves the top element of the stack to the bottom.
 *
 * Performs a single rotation on the given stack by moving the first
 * element to the end of the list.
 *
 * @param stack Pointer to the stack to rotate.
 */
void	move_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	first = *stack;
	last = stack_last(stack);
	*stack = first->next;
	first->next = NULL;
	last->next = first;
}

/**
 * @brief Performs the 'ra' operation: rotate stack A.
 *
 * Moves the top element of stack A to the bottom and prints "ra".
 * If the stack has fewer than 2 elements, the operation is ignored.
 *
 * @param stack Pointer to stack A.
 */
void	rotate_a(t_stack **stack)
{
	if (!(*stack) || !(*stack)->next)
		return ;
	move_rotate(stack);
	ft_printf("ra\n");
}

/**
 * @brief Performs the 'rb' operation: rotate stack B.
 *
 * Moves the top element of stack B to the bottom and prints "rb".
 * If the stack has fewer than 2 elements, the operation is ignored.
 *
 * @param stack Pointer to stack B.
 */
void	rotate_b(t_stack **stack)
{
	if (!(*stack) || !(*stack)->next)
		return ;
	move_rotate(stack);
	ft_printf("rb\n");
}

/**
 * @brief Performs the 'rr' operation: rotate both stacks A and B.
 *
 * Moves the top element of both stacks to the bottom simultaneously,
 * and prints "rr". If either stack has fewer than 2 elements,
 * the operation is ignored.
 *
 * @param a Pointer to stack A.
 * @param b Pointer to stack B.
 */
void	rotate_r(t_stack **a, t_stack **b)
{
	if (!(*a) || !(*b) || !(*a)->next || !(*b)->next)
		return ;
	move_rotate(a);
	move_rotate(b);
	ft_printf("rr\n");
}
