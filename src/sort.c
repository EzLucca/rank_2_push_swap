/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlucca <edlucca@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:40:26 by edlucca           #+#    #+#             */
/*   Updated: 2025/06/28 12:21:42 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_big(t_stack **a, t_stack **b)
{
	int	i;

	i = 2;
	while (stack_size (a) > 3 && i--)
		push_b(a, b);
	if (stack_size (a) > 3)
		a_to_b(a, b);
	if (!ascending_check (a))
		sort_three(a);
	b_to_a(a, b);
	if (!ascending_check (a))
	{
		i = stack_position(a, stack_min(a));
		if (i <= stack_size(a) / 2)
		{
			while ((*a)->nbr != stack_min(a))
				rotate_a(a);
		}
		else
		{
			while ((*a)->nbr != stack_min(a))
				reverse_rotate_a(a);
		}
	}
}

void	sort_three(t_stack **a)
{
	if ((*a)->nbr == stack_max(a))
		rotate_a(a);
	else if ((*a)->next->nbr == stack_max(a))
		reverse_rotate_a(a);
	if ((*a)->nbr > (*a)->next->nbr)
		swap_a(a);
}

void	sort_stack(t_stack **a, t_stack **b)
{
	if (stack_size(a) == 2)
		swap_a(a);
	else if (stack_size(a) == 3)
		sort_three(a);
	else
		sort_big(a, b);
}
