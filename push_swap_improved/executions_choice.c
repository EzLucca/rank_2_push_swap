/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executions_choice.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlucca <edlucca@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:08:50 by edlucca           #+#    #+#             */
/*   Updated: 2025/06/25 10:20:49 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	ra_rb_rr(t_st **a, t_st **b, t_st *node, t_st *target)
{
	while (*a != node && *b != target)
		rotate_r(a, b);
	while (*a != node)
		rotate_a(a);
	while (*b != target)
		rotate_b(b);
}

void	rra_rrb_rrr(t_st **a, t_st **b, t_st *node, t_st *target)
{
	while (*a != node && *b != target)
		reverse_rotate_r(a, b);
	while (*a != node)
		reverse_rotate_a(a);
	while (*b != target)
		reverse_rotate_b(b);
}

void	ra_rra(t_st **a, t_st *node)
{
	if (node->rotate < node->reverse)
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

void	rb_rrb(t_st **b, t_st *node)
{
	if (node->rotate < node->reverse)
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

int	choose(int cond, int a, int b)
{
	if (cond)
		return (a);
	else
		return (b);
}
