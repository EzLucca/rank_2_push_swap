/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushing_b_to_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 08:58:22 by hutzig            #+#    #+#             */
/*   Updated: 2025/06/17 14:48:50 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*target_in_a(t_stack **a, t_stack *node_b)
{
	t_stack	*node_a;
	t_stack	*tmp;

	tmp = *a;
	node_a = NULL;
	if (node_b->nb < tmp->nb && node_b->nb > ft_stack_last(&tmp)->nb)
		return (tmp);
	if (node_b->nb > ft_stack_max(a) || node_b->nb < ft_stack_min(a))
	{
		while (tmp->nb != ft_stack_min(a))
			tmp = tmp->next;
		node_a = tmp;
	}
	while (tmp->next)
	{
		if (node_b->nb > tmp->nb && node_b->nb < tmp->next->nb)
			node_a = tmp->next;
		tmp = tmp->next;
	}
	return (node_a);
}

int	moves_to_a(t_stack **a, t_stack **b, t_stack *node, t_stack *target)
{
	int	moves;
	int	rev_moves;

	node->info.rotate = ft_stack_position(b, node->nb);
	target->info.rotate = ft_stack_position(a, target->nb);
	node->info.reverse = ft_stack_size(b) - ft_stack_position(b, node->nb);
	target->info.reverse = ft_stack_size(a) - ft_stack_position(a, target->nb);
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

t_stack	*find_node_to_push_to_a(t_stack **a, t_stack **b)
{
	t_stack	*node;
	t_stack	*target;
	t_stack	*tmp;
	int		min_moves;
	int		moves;

	tmp = *b;
	node = NULL;
	moves = INT_MAX;
	while (tmp)
	{
		target = target_in_a(a, tmp);
		min_moves = moves_to_a(a, b, tmp, target);
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

void	pushing_from_b_to_a(t_stack **a, t_stack **b)
{
	t_stack	*node_b;
	t_stack	*target;

	while (*b)
	{
		node_b = find_node_to_push_to_a(a, b);
		target = target_in_a(a, node_b);
		if (node_b->info.moves == node_b->info.rotate
			|| node_b->info.moves == target->info.rotate)
			rr_ra_rb(a, b, target, node_b);
		else if (node_b->info.moves == node_b->info.reverse
			|| node_b->info.moves == target->info.reverse)
			rrr_rra_rrb(a, b, target, node_b);
		else
		{
			ra_or_rra(a, target);
			rb_or_rrb(b, node_b);
		}
		pa(b, a);
	}	
}
