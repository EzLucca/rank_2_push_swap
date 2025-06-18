/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlucca <edlucca@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:32:30 by edlucca           #+#    #+#             */
/*   Updated: 2025/06/18 17:35:14 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_target_b(t_stack **st_b, t_stack *node)
{
	t_stack	*target;
	t_stack	*tmp;

	tmp = *st_b;
	target = NULL;
	if (node->nbr > tmp->nbr && node->nbr < stack_last(&tmp)->nbr)
		return (tmp);
	else if (node->nbr > stack_max(st_b) || node->nbr < stack_min(st_b))
	{
		while (tmp->nbr != stack_max(st_b))
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

t_stack	*find_node_a(t_stack **st_a, t_stack **st_b)
{
	t_stack *node;
	t_stack	*target;
	t_stack	*tmp;
	int		min;
	int		moves;

	tmp = *st_a;
	node = NULL;
	moves = INT_MAX;
	while (tmp)
	{
		target = find_target_b(st_b, tmp);
		min = execute_b(st_a, st_b, tmp, target);
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

int	execute_b(t_stack **st_a, t_stack **st_b, t_stack *node, t_stack *target)
{
	int	moves;
	int	rev_moves;

	node->info.rotate = stack_position(st_a, node->nbr);
	target->info.rotate = stack_position(st_b, target->nbr);
	node->info.reverse = stack_size(st_a) - stack_position(st_a, node->nbr);
	target->info.reverse = stack_size(st_b) - stack_position(st_b, target->nbr);
	moves = max_return(node->info.rotate, target->info.rotate);
	rev_moves = max_return(node->info.reverse, target->info.reverse);
	if (moves > node->info.rotate + target->info.reverse)
		moves = node->info.rotate + target->info.reverse;
	if (moves > node->info.reverse + target->info.rotate)
		moves = node->info.reverse+ target->info.rotate;
	if (moves > rev_moves)
		moves = rev_moves;
	return (moves);
}

void	a_to_b(t_stack **st_a, t_stack **st_b)
{
	t_stack	*node;
	t_stack	*target;

	while(stack_size(st_a) > 3 && !ascending_check(st_a))
	{
		node = find_node_a(st_a, st_b);
		target = find_target_b(st_b, node);
		if (node->info.moves == node->info.rotate || node->info.moves == target->info.rotate)
			ra_rb_rr(st_a, st_b, node, target);
		else if (node->info.moves == target->info.reverse || node->info.moves == target->info.reverse)
			rra_rrb_rrr(st_a, st_b, node, target);
		else
		{
			ra_rra(st_a, node);
			rb_rrb(st_b, target);
		}
		push_b(st_a, st_b);
	}
}
