/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 15:16:42 by hutzig            #+#    #+#             */
/*   Updated: 2025/06/17 14:49:07 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rr_ra_rb(t_stack **a, t_stack **b, t_stack *node_a, t_stack *node_b)
{
	while (*a != node_a && *b != node_b)
		rr(a, b);
	while (*a != node_a)
		ra(a);
	while (*b != node_b)
		rb(b);
}

void	rrr_rra_rrb(t_stack **a, t_stack **b, t_stack *node_a, t_stack *node_b)
{
	while (*a != node_a && *b != node_b)
		rrr(a, b);
	while (*a != node_a)
		rra(a);
	while (*b != node_b)
		rrb(b);
}

void	ra_or_rra(t_stack **a, t_stack *node)
{
	if (node->info.rotate < node->info.reverse)
	{
		while (*a != node)
			ra(a);
	}
	else
	{
		while (*a != node)
			rra(a);
	}
}

void	rb_or_rrb(t_stack **b, t_stack *node)
{
	if (node->info.rotate < node->info.reverse)
	{
		while (*b != node)
			rb(b);
	}
	else
	{
		while (*b != node)
			rrb(b);
	}
}
