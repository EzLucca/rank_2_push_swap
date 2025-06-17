/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushing_a_to_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 08:55:06 by hutzig            #+#    #+#             */
/*   Updated: 2025/06/17 14:48:20 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*target_in_b(t_stack **b, t_stack *node_a)
{
	t_stack	*node_b;
	t_stack	*tmp;

	tmp = *b;
	node_b = NULL;
	if (node_a->nb > tmp->nb && node_a->nb < ft_stack_last(&tmp)->nb)
		return (tmp);
	else if (node_a->nb > ft_stack_max(b) || node_a->nb < ft_stack_min(b))
	{
		while (tmp->nb != ft_stack_max(b))
			tmp = tmp->next;
		node_b = tmp;
	}
	while (tmp->next)
	{
		if (node_a->nb < tmp->nb && node_a->nb > tmp->next->nb)
			node_b = tmp->next;
		tmp = tmp->next;
	}
	return (node_b);
}

int	moves_to_b(t_stack **a, t_stack **b, t_stack *node, t_stack *target)
{
	int	moves;
	int	rev_moves;

	node->info.rotate = ft_stack_position(a, node->nb);
	target->info.rotate = ft_stack_position(b, target->nb);
	node->info.reverse = ft_stack_size(a) - ft_stack_position(a, node->nb);
	target->info.reverse = ft_stack_size(b) - ft_stack_position(b, target->nb);
	moves = ft_max(node->info.rotate, target->info.rotate);
	rev_moves = ft_max(node->info.reverse, target->info.reverse);
	if (moves > node->info.rotate + target->info.reverse)
		moves = node->info.rotate + target->info.reverse;
	if (moves > node->info.reverse + target->info.rotate)
		moves = node->info.reverse + target->info.rotate;
	if (moves > rev_moves)
		moves = rev_moves;
	return (moves);
}

t_stack	*find_node_to_push_to_b(t_stack **a, t_stack **b)
{
	t_stack	*node;
	t_stack	*target;
	t_stack	*tmp;
	int		min_moves;
	int		moves;

	tmp = *a;
	node = NULL;
	moves = INT_MAX;
	while (tmp)
	{	
		target = target_in_b(b, tmp);
		min_moves = moves_to_b(a, b, tmp, target);
		if (moves > min_moves)
		{
			tmp->info.moves = min_moves;
			moves = min_moves;
			node = tmp;
		}
		tmp = tmp->next;
	}
	return (node);
}

void	pushing_from_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*node_a;
	t_stack	*target;

	while (ft_stack_size(a) > 3 && !stack_sorting_check(a))
	{
		node_a = find_node_to_push_to_b(a, b);
		target = target_in_b(b, node_a);
		if (node_a->info.moves == node_a->info.rotate
			|| node_a->info.moves == target->info.rotate)
			rr_ra_rb(a, b, node_a, target);
		else if (node_a->info.moves == node_a->info.reverse
			|| node_a->info.moves == target->info.reverse)
			rrr_rra_rrb(a, b, node_a, target);
		else
		{
			ra_or_rra(a, node_a);
			rb_or_rrb(b, target);
		}
		pb(a, b);
	}
}
