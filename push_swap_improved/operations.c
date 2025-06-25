/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlucca <edlucca@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 09:47:41 by edlucca           #+#    #+#             */
/*   Updated: 2025/06/25 17:22:15 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

// review function lines to long and function to big
t_st	*find_target(t_st **src, t_st *node, t_move dir)
{
	t_st	*target;
	t_st	*tmp;
	t_st	*last;
	int		min;
	int		max;

	tmp = *src;
	target = NULL;
	min = stack_min(src);
	max = stack_max(src);
	last = stack_last(&tmp);
	if ((dir == A_TO_B && node->nbr > tmp->nbr && node->nbr < last->nbr)
			|| (dir == B_TO_A && node->nbr < tmp->nbr && node->nbr > last->nbr))
		return (tmp);
	if (node->nbr > max || node->nbr < min)
	{
		while (tmp->nbr != choose(dir == A_TO_B, max, min))
			tmp = tmp->next;
		target = tmp;
	}
	while (tmp->next)
	{
		if ((dir == A_TO_B && node->nbr < tmp->nbr && node->nbr > tmp->next->nbr)
				|| (dir == B_TO_A && node->nbr > tmp->nbr && node->nbr < tmp->next->nbr))
			target = tmp->next;
		tmp = tmp->next;
	}
	return (target);
}

int	min_moves(t_st **src, t_st **dst, t_st *node, t_st *target)
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

t_st	*find_node(t_st **src, t_st **dst, t_move dir)
{
	t_st	*node;
	t_st	*target;
	t_st	*tmp;
	int		min;
	int		moves;

	tmp = *src;
	node = NULL;
	moves = INT_MAX;
	while (tmp)
	{
		target = find_target(dst, tmp, dir);
		min = min_moves(src, dst, tmp, target);
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

void	stacks_op(t_st **src, t_st **dst, t_move dir)
{
	t_st	*node;
	t_st	*target;

	node = find_node(src, dst, dir);
	target = find_target(dst, node, dir);
	if (node->moves == node->rotate || node->moves == target->rotate)
	{
		if (dir == A_TO_B)
			ra_rb_rr(src, dst, node, target);
		else
			ra_rb_rr(dst, src, target, node);
	}
	else if (node->moves == node->reverse || node->moves == target->reverse)
	{
		if (dir == A_TO_B)
			rra_rrb_rrr(src, dst, node, target);
		else
			rra_rrb_rrr(dst, src, target, node);
	}
	else if (dir == A_TO_B)
	{
		ra_rra(src, node);
		rb_rrb(dst, target);
	}
	else if (dir == B_TO_A)
	{
		ra_rra(dst, target);
		rb_rrb(src, node);
	}
}

void	src_to_dst(t_st **src, t_st **dst, t_move dir)
{
	if (dir == A_TO_B)
	{
		while (stack_size(src) > 3 && !ascending_check(src))
		{
			stacks_op(src, dst, dir);
			push_b(src, dst);
		}
	}
	if (dir == B_TO_A)
	{
		while (*src)
		{
			stacks_op(src, dst, dir);
			push_a(src, dst);
		}
	}
}
