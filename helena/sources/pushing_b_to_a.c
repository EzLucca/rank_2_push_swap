/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushing_b_to_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 08:58:22 by hutzig            #+#    #+#             */
/*   Updated: 2025/06/19 16:15:01 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*target_in_a(t_stack **dst, t_stack *node)
{
	t_stack	*target;
	t_stack	*tmp;

	tmp = *dst;
	target = NULL;
	if (node->nb < tmp->nb && node->nb > ft_stack_last(&tmp)->nb)
		return (tmp);
	if (node->nb > ft_stack_max(dst) || node->nb < ft_stack_min(dst))
	{
		while (tmp->nb != ft_stack_min(dst))
			tmp = tmp->next;
		target = tmp;
	}
	while (tmp->next)
	{
		if (node->nb > tmp->nb && node->nb < tmp->next->nb)
			target = tmp->next;
		tmp = tmp->next;
	}
	return (target);
}

int	moves_to_a(t_stack **dst, t_stack **src, t_stack *node, t_stack *target)
{
	int	moves;
	int	rev_moves;

	node->info.rotate = ft_stack_position(src, node->nb);
	target->info.rotate = ft_stack_position(dst, target->nb);
	node->info.reverse = ft_stack_size(src) - ft_stack_position(src, node->nb);
	target->info.reverse = ft_stack_size(dst) - ft_stack_position(dst, target->nb);
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

t_stack	*find_node_to_push_to_a(t_stack **dst, t_stack **src)
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
		target = target_in_a(dst, tmp);
		min = moves_to_a(dst, src, tmp, target);
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

void	pushing_from_b_to_a(t_stack **dst, t_stack **src)
{
	t_stack	*node;
	t_stack	*target;

	while (*src)
	{
		node = find_node_to_push_to_a(dst, src);
		target = target_in_a(dst, node);
		if (node->info.moves == node->info.rotate
			|| node->info.moves == target->info.rotate)
			rr_ra_rb(dst, src, target, node);
		else if (node->info.moves == node->info.reverse
			|| node->info.moves == target->info.reverse)
			rrr_rra_rrb(dst, src, target, node);
		else
		{
			ra_or_rra(dst, target);
			rb_or_rrb(src, node);
		}
		pa(src, dst);
	}	
}
