/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlucca <edlucca@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 11:05:38 by edlucca           #+#    #+#             */
/*   Updated: 2025/06/26 18:01:37 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
