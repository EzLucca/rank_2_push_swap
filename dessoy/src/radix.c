/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:02:32 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/04/09 19:12:17 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	pb_or_ra(t_stack **stack, t_stack **stack_b, int i)
{
	if ((((*stack)->index >> i) & 1) == 0)
		pb(stack, stack_b);
	else
		ra(stack);
}

static void	rb_or_pa(t_stack **stack, t_stack **stack_b, int i)
{
	if ((((*stack_b)->index >> i) & 1) == 0 && stack_order(stack) == 0)
		rb(stack_b);
	else
		pa(stack_b, stack);
}

void	radix(t_stack **stack)
{
	t_stack	*stack_b;
	int		i;
	int		len;

	i = 0;
	stack_b = NULL;
	while (stack_order(stack) == 0 || stack_b != NULL)
	{
		len = gimme_length(*stack);
		while (len > 0 && stack_order(stack) == 0)
		{
			pb_or_ra(stack, &stack_b, i);
			len--;
		}
		i++;
		len = gimme_length(stack_b);
		while (len > 0)
		{
			rb_or_pa(stack, &stack_b, i);
			len--;
		}
	}
}
