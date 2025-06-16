/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeintje <nmeintje@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:21:01 by nmeintje          #+#    #+#             */
/*   Updated: 2024/08/12 16:08:25 by nmeintje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (ft_lstsize(*stack_a) <= 3)
		ft_sort_small(stack_a);
	else
	{
		ft_assign_index(stack_a);
		ft_sort_large(stack_a, &stack_b);
	}
}

void	ft_sort_small(t_stack **stack_a)
{
	if (ft_lstsize(*stack_a) == 2)
		ft_sa(stack_a);
	else if (ft_lstsize(*stack_a) == 3)
		ft_sort_three(stack_a);
}

void	ft_sort_three(t_stack **a)
{
	int	min;
	int	max;

	if (ft_check_sorted(*a))
		return ;
	min = min_value(*a);
	max = max_value(*a);
	if (min == (*a)->num)
	{
		ft_rra(a);
		ft_sa(a);
	}
	else if (max == (*a)->num)
	{
		ft_ra(a);
		if (!ft_check_sorted(*a))
			ft_sa(a);
	}
	else
	{
		if (ft_find_index(*a, max) == 1)
			ft_rra(a);
		else
			ft_sa(a);
	}
}

void	ft_sort_large(t_stack **a, t_stack **b)
{
	if (ft_lstsize(*a) > 3 && !ft_check_sorted(*a))
		ft_pb(a, b);
	if (ft_lstsize(*a) > 3 && !ft_check_sorted(*a))
		ft_pb(a, b);
	while (ft_lstsize(*a) > 3)
	{
		populate_stack_b(a, b);
		ft_pb(a, b);
	}
	if (ft_lstsize(*a) == 3)
		ft_sort_three(a);
	while (*b != NULL)
	{
		populate_stack_a(a, b);
	}
	minimum_to_top(a);
}
