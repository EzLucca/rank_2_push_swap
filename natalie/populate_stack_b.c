/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_stack_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeintje <nmeintje@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:40:32 by nmeintje          #+#    #+#             */
/*   Updated: 2024/08/12 16:17:26 by nmeintje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rotates(t_stack **a, t_stack **b, t_steps *step_a, t_steps *step_b)
{
	while (step_a->rotate > 0 && step_b->rotate > 0)
	{
		step_a->rotate--;
		step_b->rotate--;
		ft_rr_a(a, b);
	}
	while (step_a->rotate > 0)
	{
		step_a->rotate--;
		ft_ra(a);
	}
	while (step_b->rotate > 0)
	{
		step_b->rotate--;
		ft_rb(b);
	}
}

void	rev_rotates(t_stack **a, t_stack **b, t_steps *step_a, t_steps *step_b)
{
	while (step_a->reverse > 0 && step_b->reverse > 0)
	{
		step_a->reverse--;
		step_b->reverse--;
		ft_rrr_a(a, b);
	}
	while (step_a->reverse > 0)
	{
		step_a->reverse--;
		ft_rra(a);
	}
	while (step_b->reverse > 0)
	{
		step_b->reverse--;
		ft_rrb(b);
	}
}

t_stack	*find_cheapest_move(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;
	int		min_cost;
	t_stack	*current_a;
	t_stack	*target_b;
	int		cost;

	cheapest_node = NULL;
	min_cost = INT_MAX;
	current_a = *a;
	while (current_a)
	{
		target_b = find_position_in_b(b, current_a->index);
		cost = ft_move_cost(a, b, current_a, target_b);
		if (cost < min_cost)
		{
			min_cost = cost;
			cheapest_node = current_a;
		}
		current_a = current_a->next;
	}
	return (cheapest_node);
}

void	rotate_stacks(t_stack **a, t_stack **b, t_stack *cur_a, t_stack *tar_b)
{
	t_steps	step_a;
	t_steps	step_b;

	calculate_steps_to_head(a, cur_a, &step_a);
	calculate_steps_to_head(b, tar_b, &step_b);
	do_rotates(a, b, &step_a, &step_b);
	rev_rotates(a, b, &step_a, &step_b);
}

void	populate_stack_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;
	t_stack	*target_b;

	cheapest_node = find_cheapest_move(a, b);
	target_b = find_position_in_b(b, cheapest_node->index);
	rotate_stacks(a, b, cheapest_node, target_b);
}
