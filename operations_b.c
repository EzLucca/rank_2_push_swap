/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlucca <edlucca@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 15:17:16 by edlucca           #+#    #+#             */
/*   Updated: 2025/06/19 16:48:54 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_target_a(t_stack **dst, t_stack *node)
{
	t_stack	*target;
	t_stack	*tmp;

	tmp = *dst;
	target = NULL;
	if (node->nbr > tmp->nbr && node->nbr < stack_last(&tmp)->nbr)
		return (tmp);
	if (node->nbr < stack_max(dst) || node->nbr > stack_min(dst))
	{
		while (tmp->nbr != stack_min(dst))
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

int	execute_b(t_stack **src, t_stack **dst, t_stack *node, t_stack *target)
{
	int	moves;
	int	rev_moves;

	node->info.rotate = stack_position(src, node->nbr);
	target->info.rotate = stack_position(dst, target->nbr);
	node->info.reverse = stack_size(src) - stack_position(src, node->nbr);
	target->info.reverse = stack_size(dst) - stack_position(dst, target->nbr);
	moves = max_return(node->info.rotate, target->info.rotate);
	rev_moves = max_return(node->info.reverse, target->info.reverse);
	if (moves > node->info.rotate + target->info.reverse)
		moves = node->info.rotate + target->info.reverse;
	if (moves > node->info.reverse + target->info.rotate)
		moves = node->info.reverse + target->info.rotate;
	if (moves > rev_moves)
		moves = rev_moves;
	return (moves);
}

t_stack	*find_node_b(t_stack **src, t_stack **dst)
{
	t_stack *node;
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
		min = execute_b(src, dst, tmp, target);
		if (moves > min)
		{
			tmp->info.moves = min;
			moves = min;
			node = tmp;
		}
		tmp = tmp->next;
	}
	return (node);
}

void	b_to_a(t_stack **src, t_stack **dst)
{
	t_stack	*node;
	t_stack	*target;

	while(*src)
	{
		node = find_node_a(src, dst);
		target = find_target_a(dst, node);
		if (node->info.moves == node->info.rotate
				|| node->info.moves == target->info.rotate)
			ra_rb_rr(src, dst, node, target);
		else if (node->info.moves == target->info.reverse 
				|| node->info.moves == target->info.reverse)
			rra_rrb_rrr(src, dst, node, target);
		else
		{
			ra_rra(src, node);
			rb_rrb(dst, target);
		}
		push_b(src, dst);
	}
}
