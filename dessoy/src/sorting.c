/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 12:31:45 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/04/09 19:09:23 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_stack **stack)
{
	if ((*stack)->nb > (*stack)->next->nb && (*stack)->nb
		> (*stack)->next->next->nb)
	{
		if ((*stack)->next->nb < (*stack)->next->next->nb)
			ra(stack);
		else
		{
			ra(stack);
			sa(stack);
		}
	}
	else if ((*stack)->nb < (*stack)->next->nb && (*stack)->nb
		> (*stack)->next->next->nb)
		rra(stack);
	else if ((*stack)->nb > (*stack)->next->nb && (*stack)->nb
		< (*stack)->next->next->nb)
		sa(stack);
	else
	{
		sa(stack);
		ra(stack);
	}
}

void	sort_four_or_more(t_stack **stack, int i)
{
	t_stack	*stack_b;

	stack_b = NULL;
	while (gimme_length(*stack) > 3)
	{
		if ((*stack)->index <= i - 3)
			pb(stack, &stack_b);
		else
			ra(stack);
	}
	sort_three(stack);
	while (stack_b != NULL)
	{
		if (stack_b->index != i - 3)
			rb(&stack_b);
		else
		{
			pa(&stack_b, stack);
			i--;
		}
	}
}
