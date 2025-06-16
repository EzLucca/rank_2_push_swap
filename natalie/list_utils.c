/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeintje <nmeintje@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:03:22 by nmeintje          #+#    #+#             */
/*   Updated: 2024/08/12 12:05:24 by nmeintje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*min_index(t_stack *stack)
{
	t_stack	*min;

	min = NULL;
	while (stack)
	{
		if (min == NULL || stack->index < min->index)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

t_stack	*max_index(t_stack *stack)
{
	t_stack	*max;

	max = NULL;
	while (stack)
	{
		if (max == NULL || stack->index > max->index)
			max = stack;
		stack = stack->next;
	}
	return (max);
}
