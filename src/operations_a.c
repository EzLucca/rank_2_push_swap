/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlucca <edlucca@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 11:04:59 by edlucca           #+#    #+#             */
/*   Updated: 2025/06/26 18:01:29 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*find_target_b(t_stack **dst, t_stack *node)
{
	t_stack	*target;
	t_stack	*tmp;
	int		min;
	int		max;

	tmp = *dst;
	target = NULL;
	min = stack_min(dst);
	max = stack_max(dst);
	if (node->nbr > tmp->nbr && node->nbr < stack_last(&tmp)->nbr)
		return (tmp);
	else if (node->nbr > max || node->nbr < min)
	{
		while (tmp->nbr != max)
			tmp = tmp->next;
		target = tmp;
	}
	while (tmp->next)
	{
		if (node->nbr < tmp->nbr && node->nbr > tmp->next->nbr)
			target = tmp->next;
		tmp = tmp->next;
	}
	return (target);
}

int	execute_a(t_stack **src, t_stack **dst, t_stack *node, t_stack *target)
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

t_stack	*find_node_a(t_stack **src, t_stack **dst)
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
		target = find_target_b(dst, tmp);
		min = execute_a(src, dst, tmp, target);
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

void	a_to_b(t_stack **src, t_stack **dst)
{
	t_stack	*node;
	t_stack	*target;

	while (stack_size(src) > 3 && !ascending_check(src))
	{
		node = find_node_a(src, dst);
		target = find_target_b(dst, node);
		if (node->moves == node->rotate
			|| node->moves == target->rotate)
			ra_rb_rr(src, dst, node, target);
		else if (node->moves == node->reverse
			|| node->moves == target->reverse)
			rra_rrb_rrr(src, dst, node, target);
		else
		{
			ra_rra(src, node);
			rb_rrb(dst, target);
		}
		push_b(src, dst);
	}
}
