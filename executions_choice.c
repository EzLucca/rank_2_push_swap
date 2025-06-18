/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executions_choice.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlucca <edlucca@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:08:50 by edlucca           #+#    #+#             */
/*   Updated: 2025/06/18 16:37:02 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_rra(t_stack **st_a, t_stack *node)
{
	if (node->info.rotate < node->info.reverse)
	{
		while (*st_a != node)
			rotate_a(st_a);
	}
	else
	{
		while (*st_a != node)
			reverse_rotate_a(st_a);
	}
}

void	rb_rrb(t_stack **st_b, t_stack *node)
{
	if (node->info.rotate < node->info.reverse)
	{
		while (*st_b != node)
			rotate_b(st_b);
	}
	else
	{
		while (*st_b != node)
			reverse_rotate_b(st_b);
	}
}

void	ra_rb_rr(t_stack **st_a, t_stack **st_b, t_stack *node, t_stack *target)
{
	while (*st_a != node && *st_b != target)
		rotate_r(st_a, st_b);
	while (*st_a != node)
		rotate_a(st_a);
	while (*st_b != target)
		rotate_b(st_b);
}

void	rra_rrb_rrr(t_stack **st_a, t_stack **st_b, t_stack *node, t_stack *target)
{
	while (*st_a != node && *st_b != target)
		reverse_rotate_r(st_a, st_b);
	while (*st_a != node)
		reverse_rotate_a(st_a);
	while (*st_b != target)
		reverse_rotate_b(st_b);
}

