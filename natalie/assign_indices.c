/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_indices.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeintje <nmeintje@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:34:23 by nmeintje          #+#    #+#             */
/*   Updated: 2024/08/12 16:22:43 by nmeintje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_assign_index(t_stack **a)
{
	int		i;
	int		min;
	t_stack	*temp;
	t_stack	*current;

	i = 0;
	while (i <= ft_lstsize(*a))
	{
		temp = *a;
		min = INT_MAX;
		current = NULL;
		while (temp)
		{
			if (temp->num <= min && temp->index == -1)
			{
				min = temp->num;
				current = temp;
			}
			temp = temp->next;
		}
		if (current)
			current->index = i;
		i++;
	}
}

t_stack	*find_position_in_b(t_stack **b, int index)
{
	t_stack	*pos;
	t_stack	*best_pos;
	int		best_index;

	pos = *b;
	best_pos = NULL;
	best_index = INT_MIN;
	while (pos)
	{
		if (pos->index < index && pos->index > best_index)
		{
			best_index = pos->index;
			best_pos = pos;
		}
		pos = pos->next;
	}
	if (best_pos == NULL)
		best_pos = max_index(*b);
	return (best_pos);
}

t_stack	*mid_pos_in_stack_a(t_stack *stack, t_stack *node)
{
	t_stack	*current;

	current = stack;
	while (current->next != NULL)
	{
		if (current->num < node->num && current->next->num > node->num)
			return (current->next);
		current = current->next;
	}
	return (stack);
}

t_stack	*node_new_pos_a(t_stack **a, t_stack *node)
{
	t_stack	*min_node;
	t_stack	*max_node;

	if (!a || !*a || !node)
		return (*a);
	min_node = min_index(*a);
	max_node = max_index(*a);
	if (!min_node || !max_node)
		return (*a);
	if (min_node->num > node->num)
		return (min_node);
	if (max_node->num < node->num)
		return (min_node);
	return (mid_pos_in_stack_a(*a, node));
}
