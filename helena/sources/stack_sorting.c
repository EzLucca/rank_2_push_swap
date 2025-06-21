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

void	sorting_big(t_stack **st_a, t_stack **st_b)
{
	int	i;

	i = 2;
	while (ft_stack_size(st_a) > 3 && i--)
		pb(st_a, st_b);
	if (ft_stack_size(st_a) > 3)
		pushing_from_a_to_b(st_a, st_b);
	if (!stack_sorting_check(st_a))
		sorting_three(st_a);
	pushing_from_b_to_a(st_a, st_b);
	if (!stack_sorting_check(st_a))
	{
		i = ft_stack_position(st_a, ft_stack_min(st_a));
		if (i <= ft_stack_size(st_a) / 2)
		{
			while ((*st_a)->nb != ft_stack_min(st_a))
				ra(st_a);
		}
		else
		{
			while ((*st_a)->nb != ft_stack_min(st_a))
				rra(st_a);
		}
	}
}

void	sorting_three(t_stack **st_a)
{
	if ((*st_a)->nb == ft_stack_max(st_a))
		ra(st_a);
	else if ((*st_a)->next->nb == ft_stack_max(st_a))
		rra(st_a);
	if ((*st_a)->nb > (*st_a)->next->nb)
		sa(st_a);
}

void	stack_sorting(t_stack **st_a, t_stack **st_b)
{	
	if (ft_stack_size(st_a) == 2)
		sa(st_a);
	else if (ft_stack_size(st_a) == 3)
		sorting_three(st_a);
	else
		sorting_big(st_a, st_b);
}
