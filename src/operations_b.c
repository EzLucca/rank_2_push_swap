/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlucca <edlucca@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 11:05:38 by edlucca           #+#    #+#             */
/*   Updated: 2025/06/28 16:30:55 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief Finds the optimal insertion point in stack A for a node from stack B.
 *
 * Determines the best target position in stack A where the given node from
 * stack B should be placed to maintain ascending order.
 * If the node is smaller than the min or larger than the max, returns the min 
 * node.
 *
 * @param src Pointer to stack A.
 * @param node The node from stack B to be inserted.
 * @return Pointer to the target node in stack A.
 */
t_stack	*find_target_a(t_stack **src, t_stack *node)
{
	t_stack	*target;
	t_stack	*tmp;
	int		min;
	int		max;

	tmp = *src;
	target = NULL;
	min = stack_min(src);
	max = stack_max(src);
	if (node->nbr < tmp->nbr && node->nbr > stack_last(&tmp)->nbr)
		return (tmp);
	if (node->nbr > max || node->nbr < min)
	{
		while (tmp->nbr != min)
			tmp = tmp->next;
		target = tmp;
	}
	while (tmp->next)
	{
		if (node->nbr > tmp->nbr && node->nbr < tmp->next->nbr)
			target = tmp->next;
		tmp = tmp->next;
	}
	return (target);
}

/**
 * @brief Calculates the minimum number of moves required to push a node from 
 * B to A.
 *
 * Computes and compares all possible combinations of rotate and reverse rotate
 * to bring both the source node and its target position to the top.
 *
 * @param dst Pointer to stack A.
 * @param src Pointer to stack B.
 * @param node The node in stack B to be moved.
 * @param target The target position in stack A.
 * @return Minimum number of moves needed to perform the push.
 */
int	execute_b(t_stack **dst, t_stack **src, t_stack *node, t_stack *target)
{
	int	moves;
	int	rev_moves;

	node->rotate = stack_position(src, node->nbr);
	target->rotate = stack_position(dst, target->nbr);
	node->reverse = stack_size(src) - stack_position(src, node->nbr);
	target->reverse = stack_size(dst) - stack_position(dst, target->nbr);
	moves = max_return(node->rotate, target->rotate);
	rev_moves = max_return(node->reverse, target->reverse);
	if (moves > node->rotate + target->reverse)
		moves = node->rotate + target->reverse;
	if (moves > node->reverse + target->rotate)
		moves = node->reverse + target->rotate;
	if (moves > rev_moves)
		moves = rev_moves;
	return (moves);
}

/**
 * @brief Finds the best node in stack B to move to stack A.
 *
 * Iterates over all nodes in stack B and calculates the cheapest node to move
 * (in terms of operation count) by evaluating each node's optimal target
 * in stack A using `find_target_a` and `execute_b`.
 *
 * @param dst Pointer to stack A.
 * @param src Pointer to stack B.
 * @return Pointer to the node in stack B that should be moved next.
 */
t_stack	*find_node_b(t_stack **dst, t_stack **src)
{
	t_stack	*node;
	t_stack	*target;
	t_stack	*tmp;
	int		min;
	int		moves;

	tmp = *src;
	node = NULL;
	moves = INT_MAX;
	while (tmp)
	{
		target = find_target_a(dst, tmp);
		min = execute_b(dst, src, tmp, target);
		if (moves > min)
		{
			tmp->moves = min;
			moves = min;
			node = tmp;
		}
		tmp = tmp->next;
	}
	return (node);
}

/**
 * @brief Moves all elements from stack B back to stack A in sorted order.
 *
 * Continuously finds the cheapest node to move from B to A, calculates its
 * ideal target position in A, and performs the optimal combination of rotations
 * to bring both nodes to the top before executing the push.
 *
 * @param dst Pointer to stack A (destination).
 * @param src Pointer to stack B (source).
 */
void	b_to_a(t_stack **dst, t_stack **src)
{
	t_stack	*node;
	t_stack	*target;

	while (*src)
	{
		node = find_node_b(dst, src);
		target = find_target_a(dst, node);
		if (node->moves == node->rotate
			|| node->moves == target->rotate)
			ra_rb_rr(dst, src, target, node);
		else if (node->moves == node->reverse
			|| node->moves == target->reverse)
			rra_rrb_rrr(dst, src, target, node);
		else
		{
			ra_rra(dst, target);
			rb_rrb(src, node);
		}
		push_a(src, dst);
	}
}
