/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executions_choice.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlucca <edlucca@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:08:50 by edlucca           #+#    #+#             */
/*   Updated: 2025/06/18 21:16:14 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_rb_rr(t_stack **a, t_stack **b, t_stack *node, t_stack *target)
{
	while (*a != node && *b != target)
		rotate_r(a, b);
	while (*a != node)
		rotate_a(a);
	while (*b != target)
		rotate_b(b);
}

void	rra_rrb_rrr(t_stack **a, t_stack **b, t_stack *node, t_stack *target)
{
	while (*a != node && *b != target)
		reverse_rotate_r(a, b);
	while (*a != node)
		reverse_rotate_a(a);
	while (*b != target)
		reverse_rotate_b(b);
}

void	ra_rra(t_stack **a, t_stack *node)
{
	if (node->info.rotate < node->info.reverse)
	{
		while (*a != node)
			rotate_a(a);
	}
	else
	{
		while (*a != node)
			reverse_rotate_a(a);
	}
}

void	rb_rrb(t_stack **b, t_stack *node)
{
	if (node->info.rotate < node->info.reverse)
	{
		while (*b != node)
			rotate_b(b);
	}
	else
	{
		while (*b != node)
			reverse_rotate_b(b);
	}
}
