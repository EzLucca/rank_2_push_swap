/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edlucca <edlucca@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:40:26 by edlucca           #+#    #+#             */
/*   Updated: 2025/06/24 18:13:24 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	sort_big(t_stack **st_a, t_stack **st_b)
{
	int	i;

	i = 2;
	while (stack_size(st_a) > 3 && i--)
		push_b(st_a, st_b);
	if (stack_size(st_a) > 3)
		a_to_b(st_a, st_b);
	if (!ascending_check(st_a))
		sort_three(st_a);
	b_to_a(st_a, st_b);
	if (!ascending_check(st_a))
	{
		i = stack_position(st_a, stack_min(st_a));
		if (i <= stack_size(st_a) / 2)
		{
			while ((*st_a)->nbr != stack_min(st_a))
				rotate_a(st_a);
		}
		else
		{
			while ((*st_a)->nbr != stack_min(st_a))
				reverse_rotate_a(st_a);
		}
	}
}

void	sort_three(t_stack **st_a)
{
	if ((*st_a)->nbr == stack_max(st_a))
		rotate_a(st_a);
	else if ((*st_a)->next->nbr == stack_max(st_a))
		reverse_rotate_a(st_a);
	if ((*st_a)->nbr > (*st_a)->next->nbr)
		swap_a(st_a);
}

void	sort_stack(t_stack **st_a, t_stack **st_b)
{
	if (stack_size(st_a) == 2)
		swap_a(st_a);
	else if (stack_size(st_a) == 3)
		sort_three(st_a);
	else
		sort_big(st_a, st_b);
}
