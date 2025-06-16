/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_stack_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeintje <nmeintje@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 10:41:27 by nmeintje          #+#    #+#             */
/*   Updated: 2024/08/14 10:41:50 by nmeintje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_a(t_stack **a, t_steps *steps_a)
{
	while (steps_a->rotate > 0)
	{
		ft_ra(a);
		steps_a->rotate--;
	}
}

static void	rev_rotate_a(t_stack **a, t_steps *steps_a)
{
	while (steps_a->reverse > 0)
	{
		ft_rra(a);
		steps_a->reverse--;
	}
}

static void	rotate_stack_a(t_stack **a, t_stack *current_a)
{
	t_steps	steps_a;

	calculate_steps_to_head(a, current_a, &steps_a);
	if (!*a || !current_a)
		return ;
	if (steps_a.rotate != 0)
		rotate_a(a, &steps_a);
	else
		rev_rotate_a(a, &steps_a);
}

void	populate_stack_a(t_stack **a, t_stack **b)
{
	t_stack	*max_node_b;
	t_stack	*new_pos_on_a;

	max_node_b = max_index(*b);
	if (*b == NULL)
		return ;
	while (*b != max_node_b)
	{
		if (dist_w_rot(max_node_b, b) > dist_w_rev(max_node_b, b))
			ft_rrb(b);
		else
			ft_rb(b);
	}
	while (*b)
	{
		new_pos_on_a = node_new_pos_a(a, *b);
		while (*a != new_pos_on_a)
		{
			if (dist_w_rot(new_pos_on_a, a) < dist_w_rev(new_pos_on_a, a))
				ft_ra(a);
			else
				ft_rra(a);
		}		
		ft_pa(a, b);
	}
}

void	minimum_to_top(t_stack **a)
{
	t_stack	*min_node;

	min_node = min_index(*a);
	rotate_stack_a(a, min_node);
}
