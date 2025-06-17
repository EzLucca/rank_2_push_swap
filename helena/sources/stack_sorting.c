/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:53:48 by hutzig            #+#    #+#             */
/*   Updated: 2025/06/17 14:51:18 by edlucca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sorting_big(t_stack **a, t_stack **b)
{
	int	i;

	i = 2;
	while (ft_stack_size(a) > 3 && i--)
		pb(a, b);
	if (ft_stack_size(a) > 3)
		pushing_from_a_to_b(a, b);
	if (!stack_sorting_check(a))
		sorting_three(a);
	pushing_from_b_to_a(a, b);
	if (!stack_sorting_check(a))
	{
		i = ft_stack_position(a, ft_stack_min(a));
		if (i <= ft_stack_size(a) / 2)
		{
			while ((*a)->nb != ft_stack_min(a))
				ra(a);
		}
		else
		{
			while ((*a)->nb != ft_stack_min(a))
				rra(a);
		}
	}
}

void	sorting_three(t_stack **a)
{
	if ((*a)->nb == ft_stack_max(a))
		ra(a);
	else if ((*a)->next->nb == ft_stack_max(a))
		rra(a);
	if ((*a)->nb > (*a)->next->nb)
		sa(a);
}

void	stack_sorting(t_stack **a, t_stack **b)
{	
	if (ft_stack_size(a) == 2)
		sa(a);
	else if (ft_stack_size(a) == 3)
		sorting_three(a);
	else
		sorting_big(a, b);
}
