/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executions_choice.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlucca <edlucca@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:08:50 by edlucca           #+#    #+#             */
/*   Updated: 2025/06/28 16:09:30 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief Rotates both stacks simultaneously (or not) to bring target and node
 * to the top.
 *
 * Performs `rr` (rotate both) while both target nodes are not at the top of
 * their respective stacks. Then completes remaining individual rotations.
 * At the end of this functions both target and node should be on top of each
 * stack.
 *
 * @param a Pointer to stack A.
 * @param b Pointer to stack B.
 * @param node The target node in stack A.
 * @param target The target node in stack B.
 */
void	ra_rb_rr(t_stack **a, t_stack **b, t_stack *node, t_stack *target)
{
	while (*a != node && *b != target)
		rotate_r(a, b);
	while (*a != node)
		rotate_a(a);
	while (*b != target)
		rotate_b(b);
}

/**
 * @brief Reverse rotates both stacks simultaneously(or not)to bring target
 * and node to the top.
 *
 * Performs `rrr` (reverse rotate both) while both target nodes are not at 
 * the top of their stacks. Then completes remaining individual reverse 
 * rotations. At the end of this functions both target and node should be on 
 * top of each stack.
 *
 * @param a Pointer to stack A.
 * @param b Pointer to stack B.
 * @param node The target node in stack A.
 * @param target The target node in stack B.
 */
void	rra_rrb_rrr(t_stack **a, t_stack **b, t_stack *node, t_stack *target)
{
	while (*a != node && *b != target)
		reverse_rotate_r(a, b);
	while (*a != node)
		reverse_rotate_a(a);
	while (*b != target)
		reverse_rotate_b(b);
}

/**
 * @brief Brings a target node in stack A to the top using optimal rotation.
 *
 * Chooses between rotate (`ra`) and reverse rotate (`rra`) based on which
 * requires fewer moves, and applies the chosen operation until the node is
 * at the top.
 *
 * @param a Pointer to stack A.
 * @param node The node to bring to the top.
 */
void	ra_rra(t_stack **a, t_stack *node)
{
	if (node->rotate < node->reverse)
	{
		while (*a != node)
			rotate_a(a);
	}
	else
	{
		while (*a != node)
			reverse_rotate_a(a);
	}
}

/**
 * @brief Brings a target node in stack B to the top using optimal rotation.
 *
 * Chooses between rotate (`rb`) and reverse rotate (`rrb`) based on which
 * requires fewer moves, and applies the chosen operation until the node is 
 * at the top.
 *
 * @param b Pointer to stack B.
 * @param node The node to bring to the top.
 */
void	rb_rrb(t_stack **b, t_stack *node)
{
	if (node->rotate < node->reverse)
	{
		while (*b != node)
			rotate_b(b);
	}
	else
	{
		while (*b != node)
			reverse_rotate_b(b);
	}
}
