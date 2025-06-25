/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlucca <edlucca@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 15:17:16 by edlucca           #+#    #+#             */
/*   Updated: 2025/06/23 18:42:02 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_stack	*find_node_b(t_stack **dst, t_stack **src)
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
		min = execute_b(dst, src, tmp, target);
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

void	b_to_a(t_stack **dst, t_stack **src)
{
	t_stack	*node;
	t_stack	*target;

	while(*src)
	{
		node = find_node_b(dst, src);
		target = find_target_a(dst, node);
		if (node->info.moves == node->info.rotate
				|| node->info.moves == target->info.rotate)
		{
			ft_printf("option 1\n");
			ra_rb_rr(dst, src, target, node);
		}
		else if (node->info.moves == node->info.reverse 
				|| node->info.moves == target->info.reverse)
			rra_rrb_rrr(dst, src, target, node);
		else
		{
			ft_printf("option 2\n");
			ra_rra(dst, target);
			rb_rrb(src, node);
		}
		push_a(src, dst);
	}
}
